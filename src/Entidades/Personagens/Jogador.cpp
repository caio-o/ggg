#include "Entidades/Personagens/Jogador.hpp"
#include <SFML/System.hpp>
using sf::Keyboard;
using namespace ElementosGraficos;

Jogador::Jogador(int _maxVida):
    Personagem (_maxVida),
    agilidade  (200.0f)
{ 
    setForma( Forma (pos, Vetor2f(30.0f, 30.0f), "../img/emoji_sorrindo.png", 1.0F) );
}

Jogador::~Jogador()
{  }

void Jogador::pular() 
{
    
}

void Jogador::salvar()
{ }

void Jogador::atacar()
{ }

void Jogador::mover()
{ 
    /*if       (Keyboard::isKeyPressed (Keyboard::Up)   )    { setVelY(-agilidade); }
    else if  (Keyboard::isKeyPressed (Keyboard::Down) )    { setVelY(+agilidade); }
    else                                                   { setVelY(      0.0f); }

    if       (Keyboard::isKeyPressed (Keyboard::Right))    { setVelX( agilidade); }
    else if  (Keyboard::isKeyPressed (Keyboard::Left) )    { setVelX(-agilidade); }
    else                                                   { setVelX(      0.0f); }*/
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