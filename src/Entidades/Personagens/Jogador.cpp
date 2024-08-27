#include "Entidades/Personagens/Jogador.hpp"
#include <SFML/System.hpp>
using sf::Keyboard;
using namespace ElementosGraficos;
#define DANO_PISADA 5

Jogador::Jogador(int _maxVida):
    Personagem (Especie::jogador, _maxVida),
    agilidade  (300.0f),
    noChao(false),
    velPulo(-700.f)
{ 
    setTextura("../img/circulo_azul.png", true);
    setTamanho(30.f, 30.f);
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

//RETIREI O MOVER() DO PROJETO MAS NÃO SEI SE PODIA APAGAR ESSA ESTRUTURA, ENTÃO DEIXEI COMENTADO
/*void Jogador::mover()
{ 
    if       (Keyboard::isKeyPressed (Keyboard::Up)   )    { setVelY(-agilidade); }
    else if  (Keyboard::isKeyPressed (Keyboard::Down) )    { setVelY(+agilidade); }
    else                                                   { setVelY(      0.0f); }

    if       (Keyboard::isKeyPressed (Keyboard::Right))    { setVelX( agilidade); }
    else if  (Keyboard::isKeyPressed (Keyboard::Left) )    { setVelX(-agilidade); }
    else                                                   { setVelX(      0.0f); }
}*/

void Jogador::executar(const float dT) 
{ 
    if       (Keyboard::isKeyPressed (Keyboard::Up   ))    { pular();             }
    
    if       (Keyboard::isKeyPressed (Keyboard::Right))    { setVelX( agilidade); }
    else if  (Keyboard::isKeyPressed (Keyboard::Left) )    { setVelX(-agilidade); }
    else                                                   { setVelX(      0.0f); }
    
    noChao = false;

    
    checarVida();
}

void Jogador::reagirAhColisao(Entidade* pE)
{
    switch(pE->getEspecie())
    {
    case Especie::plataforma:
        noChao = true;
        break;

    case Especie::inimigo:
        if(pE->getY() - pE->getTam().y/2.F > getY())
        {
            static_cast<Personagem*>(pE)->receberDano(DANO_PISADA);
            aceleraY(-200.f);
        }
        break;
        
    default:
        break;
    }
}