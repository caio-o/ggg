/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe responsável por definir o comportamento e características do 
 *             projétil lançado pelo inimigo do tipo Triângulo.
 */

#include "Projetil.hpp"
#include "Erros.hpp"

#include "stdlib.h"
#include "time.h"

#define CAMINHO_TEXTURA "../img/projetil_triangulo.png"

#define VELOCIDADE_PERSEGUICAO 500.0

namespace Entidades
{
    Jogador* Projetil::pJogador1(NULL);
    Jogador* Projetil::pJogador2(NULL);

    Projetil::Projetil(Especie _especie, const int dano, const bool pers):
    Entidade(_especie),
    dano(dano),
    perseguindo(pers)
    {
        forma.setTextura(CAMINHO_TEXTURA, true);
        setTamanho(10.0, 10.0);
        setVel(500.0, 500.0);
    }

    Projetil::~Projetil()
    {
        pos = Coordenadas::Vetor2f(-1.0,-1.0);
        vel = Coordenadas::Vetor2f(0.0,0.0);
        acelVertical = 0.0;
        especie = indefinido;
    }

    //Reage a colisão dando dano se a entidade colidente for um jogador. Para todos os casos, o projétil
    //é desativado após colisão.
    void Projetil::reagirAhColisao(Entidade* pE)
    {
        //Ao colidir...
        if(pE)
        {
            //...checa se a colisao foi com um jogado...
            if(pE->getEspecie() == jogador)
            {
                //...em caso afirmativo, dá dano no jogador
                Jogador* pJ = static_cast<Jogador*>(pE);
                pJ->receberDano(dano);
            }

            //Por fim, é desativado, independente do tipo de Entidade com a qual colidiu.
            ativo = false;
        }
        else
            cout << "Erro em Entidades::Projetil::reagirAhColisao(pE): " << ERRO_NULLPTR << endl;
    }

    //Persegue alternadamente os jogadores (se houver jogador 2)
    void Projetil::executar(const float dT)
    {
        srand(time(NULL));
        
        //Persegue alternadamente os jogadores (se houver jogador 2)
        if(pJogador2 && rand()%2)
        {
    
            if(pJogador2->getPos().x < pos.x)
                vel.x = -VELOCIDADE_PERSEGUICAO;
            else
                vel.x = VELOCIDADE_PERSEGUICAO;

            if(pJogador2->getPos().y < pos.y)
                vel.y = -VELOCIDADE_PERSEGUICAO;
            else
                vel.y = VELOCIDADE_PERSEGUICAO;
        }
        else
        {
            if(pJogador1->getPos().x < pos.x)
                vel.x = -VELOCIDADE_PERSEGUICAO;
            else
                vel.x = VELOCIDADE_PERSEGUICAO;

            if(pJogador1->getPos().y < pos.y)
                vel.y = -VELOCIDADE_PERSEGUICAO;
            else
                vel.y = VELOCIDADE_PERSEGUICAO;
        }

        perseguindo = true;
    }

    void Projetil::setDano(const int d)
    {
        dano = d;
    }
    
    const int Projetil::getDano() const
    {
        return dano;
    }

    void Projetil::setPerseguindo(const bool p)
    {
        perseguindo = p;
    }

    const bool Projetil::getPerseguindo() const
    {
        return perseguindo;
    }

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
} // namespace Entidades
