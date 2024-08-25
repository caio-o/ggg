#include "Entidades/Entidade.hpp"
#include <cstring>

using namespace Entidades;

Entidade::Entidade(Especie _especie):
    Ente          (/*_pForma*/),
    //tam(50.f,50.f),
    especie(_especie),
    pos           (10.0f, 10.0f),
    vel           (0.0f, 0.0f),
    modGravidade  (1.0f, 1.0f),
    forma(pos, Vetor2f(50.7f, 48.9f),  "../img/emoji_sorrindo.png", 1.f)
{ 
    /*cout << "Entidade::Entidade:" << endl;
    cout << "    pForma = " << pForma << endl; */

    //setTextura("../img/quadrado_vermelho.png" /*, Vetor2f(80.f, 80.f)*/);
}

Entidade::~Entidade() 
{ }

void Entidade::desenhar ()
{
    forma.atualizar(pos);

    forma.renderizar();

    //Ente::desenhar();
}

void Entidade::moverse(const float n_segundos)
{
    /*if (pos.y > (float) (Ente::pGG->getJanela()->getSize().y) - 10) 
    { 
        //vel.y += GRAVIDADE;
    }
    else if (vel.y > 0.0f)
    {
        vel.y = 0.0f;
    }*/
    
    pos += vel * n_segundos;
}

void Entidade::setTextura  (const char* caminho, const bool resetarTamanho)        
{ 
    forma.setTextura(caminho, resetarTamanho);
    /*forma.getpCorpo()->setSize(sf::Vector2f(tamanho.x, tamanho.y));*/
    //forma.getpCorpo()->setScale(1.f, 1.f);
} 

const Vetor2f Entidade::getTam() const
{
    if (forma.getpCorpo())
        return Vetor2f(forma.getpCorpo()->getSize().x, forma.getpCorpo()->getSize().y);
    else 
        return Vetor2f();
}