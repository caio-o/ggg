#include "Entidades/Personagens/Jogador.hpp"
#include "Entidades/Personagens/Inimigos/Inimigo.hpp"
#include <SFML/System.hpp>
using sf::Keyboard;
using namespace ElementosGraficos;
#define DANO_PISADA 5

Jogador::Jogador(const int _maxVida, const bool j1):
    Personagem (Especie::jogador, _maxVida),
    ehJogador1 (j1),
    noChao     (false),
    pontos     (000000),
    agilidade  (300.0f),
    lentidao   (000.0f),
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
        
    noChao = false;

    
    checarVida();
}

void Jogador::reagirAhColisao(Entidade* pE)
{
    static Inimigos::Inimigo* pIni = NULL;

    switch(pE->getEspecie())
    {
    case Especie::plataforma:
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

                if(! pIni->getVivo()) // se este ataque derrotou o inimigo, receber ainda mais pontos.
                    (*this) += pIni->getMaxVida() * pIni->getMaldade(); // quanto mais malvado, mais pontos vale. maldade negativa retira os pontos do jogador (por sua crueldade).
            }
            else
            {
                
            }
            aceleraY(-200.f);
        }
        break;
        
    default:
        break;
    }
}

void Jogador::danificar(Personagem*pPers)
{
    pPers->receberDano(DANO_PISADA);
}

void Jogador::verificaTeclaSolta(string tecla)
{
    if(vivo)
    {
        if(ehJogador1)
        {
            if (tecla == "Direita" || tecla == "Esquerda") {setVelX(0.0f); lentidao = 1.0f;}
        }
        else
        {
            if (tecla == "D" || tecla == "A")              {setVelX(0.0f); lentidao = 1.0f;}
        }
    }
}

void Jogador::verificaTeclaPressionada(string tecla)
{
    if(vivo)
    {
        if(ehJogador1)
        {
            if       (tecla == "Cima")       { pular();             }

            if       (tecla == "Direita")    { setVelX( agilidade / lentidao); }
            else if  (tecla == "Esquerda" )  { setVelX(-agilidade / lentidao); }
        }

        else
        {
            if       (tecla == "W")    { pular();             }

            if       (tecla == "D")    { setVelX( agilidade / lentidao); }
            else if  (tecla == "A")    { setVelX(-agilidade / lentidao); }
        }

        lentidao = 1.0f;
    }
}
