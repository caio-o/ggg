#include "Fases/Fase.hpp"
using namespace Fases;

Fase::Fase():
    Ente(),
    t0(0.0f),
    t1(0.0f),
    deltaT(0.0f),
    colecao(),
    pJog(NULL),
    pJog2(NULL),
    pGC (Gerenciadores::GerenciadorColisoes::getInstancia()),
    pGG (Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico()),
    pGE (Gerenciadores::GerenciadorEventos::getGerenciadorEventos()),
    gameOver(false),
    efeitoGameOver(Vetor2f (754.f, 360.f), Vetor2f(1290.f, 720.f), "../img/game_over.png", 1.f)
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