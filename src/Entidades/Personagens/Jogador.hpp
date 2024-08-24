#ifndef _JOGADOR_HPP
#define _JOGADOR_HPP

#include "Personagem.hpp"
#include "Ente.hpp"
#include <SFML/Graphics.hpp>
using namespace Entidades;

namespace Entidades
{
    class Jogador : public Personagem   
    {
    private:
        //static Jogador *jogador1, *jogador2; 
        bool ehJogador1;
        bool noChao;
        float agilidade;
        float velPulo;

    public:
        Jogador(int _maxVida = 10);

        ~Jogador();

        void pular();
        const bool getChao() const { return (bool)(getY() > 500.f); }

        void salvar();
        void atacar();
        void mover();

        void executar();
    };
}

#endif