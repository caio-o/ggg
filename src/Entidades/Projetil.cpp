/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * ALTERAÇÕES: Caio e Silva Barbieri
 * DESCRIÇÃO : Implementação da classe responsável por definir o comportamento e características do 
 *             projétil lançado pelo inimigo do tipo Triângulo.
 */

#include "Projetil.hpp"
#include "Erros.hpp"

#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iostream>

#define CAMINHO_TEXTURA "../img/projetil_triangulo.png"

#define VELOCIDADE_PERSEGUICAO 500.0

namespace Entidades
{
    Jogador* Projetil::pJogador1(NULL);
    Jogador* Projetil::pJogador2(NULL);

    Projetil::Projetil(const int _dano):
    Entidade(Especie::projetil),
    dano(_dano),
    perseguindoJogador1(true)
    {
        forma.setTextura(CAMINHO_TEXTURA, true);
        setTamanho(35.0, 35.0);
        setVel(500.0, 500.0);

        if(pJogador2 && rand()%2)
            perseguindoJogador1 = false;

    }

    Projetil::~Projetil()
    {
        pos = Coordenadas::Vetor2f(-1.0,-1.0);
        vel = Coordenadas::Vetor2f(0.0,0.0);
        acelVertical = 0.0;
        especie = indefinido;
    }

    //Reage a colisão dando dano se a entidade colidente for um jogador. Para todos os casos, o projétil
    //é "desativado" após colisão.
    void Projetil::reagirAhColisao(Entidade* pE)
    {
        //Ao colidir...
        if(pE)
        {
            //...checa se a colisao foi com um jogador...
            if(pE->getEspecie() == jogador)
            {
                //...em caso afirmativo, dá dano no jogador
                Jogador* pJ = static_cast<Jogador*>(pE);
                pJ->receberDano(dano, true);
            }

            //Por fim, é desativado, independente do tipo de Entidade com a qual colidiu.
            ativo = false;
            setVel(0.f,0.f);
        }
        else
            cout << "Erro em Entidades::Projetil::reagirAhColisao(pE): " << ERRO_NULLPTR << endl;
    }

    //Persegue alternadamente os jogadores (se houver jogador 2)
    void Projetil::executar(const float dT)
    {
        //Rotaciona o projetil em torno do proprio eixo
        getForma()->getpCorpo()->rotate(720.f*dT);

        //Persegue o jogador 2
        if(!perseguindoJogador1)
        {
    
            //Define a velocidade do projetil no eixo x
            if(pJogador2->getPos().x < pos.x)
                vel.x = -VELOCIDADE_PERSEGUICAO;
            else
                vel.x = VELOCIDADE_PERSEGUICAO;

            //Define a velocidade do projetil no eixo y
            if(pJogador2->getPos().y < pos.y)
                vel.y = -VELOCIDADE_PERSEGUICAO;
            else
                vel.y = VELOCIDADE_PERSEGUICAO;
        }
        //Persegue o jogador 1
        else
        {
            //Define a velocidade do projetil no eixo x
            if(pJogador1->getPos().x < pos.x)
                vel.x = -VELOCIDADE_PERSEGUICAO;
            else
                vel.x = VELOCIDADE_PERSEGUICAO;

            //Define a velocidade do projetil no eixo y
            if(pJogador1->getPos().y < pos.y)
                vel.y = -VELOCIDADE_PERSEGUICAO;
            else
                vel.y = VELOCIDADE_PERSEGUICAO;
        }
        /*else 
        {
            cout << "PROJETIL DIZ: JOGADOR NULO!" << endl;
        }

        perseguindo = true;*/
    }

    void Projetil::setDano(const int d)
    {
        dano = d;
    }
    
    const int Projetil::getDano() const
    {
        return dano;
    }

    /*const bool Projetil::getPerseguindoJogador1() const
    {
        return perseguindoJogador1;
    }*/

    void Projetil::setpJogador1(Jogador* pJ)
    {
        pJogador1 = pJ;

        if(pJogador1 == NULL)
            cout << "ATENÇÃO EM: Entidades::Projetil::setpJogador1(): " << ERRO_NULLPTR << endl;
    }

    void Projetil::setpJogador2(Jogador* pJ)
    {
        pJogador2 = pJ;

        if(pJogador2 == NULL)
            cout << "ATENÇÃO EM: Entidades::Projetil::setpJogador2(): " << ERRO_NULLPTR << endl;
    }

    void Projetil::salvar(std::ofstream &os) 
    {
        nlohmann::ordered_json j;
        j ["especie"]       = getEspecie();
        j ["pos"]           = { {"x", getX()    }, {"y", getY()    } };
        j ["tam"]           = { {"x", getTam().x}, {"y", getTam().y} };
        j ["dano"]          = dano;

        os << j << "\n";
    }
    
    void Projetil::carregar(nlohmann::ordered_json &j)
    {
        setPos     (j["pos"]["x"], j["pos"]["y"]);
        setTamanho (j["tam"]["x"], j["tam"]["y"]);
        dano      = j["dano"];
    }
} // namespace Entidades
