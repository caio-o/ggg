#include "Entidades/Ente.hpp"

Ente::Ente(const ID_Classe _id, Figura* const _pFigura):
    //idObj   (++contEntes),
    id      (_id),
    pFigura (_pFigura)
{ }

Ente::~Ente()
{ delete pFigura; }

void Ente::desenhar()
{
    pGG->renderizar(pFigura);
}
