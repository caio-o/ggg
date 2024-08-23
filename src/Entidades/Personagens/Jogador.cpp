#include "Entidades/Personagens/Jogador.hpp"
#include <SFML/System.hpp>
using sf::Keyboard;

Jogador::Jogador(Forma* _pForma, int _maxVida):
    Personagem (_pForma, _maxVida),
    agilidade  (200.0f)
{  }

Jogador::~Jogador()
{  }

void Jogador::pular() 
{
    
}

void Jogador::executar() 
{ 
    if       (Keyboard::isKeyPressed (Keyboard::Up)   )    { setVelY(-agilidade); }
    else if  (Keyboard::isKeyPressed (Keyboard::Down) )    { setVelY(+agilidade); }
    else                                                   { setVelY(      0.0f); }

    if       (Keyboard::isKeyPressed (Keyboard::Right))    { setVelX( agilidade); }
    else if  (Keyboard::isKeyPressed (Keyboard::Left) )    { setVelX(-agilidade); }
    else                                                   { setVelX(      0.0f); }
}