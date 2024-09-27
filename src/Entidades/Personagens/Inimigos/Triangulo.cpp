/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * ALTERAÇÕES: Caio e Silva Barbieri
 * DESCRIÇÃO : Implementação da classe responsável por definir o comportamento e características do 
 *             inimigo Triângulo, que lança projéteis contra os jogadores.
 */

#include "Triangulo.hpp"
#include <iostream>
#include <fstream>

#define CAMINHO_TEXTURA "./../img/triangulo_amarelo.png"

#define COOLDOWN 3.0 //segundos

namespace Inimigos
{
    Fases::Fase* Triangulo::pFase(NULL);
    
    Triangulo::Triangulo(int maxVida, int dano):
    Inimigo(inimigo, maxVida)
    {
        setMaldade(20.f);
        forma.setTextura(CAMINHO_TEXTURA, true);
        setTamanho(65.f, 65.f);
    }

    Triangulo::~Triangulo()
    {
        cooldown = -1.0;
    }

    

    //Executa o comportamento do triângulo (não se movimenta, apenas lança projéteis conforme seu
    //cooldown)
    void Triangulo::executar(const float dT)
    {
        vel.x = 0.0;

        tempoUltimoAtaque += dT;

        if(tempoUltimoAtaque > cooldown)
        {
            atacar();

            tempoUltimoAtaque = 0.0;
        }
    }

    //Pede para a fase instanciar um novo projétil com origem em sua própria posição.
    void Triangulo::atacar()
    {
        pFase->criarProjetil(pos.x, pos.y);
    }

    //Não há.
    void Triangulo::reagirAhColisao(Entidade* pE)
    {
    }

    void Triangulo::salvar(std::ofstream &os) 
    {
        nlohmann::ordered_json j;
        j ["especie"]       = triangulo;
        j ["pos"]           = { {"x", getX()    }, {"y", getY()    } };
        j ["tam"]           = { {"x", getTam().x}, {"y", getTam().y} };
        j ["vida"]          = vida;
        j ["nivelMaldade"]  = nivelMaldade;

        os << j << "\n";
    }

    void Triangulo::carregar(nlohmann::ordered_json &j)
    {
        setPos       (j["pos"]["x"], j["pos"]["y"]);
        setTamanho   (j["tam"]["x"], j["tam"]["y"]);
        setVida      (j["vida"]);
        setMaldade   (j["nivelMaldade"]);

        checarVida();
    }
} // namespace Inimigos
