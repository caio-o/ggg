#include "Entidades/Ente.hpp"
#include "Gerenciadores/Grafico.hpp"

Gerenciadores::Grafico*  Ente::pGG        = NULL;
int                      Ente::contEntes  = 0;

Ente::Ente(Figura* const _pFigura):
    //idObj   (++contEntes),
    id      (++contEntes),
    pFigura (_pFigura)
{ }

Ente::~Ente()
{ delete pFigura; }

void Ente::desenhar()
{
    pGG->renderizar(pFigura);
}
