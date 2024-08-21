#include "Entidades/Entidade.hpp"

using namespace Entidades;

Entidade::Entidade(Figura* const _pFigura):
    Ente          (pFigura),
    pos           (0.0f, 0.0f),
    vel           (0.0f, 0.0f),
    modGravidade  (1.0f, 1.0f)
{ }

Entidade::~Entidade() 
{ }

void Entidade::moverse(const float deltaT)
{
    if (pos.y > (float) (Ente::pGG->getJanela()->getSize().y) - 10) 
    { 
        vel.y += GRAVIDADE;
    }
    else if (vel.y > 0.0f)
    {
        vel.y = 0.0f;
    }
    
    pos += vel * deltaT;
}