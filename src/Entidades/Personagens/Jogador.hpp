#ifndef _JOGADOR_HPP
#define _JOGADOR_HPP

#include "Entidades/Personagens/Personagem.hpp"
#include "Entidades/Ente.hpp"
#include <SFML/Graphics.hpp>
using namespace Entidades;

namespace Entidades
{
    class Jogador : public Personagem   
    {
    private:
        float agilidade;

    public:
        Jogador(Forma* _pForma, int _maxVida = 10);

        ~Jogador();

        void pular();

        void executar();
    };
}

#endif