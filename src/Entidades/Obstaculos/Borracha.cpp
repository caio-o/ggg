/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe responsável por definir o comportamento do obstáculo tipo Borracha
 *             que dá dano ao contato com o jogador.
 */

#include "Borracha.hpp"
#include "Erros.hpp"

#define CAMINHO_TEXTURA "./img/losango_verde.png" //textura provisória

namespace Entidades
{
    namespace Obstaculos
    {
        Jogador* Borracha::pJogador1(NULL);
        Jogador* Borracha::pJogador2(NULL);

        Borracha::Borracha(Especie _especie, const bool _permeavel, int dano):
        Obstaculo(_especie, _permeavel),
        dano(dano)
        {
            forma.setTextura(CAMINHO_TEXTURA, true);
            vel.x = 0.0;
        }

        Borracha::~Borracha()
        {
            especie = indefinido;
            dano = -1;
        }

        
        //Executa o obstáculo do tipo borracha
        void Borracha::executar(const float dT)
        {
            vel.x = 0.0; //ta sempre garantindo q não se move, não sei se isso faz sentido
        }

        //Reage ao contato aplicando dano ao jogador e fazendo com que ele pule
        void Borracha::reagirAhColisao(Entidade* pE)
        {
            // if(pE->getEspecie() == jogador)
            // {
            //     pE->danificar(dano);
            //     pE->setVelY(-20.0); //para o jogador pular ao receber dano
            // }
        }


        //Seta o dano do obstáculo borracha
        void Borracha::setDano(const int d)
        {
            dano = d;
        }

        //Retorna o dano do obstáculo borracha
        const int Borracha::getDano() const
        {
            return dano;
        }


        void Borracha::setpJogador1(Jogador* pJ)
        {
            pJogador1 = pJ;

            if(pJogador1 == NULL)
                cout << "Erro em Entidades::Obstaculos::Borracha::setpJogador1(): " << ERRO_NULLPTR << endl;
        }

        void Borracha::setpJogador2(Jogador* pJ)
        {
            pJogador2 = pJ;

            if(pJogador2 == NULL)
                cout << "Erro em Entidades::Obstaculos::Borracha::setpJogador1(): " << ERRO_NULLPTR << endl;
        }

    } // namespace Obstaculos
    
} // namespace Entidades
