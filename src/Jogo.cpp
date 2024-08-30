
#include "Jogo.hpp"
#include "Ente.hpp"
#include "Fases/Fase.hpp"
#include "Fases/Tuneis.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Gerenciadores/GerenciadorEstados.hpp"
#include "Gerenciadores/GerenciadorEventos.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"

#include "ElementosGraficos/Forma.hpp"
#include "ElementosGraficos/Texto.hpp"

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

    Gerenciadores::GerenciadorEventos::setGerenciadorGrafico();

    Ente::setGerenciadorGrafico();
    Ente::setGerenciadorEventos();

    ElementosGraficos::Forma::setGerenciadorGrafico();
    ElementosGraficos::Texto::setGerenciadorGrafico();

    /*
     * A construtora do gerenciador de estados aloca todos os estados possiveis (i.e., todas as fases
     * e menus). As construtoras dos menus, por sua vez, alocam título e opções, que são do tipo 
     * texto. Para alocar esses objetos, a classe Texto precisa ter o gerenciador gráfico (que é 
     * estático) já configurado. Por isso, a construtora deve inicializar primeiro os gerenciadores
     * grafico e de eventos e setá-los nas classes pertinentes para, só então, inicializar o
     * gerenciador de estados (SE NÃO FOR NESSA SEQUÊNCIA, DÁ SEGFAULT).
     */
    pGEs = Gerenciadores::GerenciadorEstados::getGerenciadorEstados();
    
    Estado::setGerenciadorEstados();
    Gerenciadores::GerenciadorEventos::setGerenciadorEstados();
    

    //primeiraFase =  static_cast<Fase*> (new Fases::Calabouco);
    //segundaFase = static_cast<Fase*> (new Fases::Tuneis);
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
    cout << "Jogo::Executar()" << endl;
    pGEs->executarEstado(faseTeste);
    
    ////cout << "Jogo::EXECUTAR" << endl;
    //primeiraFase->executar();
    //segundaFase->executar();
}