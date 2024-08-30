/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe responsável por definir o comportamento e características do 
 *             inimigo Triângulo, que lança projéteis contra os jogadores.
 */

#include "Triangulo.hpp"

#define CAMINHO_TEXTURA "./../img/triangulo_amarelo.png"

#define COOLDOWN 3.0 //segundos

namespace Inimigos
{
    Fases::Fase* Triangulo::pFase(NULL);
    
    Triangulo::Triangulo(Especie _especie, int maxVida, int dano):
    Inimigo(_especie, maxVida)
    {
        setMaldade(20.f);
        forma.setTextura(CAMINHO_TEXTURA, true);
        setTamanho(65.f, 65.f);
    }

    Triangulo::~Triangulo()
    {
        cooldown = -1.0;
    }

    void Triangulo::salvar()
    {

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

    //Pede para a fase instanciar um novo projétil com origem e sua própria posição.
    void Triangulo::atacar()
    {
        pFase->criarProjetil(pos.x, pos.y);
    }

    //Não há reação.
    void Triangulo::reagirAhColisao(Entidade* pE)
    {
        //não faz nada?
    }

} // namespace Inimigos
