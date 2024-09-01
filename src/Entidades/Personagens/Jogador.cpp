#include "Entidades/Personagens/Jogador.hpp"
#include "Entidades/Personagens/Inimigos/Inimigo.hpp"
#include <SFML/System.hpp>
#include "json.hpp"
#include <iostream>
#include <fstream>
using sf::Keyboard;
using namespace ElementosGraficos;
#define DANO_PISADA 5

//using json = nlohmann::json;

Jogador::Jogador(const int _maxVida, const bool j1):
    Personagem (Especie::jogador, _maxVida),
    ehJogador1 (j1),
    noChao     (false),
    pontos     (000000),
    agilidade  (300.0f),
    lentidao   (1.0f),
    velPulo    (-700.f)
{ 
    if(ehJogador1)
    {
        setTextura("../img/emoji_com_faca.png", true);
    }
    else
    {
        setTextura("../img/emoji_sorrindo.png", true);
    }
    setTamanho(45.f, 45.f);
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

void Jogador::salvar(ofstream &os)
{
    nlohmann::ordered_json j;
    j ["especie"]    = getEspecie();
    j ["pos"]        = { {"x", getX()    }, {"y", getY()    } };
    j ["tam"]        = { {"x", getTam().x}, {"y", getTam().y} };
    j ["vida"]       = getVida();
    j ["ehJogador1"] = ehJogador1;

    // o output eh o que se espera no arquivo final
    os << j << "\n";
    cout << j << "\n";
    cout << "salvamento concluido!" << endl;
}

void Jogador::carregar(nlohmann::ordered_json &j)
{
    ehJogador1 = j["ehJogador1"];

    if(ehJogador1) setTextura("../img/emoji_com_faca.png", true);
    else           setTextura("../img/emoji_sorrindo.png", true);

    setPos       (j["pos"]["x"], j["pos"]["y"]);
    setTamanho   (j["tam"]["x"], j["tam"]["y"]);
    setVida      (j["vida"]);

    checarVida();
}

void Jogador::atacar()
{ }

void Jogador::executar(const float dT) 
{ 
    // Faz que o jogador seja controlado pelo teclado.
    controlarse(); 

    lentidao = 1.0f;
    noChao = false;
    
    checarVida();
}

void Jogador::reagirAhColisao(Entidade* pE)
{
    static Inimigos::Inimigo* pIni = NULL;

    switch(pE->getEspecie())
    {
    case Especie::plataforma:
        if(getY() < pE->getY() + pE->getTam().y/2) // se o jogador nao estah colidindo DE BAIXO
            noChao = true;
        break;

    case Especie::inimigo:
        pIni = static_cast<Inimigos::Inimigo*> (pE);

        if(pE->getY() - pE->getTam().y/2.F > getY())
        {
            if(pIni->getVivo())
            {
                danificar(static_cast<Personagem*>(pIni));
                (*this) += DANO_PISADA*3;

                // se este ataque derrotou o inimigo, receber ainda mais pontos.
                if(! pIni->getVivo())                                  
                    // quanto mais malvado, mais pontos vale. maldade negativa retira os pontos do jogador (por sua crueldade).
                    (*this) += pIni->getMaxVida() * pIni->getMaldade(); 
            }
            aceleraY(-200.f);
        }
        break;
        
    default:
        break;
    }
}

void Jogador::controlarse()
{
    if(vivo)
    {
        if(ehJogador1)
        {
            if       (Keyboard::isKeyPressed (Keyboard::Up   ))    { pular();             }

            if       (Keyboard::isKeyPressed (Keyboard::Right))    { setVelX( agilidade / lentidao); }
            else if  (Keyboard::isKeyPressed (Keyboard::Left) )    { setVelX(-agilidade / lentidao); }
            else                                                   { setVelX(      0.0f); }
        }

        else
        {
            if       (Keyboard::isKeyPressed (Keyboard::W   ))    { pular();             }

            if       (Keyboard::isKeyPressed (Keyboard::D   ))    { setVelX( agilidade / lentidao); }
            else if  (Keyboard::isKeyPressed (Keyboard::A   ))    { setVelX(-agilidade / lentidao); }
            else                                                  { setVelX(      0.0f); }
        }
    }
}

void Jogador::danificar(Personagem*pPers)
{
    pPers->receberDano(DANO_PISADA);
}
