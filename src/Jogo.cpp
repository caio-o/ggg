
#include "Jogo.hpp"
#include "Ente.hpp"
#include "Fases/Fase.hpp"
#include "Fases/Tuneis.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
using namespace Fases;

Jogo::Jogo():
    pGG(NULL),
    pGE(NULL),
    primeiraFase(NULL)
{
    srand(time(NULL));
    /*Jogador *jog1 = new Jogador;
    Jogador *jog2 = NULL;*/

    //cout << "Jogo::Jogo 1" << endl;
    pGG = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
    pGE = Gerenciadores::GerenciadorEventos::getGerenciadorEventos();
    
    Ente::setGerenciadorGrafico();

    //primeiraFase =  static_cast<Fase*> (new Fases::Calabouco);
    segundaFase = static_cast<Fase*> (new Fases::Tuneis);
    //cout << "Jogo::Jogo 2" << endl;
}

Jogo::~Jogo()
{
    delete primeiraFase;
    delete pGG;
    delete pGE;
}

void Jogo::executar()
{
    ////cout << "Jogo::EXECUTAR" << endl;
    //primeiraFase->executar();
    segundaFase->executar();
}