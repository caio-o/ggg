#include "Ente.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"

Gerenciadores::GerenciadorGrafico*  Ente::pGG        = NULL;
int                                 Ente::contEntes  = 0;

Ente::Ente(/*Forma* _pForma*/):
    id      (++contEntes)
    //pForma  (_pForma)
{ }

Ente::~Ente()
{ /*delete pForma; */}

void Ente::desenhar()
{
    //pForma->renderizar();
}
