#include "Entidades/Personagens/Jogador.hpp"
#include <SFML/System.hpp>
using sf::Keyboard;
using namespace ElementosGraficos;
#define DANO_PISADA 5

Jogador::Jogador(const int _maxVida, const bool j1):
    Personagem (Especie::jogador, _maxVida),
    ehJogador1(j1),
    agilidade  (300.0f),
    noChao(false),
    velPulo(-700.f)
{ 
    if(ehJogador1)
    {
        setTextura("../img/emoji_com_faca.png", true);
    }
    else
    {
        setTextura("../img/emoji_sorrindo.png", true);
    }
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
    if(vivo)
    {
        if(ehJogador1)
        {
            if       (Keyboard::isKeyPressed (Keyboard::Up   ))    { pular();             }

            if       (Keyboard::isKeyPressed (Keyboard::Right))    { setVelX( agilidade); }
            else if  (Keyboard::isKeyPressed (Keyboard::Left) )    { setVelX(-agilidade); }
            else                                                   { setVelX(      0.0f); }
        }

        else
        {
            if       (Keyboard::isKeyPressed (Keyboard::W   ))    { pular();             }

            if       (Keyboard::isKeyPressed (Keyboard::D   ))    { setVelX( agilidade); }
            else if  (Keyboard::isKeyPressed (Keyboard::A   ))    { setVelX(-agilidade); }
            else                                                  { setVelX(      0.0f); }
        }
    }
    
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