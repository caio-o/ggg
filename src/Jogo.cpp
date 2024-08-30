
#include "Jogo.hpp"
#include "Ente.hpp"
#include "Fases/Fase.hpp"
#include "Fases/Tuneis.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Gerenciadores/GerenciadorEstados.hpp"

using namespace std;
using namespace Fases;

Jogo::Jogo():
    pGG(NULL),
    pGE(NULL),
    pGEs(NULL),
    primeiraFase(NULL)
{
    srand(time(NULL));
    /*Jogador *jog1 = new Jogador;
    Jogador *jog2 = NULL;*/

    cout << "Jogo::Jogo 1" << endl;
    pGG = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
    pGE = Gerenciadores::GerenciadorEventos::getGerenciadorEventos();
    pGEs = Gerenciadores::GerenciadorEstados::getGerenciadorEstados();
    
    Ente::setGerenciadorGrafico();
    Ente::setGerenciadorEventos();

    primeiraFase =  static_cast<Fase*> (new Fases::Calabouco);
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
    /*cout << "Jogo::Executar()" << endl;
    pGEs->executarEstado(menuPrincipal);*/
    
    ////cout << "Jogo::EXECUTAR" << endl;
    primeiraFase->executar();
}