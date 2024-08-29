#include "Ente.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Gerenciadores/GerenciadorEventos.hpp"

Gerenciadores::GerenciadorGrafico*  Ente::pGG        = NULL;
Gerenciadores::GerenciadorEventos*  Ente::pGE        = NULL;
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
    //pGG->renderizar(&forma);
}
