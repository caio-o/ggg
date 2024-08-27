
#include "Jogo.hpp"
#include "Fases/Fase.hpp"
#include <iostream>
using namespace std;
using namespace Fases;

Jogo::Jogo():
    pGG(NULL),
    pGE(NULL),
    primeiraFase(NULL)
{
    
    cout << "Jogo::Jogo 1" << endl;
    pGG = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
    pGE = Gerenciadores::GerenciadorEventos::getGerenciadorEventos();
    primeiraFase =  static_cast<Fase*> (new FaseTeste);
    cout << "Jogo::Jogo 2" << endl;
}

Jogo::~Jogo()
{
    delete primeiraFase;
    delete pGG;
    delete pGE;
}

void Jogo::executar()
{
    cout << "Jogo::EXECUTAR" << endl;
    primeiraFase->executar();
}