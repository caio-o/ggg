#ifndef _TUNEIS_HPP
#define _TUNEIS_HPP

#include "Fases/Fase.hpp"

namespace Fases
{
    class Tuneis : public Fase
    {
    private:
        void criarLapis              (float posX, float posY, int dano = 1);
        void criarObstaculos();
        void criarInimigos();

    public:
        Tuneis(/* args */);
        ~Tuneis();
    };
}

#endif