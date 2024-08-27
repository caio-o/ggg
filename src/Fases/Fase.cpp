#include "Fases/Fase.hpp"
using namespace Fases;

Fase::Fase():
    Ente(),
    t0(0.0f),
    t1(0.0f),
    deltaT(0.0f),
    colecao(),
    pJog(NULL),
    pGC (Gerenciadores::GerenciadorColisoes::getInstancia()),
    pGG (Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico()),
    pGE (Gerenciadores::GerenciadorEventos::getGerenciadorEventos())
{
    cout << "Fase::FASE" << endl;
    t0 = pGG->getTempo();
    t1 = pGG->getTempo();
}

Fase::~Fase()
{
    delete pGC;
}

void Fase::salvar() 
{ }