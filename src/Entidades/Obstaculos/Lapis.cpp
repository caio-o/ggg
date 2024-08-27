/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe responsável por definir o comportamento do obstáculo tipo Lapis
 *             que dá dano ao contato com o jogador.
 */

#include "Lapis.hpp"
#include "Erros.hpp"

#define CAMINHO_TEXTURA "../img/lapis.png" //textura provisória

namespace Entidades
{
    namespace Obstaculos
    {
        Jogador* Lapis::pJogador1(NULL);
        Jogador* Lapis::pJogador2(NULL);

        Lapis::Lapis(Especie _especie, const bool _permeavel, const int dano):
        Obstaculo(_especie, _permeavel),
        dano(dano)
        {
            forma.setTextura(CAMINHO_TEXTURA, true);
            vel.x = 0.0;
            setTamanho(80.f, 80.f);
        }

        Lapis::~Lapis()
        {
            especie = indefinido;
            dano = -1;
        }

        
        //Executa o obstáculo do tipo Lapis
        void Lapis::executar(const float dT)
        {
            vel.x = 0.0; //ta sempre garantindo q não se move, não sei se isso faz sentido
        }

        //Reage ao contato aplicando dano ao jogador e fazendo com que ele pule
        void Lapis::reagirAhColisao(Entidade* pE)
        {
            if(pE->getEspecie() == jogador)
            {
                Jogador* pJ = static_cast<Jogador*>(pE);
                pJ->receberDano(dano, true);
                //pJ->aceleraY(-200.0); //para o jogador pular ao receber dano
            }
        }


        //Seta o dano do obstáculo Lapis
        void Lapis::setDano(const int d)
        {
            dano = d;
        }

        //Retorna o dano do obstáculo Lapis
        const int Lapis::getDano() const
        {
            return dano;
        }


        void Lapis::setpJogador1(Jogador* pJ)
        {
            pJogador1 = pJ;

            if(pJogador1 == NULL)
                cout << "Erro em Entidades::Obstaculos::Lapis::setpJogador1(): " << ERRO_NULLPTR << endl;
        }

        void Lapis::setpJogador2(Jogador* pJ)
        {
            pJogador2 = pJ;

            if(pJogador2 == NULL)
                cout << "Erro em Entidades::Obstaculos::Lapis::setpJogador1(): " << ERRO_NULLPTR << endl;
        }

    } // namespace Obstaculos
    
} // namespace Entidades
