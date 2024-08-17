#ifndef _JOGADOR_HPP
#define _JOGADOR_HPP

#include "Entidades/Personagens/Personagem.hpp"
#include "Entidades/Ente.hpp"
using namespace Entidades;

namespace Entidades
{
    class Jogador : public Personagem   
    {
    public:
        Jogador(Figura* _pFigura = new sf::CircleShape(50), int _maxVida = 10):
            Personagem(ID_Classe::jogador, _pFigura, _maxVida)
        {  }

        ~Jogador()
        {  }

        void pular()
        {
            if(getY() >= Gerenciadores::Grafico::getGrafico()->getJanela()->getSize().y + 50.0f)
            {
                setVelY( getVel().y + 20.0f );
            }
        }

        void executar()
        {
            pular();
        }
    };
}

#endif