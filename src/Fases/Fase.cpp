#include "Fases/Fase.hpp"
#include "Entidades/Obstaculos/Plataforma.hpp"
#include "Entidades/Obstaculos/PlataformaGrudenta.hpp"
#include "Entidades/Personagens/Inimigos/Quadrado.hpp"
#include "Entidades/Personagens/Inimigos/Triangulo.hpp"
#include "Entidades/Projetil.hpp"
#include <iostream>
#include <fstream>

namespace Fases
{
    Fase::Fase():
    Estado(),
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
    saida(Vetor2f(CANTO_DIREITO-350.0F, TETO-50.0F), Vetor2f(400.f, 400.f), "../img/saida_luz.png", 1.f),
    efeitoGameOver(Vetor2f (1290, 720.f), Vetor2f(2580.f, 1440.f), "../img/game_over.png", 1.f)
    {
        t0 = pGG->getTempo();
        t1 = pGG->getTempo();
    }

    Fase::~Fase()
    {
        if(pGC)
            delete pGC;
    }

    void Fase::salvar() 
    {
        ofstream ofs("../dados/save.dat");

        if(pJog)
        {
            pJog->salvar(ofs);
        }
        if(pJog2)
        {
            pJog2->salvar(ofs);
        }

        // em breve a tarefa serah delegada para a LISTA ENTIDADES
    }

    void Fase::criarProjetil(const float x, const float y)
    {
        Entidades::Projetil* pProj = new Projetil();

        if(pProj)
        {
            pProj->setPos(x, y);

            pGC->inserirProjetil(pProj);

            colecao.incluir(static_cast<Entidade*>(pProj));
        }
        else
            cout << "Erro em Fases::Fase::criarProjetil(): " << ERRO_ALOCACAO << endl;
    }

    void Fase::criarPlataforma(float posX, float posY, float tamX, float tamY)
    {
        Plataforma *pPlat = new Obstaculos::Plataforma(tamX, tamY);

        if(pPlat)
        {
            pPlat->setPos(posX, posY);
            colecao.incluir(static_cast<Entidade*> (pPlat));
            pGC->inserirObstaculo(static_cast<Obstaculo*> (pPlat));
        }

        else cout << "Faseteste::criarPlataforma: " << ERRO_ALOCACAO << "\n" << ERRO_INCLUI_NULLPTR << endl;
    }

    void Fase::criarPlataformaGrudenta(float posX, float posY, float tamX, float tamY)
    {
        PlataformaGrudenta *pPlat = new PlataformaGrudenta(tamX, tamY);

        if(pPlat)
        {
            pPlat->setPos(posX, posY);
            colecao.incluir(static_cast<Entidade*> (pPlat));
            pGC->inserirObstaculo(static_cast<Obstaculo*> (pPlat));
        }

        else cout << "Faseteste::criarPlataforma: " << ERRO_ALOCACAO << "\n" << ERRO_INCLUI_NULLPTR << endl;
    }

    void Fase::criarBordas()
    {
            //                 POS_X                                    POS_Y           TAM_X           TAM_Y
        criarPlataforma (CANTO_ESQUERDO,                         ALTURA_FASE/2.F,   100.f,          ALTURA_FASE); // PAREDE ESQUERDA
        criarPlataforma (CANTO_DIREITO,                          ALTURA_FASE/2.F,   100.f,          ALTURA_FASE); // PAREDE DIREITA
        criarPlataforma ((CANTO_DIREITO + CANTO_ESQUERDO)/2.F,   CHAO,              LARGURA_FASE,   100.f);       // CHAO
        criarPlataforma ((CANTO_DIREITO + CANTO_ESQUERDO)/2.F,   TETO,              LARGURA_FASE,   100.f);       // TETO

    }

    void Fase::criarTriangulo(float posX, float posY)
    {
        Inimigo* pIni = static_cast<Inimigo*> (new Triangulo(Especie::inimigo));
        pIni->setPos(posX, posY);
        pGC->inserirInimigo(pIni);
        colecao.incluir(static_cast<Entidade*> (pIni));
    }

    void Fase::criarQuadrado(float posX, float posY)
    {
        Inimigo* pIni = static_cast<Inimigo*> (new Quadrado(Especie::inimigo, 10));
        pIni->setPos(posX, posY);
        pGC->inserirInimigo(pIni);
        colecao.incluir(static_cast<Entidade*> (pIni));
    }
        
    const bool Fase::verificaGameOver()
    {
        if       (pJog && pJog2)  { return gameOver = (bool) !( pJog->getVivo() || pJog2->getVivo() ); }
        else if  (pJog         )  { return gameOver = (bool) !( pJog->getVivo() );                     }
        else                      { return false;                                                      }
    }

    void Fase::verificaTeclaPressionada(string tecla)
    {
        /*if(pJog)
            pJog->verificaTeclaPressionada(tecla);
        
        if(pJog2)
            pJog2->verificaTeclaPressionada(tecla);*/
    }

    void Fase::verificaTeclaSolta(string tecla)
    {
        if(tecla == "Escape")
            { cout << "JOGO PAUSADO" << endl; pGEs->executarEstado(menuPause);}
        else
        {
            /*if(pJog)
                pJog->verificaTeclaSolta(tecla);
        
            if(pJog2)
                pJog2->verificaTeclaSolta(tecla);*/
        }
    }
} // namespace Fases
