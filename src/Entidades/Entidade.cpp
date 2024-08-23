#include "Entidades/Entidade.hpp"

using namespace Entidades;

Entidade::Entidade(Forma* _pForma):
    Ente          (_pForma),
    pos           (10.0f, 10.0f),
    vel           (0.0f, 0.0f),
    modGravidade  (1.0f, 1.0f)
{ 
    cout << "Entidade::Entidade:" << endl;
    cout << "    pForma = " << pForma << endl; 
}

Entidade::~Entidade() 
{ }

void Entidade::desenhar ()
{
    //cout << "Entidade::desenhar:" << endl;
    pForma->atualizar(pos);
    Ente::desenhar();
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