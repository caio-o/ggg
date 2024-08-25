#include "Entidades/Personagens/Jogador.hpp"
#include <SFML/System.hpp>
using sf::Keyboard;
using namespace ElementosGraficos;

Jogador::Jogador(int _maxVida):
    Personagem (Especie::jogador, _maxVida),
    agilidade  (200.0f),
    noChao(false),
    velPulo(-700.f)
{ 
    setTextura("../img/circulo_azul.png", true);
    //setTamanho(30.f, 30.f);
    //getForma()->setEscala(0.5f);
}

Jogador::~Jogador()
{  }

void Jogador::pular() 
{
    if(noChao) 
    {
        vel.y = velPulo;
    }
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
    /*if       (Keyboard::isKeyPressed (Keyboard::Up)   )    { setVelY(-agilidade); }
    else if  (Keyboard::isKeyPressed (Keyboard::Down) )    { setVelY(+agilidade); }
    else                                                   { setVelY(      0.0f); }*/

    if       (Keyboard::isKeyPressed (Keyboard::Right))    { setVelX( agilidade); }
    else if  (Keyboard::isKeyPressed (Keyboard::Left) )    { setVelX(-agilidade); }
    else                                                   { setVelX(      0.0f); }
}

void Jogador::reagirAhColisao(Entidade* pE)
{
    switch(pE->getEspecie())
    {
    case Especie::plataforma:
        noChao = true;
        break;
        
    default:
        break;
    }
}