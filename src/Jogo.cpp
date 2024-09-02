
#include "Jogo.hpp"
#include "Ente.hpp"
#include "Fases/Fase.hpp"
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

Jogador* Jogo::pJog1 = NULL;
Jogador* Jogo::pJog2 = NULL;

Jogo::Jogo():
    pGG(NULL),
    pGE(NULL),
    pGEs(NULL),
    primeiraFase(NULL)
{
    Fase::setDeveCarregar(false);
    getJogador1();
    getJogador2();

    srand(time(NULL));

    cout << "Jogo::Jogo 1" << endl;
    pGG = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
    pGE = Gerenciadores::GerenciadorEventos::getGerenciadorEventos();

    Fases::Fase::setGerenciadorColisoes();

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
    delete pGG;
    delete pGE;
    delete pGEs;
}

void Jogo::executar()
{
    // cout << "Jogo::Executar()" << endl;
    // pGEs->executarEstado(fase1);
    
    ////cout << "Jogo::EXECUTAR" << endl;
    //primeiraFase->executar();
    //segundaFase->executar();

    pGEs->executarEstado(menuPrincipal);
}

void Jogo::carregarJogador1(nlohmann::ordered_json j) 
{
    if(pJog1)
    {
        pJog1->carregar(j);
    }
    else
    {
        cout << "Em Jogo::carregarJogador1: " << ERRO_SET_NULLPTR << endl;
        enterFechar();
        exit(1);
    }
}

void Jogo::carregarJogador2(nlohmann::ordered_json j) 
{
    if(pJog2)
    {
        pJog2->carregar(j);
    }
    else
    {
        cout << "Em Jogo::carregarJogador2: " << ERRO_SET_NULLPTR << endl;
        enterFechar();
        exit(1);
    }
}

Jogador *Jogo::getJogador1()
{
    if(pJog1)
    {
        return pJog1;
    }
    else
    {
        pJog1 = new Jogador(60, true);
        return pJog1;
    }
}

Jogador *Jogo::getJogador2()
{
    if(pJog2)
    {
        return pJog2;
    }
    else
    {
        pJog2 = new Jogador(60, false);
        return pJog2;
    }
}

void Jogo::setJogador1(Jogador *jog)
{
    pJog1 = jog;
}

void Jogo::setJogador2(Jogador *jog)
{
    pJog2 = jog;
}
