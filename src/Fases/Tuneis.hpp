#ifndef _TUNEIS_HPP
#define _TUNEIS_HPP

#include "Fases/Fase.hpp"
#include "Estado.hpp"

namespace Fases
{
    class Tuneis : public Fase
    {
    private:
        //Forma saida;
        int maxInimigos;
        int  maxChefao;
        Lapis*   criarLapis              (float posX, float posY, int dano = 1);
        Estrela* criarChefaoEstrela      (const float posX, const float posY, const int nCapangas);
        void criarObstaculos();
        void criarInimigos();

    public:
        Tuneis(/* args */);
        ~Tuneis();
        void carregar();
        void executar(const float dT);
        const bool verificaVitoria();

        //void desenhar(){}

    };
}

#endif