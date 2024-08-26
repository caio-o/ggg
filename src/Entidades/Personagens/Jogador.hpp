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
        float agilidade; // velocidade do CAMINHAR do jogador (no eixo X)
        float velPulo;   // velocidade inicial do PULO do jogador (no eixo Y)
        virtual void morrer()  { forma.setEscala(1.f, 2.0f); setY(getY()+100.f); }; //efeito da morte no jogador

    public:
        Jogador(int _maxVida = 10);

        ~Jogador();

        void pular();
        const bool getChao() const { return noChao; }

        void salvar();
        void atacar();
        void executar(const float dT);
        void reagirAhColisao(Entidade* pE);
    };
}

#endif