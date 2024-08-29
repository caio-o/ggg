#include "Fases/FaseTeste.hpp"
#include "Entidades/Personagens/Inimigos/Triangulo.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Entidades/Obstaculos/Lapis.hpp"
#define GRAVIDADE      1000.0F
#define LARGURA_FASE   2580.0F
#define ALTURA_FASE    1440.0F
#define CHAO           ALTURA_FASE
#define TETO              0.0F
#define CANTO_ESQUERDO    0.0F
#define CANTO_DIREITO     LARGURA_FASE

using namespace Fases;

void FaseTeste::criarObstaculos() 
{
    Obstaculos::Lapis *pLap;
    Obstaculos::Plataforma* pPlat;

    pPlat = new Obstaculos::Plataforma(LARGURA_FASE-400.F, 100.f);
    pPlat->setPos((CANTO_DIREITO + CANTO_ESQUERDO)/2.F - 200.F, CHAO-540.F);
    colecao.incluir(static_cast<Entidade*> (pPlat));
    pGC->inserirObstaculo(static_cast<Obstaculo*> (pPlat));

    pPlat = new Obstaculos::Plataforma(LARGURA_FASE-400.F, 100.f);
    pPlat->setPos((CANTO_DIREITO + CANTO_ESQUERDO)/2.F + 200.F, CHAO-1140.F);
    colecao.incluir(static_cast<Entidade*> (pPlat));
    pGC->inserirObstaculo(static_cast<Obstaculo*> (pPlat));

    pLap = new Lapis();
    pLap->setPos(700.f, pPlat->getY() - pLap->getTam().y/2);
    colecao.incluir(static_cast<Entidade*> (pLap));
    pGC->inserirObstaculo(static_cast<Obstaculo*> (pLap));
    
    pPlat = new Obstaculos::Plataforma();
    pPlat->setPos(700.f, CHAO-320.f);
    colecao.incluir(static_cast<Entidade*> (pPlat));
    pGC->inserirObstaculo(static_cast<Obstaculo*> (pPlat));

    
    pPlat = new Obstaculos::Plataforma(500.f,  100.F);
    pPlat->setPos(800.f, CHAO-100.f);
    colecao.incluir(static_cast<Entidade*> (pPlat));
    pGC->inserirObstaculo(static_cast<Obstaculo*> (pPlat));
    

    pPlat = new Obstaculos::Plataforma(500.f, 100.f);
    pPlat->setPos(700.f, CHAO-900.f);
    colecao.incluir(static_cast<Entidade*> (pPlat));
    pGC->inserirObstaculo(static_cast<Obstaculo*> (pPlat));

    pLap = new Lapis();
    pLap->setPos(600.f, pPlat->getY() - pLap->getTam().y/2);
    colecao.incluir(static_cast<Entidade*> (pLap));
    pGC->inserirObstaculo(static_cast<Obstaculo*> (pLap));

    pLap = new Lapis();
    pLap->setPos(650.f, pPlat->getY() - pLap->getTam().y/2);
    colecao.incluir(static_cast<Entidade*> (pLap));
    pGC->inserirObstaculo(static_cast<Obstaculo*> (pLap));


    //if(rand()%3)
    {
        pPlat = new Obstaculos::Plataforma(400.F);
        pPlat->setPos(CANTO_DIREITO - 250.F, CHAO - 300.f);
        colecao.incluir(static_cast<Entidade*> (pPlat));
        pGC->inserirObstaculo(static_cast<Obstaculo*> (pPlat));

        pPlat = new Obstaculos::Plataforma(400.F, 300.F);
        pPlat->setPos(CANTO_ESQUERDO + 250.F, CHAO - 740.f);
        colecao.incluir(static_cast<Entidade*> (pPlat));
        pGC->inserirObstaculo(static_cast<Obstaculo*> (pPlat));
    }

    if(rand()%3)
    {
        pPlat = new Obstaculos::Plataforma(500.F);
        pPlat->setPos(CANTO_DIREITO - 250.F, CHAO - 1000.f);
        colecao.incluir(static_cast<Entidade*> (pPlat));
        pGC->inserirObstaculo(static_cast<Obstaculo*> (pPlat));
    }

    if(rand()%3)
    {
        pPlat = new Obstaculos::Plataforma(400.F);
        pPlat->setPos(CANTO_DIREITO - 350.F, CHAO - 1600.f);
        colecao.incluir(static_cast<Entidade*> (pPlat));
        pGC->inserirObstaculo(static_cast<Obstaculo*> (pPlat));
    }

    colecao.irAoInicio();
}

void FaseTeste::criarInimigos()
{
    Inimigos::Triangulo* pTri;
    Inimigo::setpJogador1(pJog);
    Projetil::setpJogador1(pJog);

    Inimigo* pIni = static_cast<Inimigo*> (new Quadrado(Especie::inimigo, 10));
    pIni->setPos(CANTO_DIREITO-230.F, CHAO-150.F);
    pGC->inserirInimigo(pIni);
    colecao.incluir(static_cast<Entidade*> (pIni));

    pIni = static_cast<Inimigo*> (new Quadrado(Especie::inimigo, 10));
    pIni->setPos(CANTO_DIREITO-400.F, CHAO-150.F);
    pGC->inserirInimigo(pIni);
    colecao.incluir(static_cast<Entidade*> (pIni));

    pIni = static_cast<Inimigo*> (new Quadrado(Especie::inimigo, 10));
    pIni->setPos(CANTO_DIREITO-150.F, CHAO-150.F);
    pGC->inserirInimigo(pIni);
    colecao.incluir(static_cast<Entidade*> (pIni));

    pTri = new Triangulo;
    pTri->setpFase(this);
    pIni = static_cast<Inimigo*>(pTri);
    pIni->setPos(900.f, 900.f);
    pGC->inserirInimigo(pIni);
    colecao.incluir(static_cast<Entidade*>(pIni));

    pTri = new Triangulo;
    pIni = static_cast<Inimigo*>(pTri);
    pIni->setPos(1000.f, 600.F-100);
    pGC->inserirInimigo(pIni);
    colecao.incluir(static_cast<Entidade*>(pIni));

    pTri = new Triangulo;
    pIni = static_cast<Inimigo*>(pTri);
    pIni->setPos(400.f, CHAO-900.f);
    pGC->inserirInimigo(pIni);
    colecao.incluir(static_cast<Entidade*>(pIni));

    if(rand()%2)
    {
        Inimigo* pIni = static_cast<Inimigo*> (new Quadrado(Especie::inimigo, 1));
        pIni->setPos(700.F, CHAO+300);
        pGC->inserirInimigo(pIni);
        colecao.incluir(static_cast<Entidade*> (pIni));
    }
}

/** TODO: Talvez por isto na fase abstrata, e chamar
 *     Fase::Executar no fim do loop de cada fase. 
 *     Isto pouparia tempo.
 */ 
void FaseTeste::executar(const float dT)
{
    while (pGG->janelaAberta())
    {
        pGG->limpar();

        pGE->executar(); // Checar se a janela deve ser fechada.
        pGC->executar(); // Checar colisoes e gerar seus efeitos.

        t0 = t1;
        t1 = pGG->getTempo();
        deltaT = t1 - t0;

        // Executar, mover e desenhar entidades.
        colecao.percorrer(deltaT);

        if(pJog)
        {
            if(verificaGameOver())
            {
                pGG->renderizar(&efeitoGameOver);
            }
        }

        pGG->mostrar();
    }
}

FaseTeste::FaseTeste():
    Fase(),
    maxInimigos(100)
{
    pGG->setTamanhoCamera(Vetor2f(LARGURA_FASE, ALTURA_FASE));
    pGG->centralizarCamera();

    pJog = new Jogador(15.f, true);
    pJog2 = new Jogador(15.f, false);

    Inimigo::setpJogador1(pJog);
    Inimigo::setpJogador2(pJog2);
    
    pJog->setPos(190.f, CHAO-100.f);
    pJog2->setPos(190.f, CHAO-100.f);
    pGC->inserirJogador(pJog);
    pGC->inserirJogador(pJog2);
    colecao.incluir(static_cast<Entidade*>(pJog));
    colecao.incluir(static_cast<Entidade*>(pJog2));

    colecao.setGravidade(GRAVIDADE);
    
    {// CRIAR PAREDES, CHAO E TETO
    Obstaculos::Plataforma* pPlat = new Obstaculos::Plataforma(100.f, ALTURA_FASE);
    pPlat->setPos(CANTO_ESQUERDO, ALTURA_FASE/2.F);
    colecao.incluir(static_cast<Entidade*> (pPlat));
    pGC->inserirObstaculo(static_cast<Obstaculo*>(pPlat));

    pPlat = new Obstaculos::Plataforma(100.f, ALTURA_FASE);
    pPlat->setPos(CANTO_DIREITO, ALTURA_FASE/2.F);
    colecao.incluir(static_cast<Entidade*> (pPlat));
    pGC->inserirObstaculo(static_cast<Obstaculo*> (pPlat));

    pPlat = new Obstaculos::Plataforma(LARGURA_FASE, 100.f);
    pPlat->setPos((CANTO_DIREITO + CANTO_ESQUERDO)/2.F, CHAO);
    colecao.incluir(static_cast<Entidade*> (pPlat));
    pGC->inserirObstaculo(static_cast<Obstaculo*> (pPlat));

    pPlat = new Obstaculos::Plataforma(LARGURA_FASE, 100.f);
    pPlat->setPos((CANTO_DIREITO + CANTO_ESQUERDO)/2.F, TETO);
    colecao.incluir(static_cast<Entidade*> (pPlat));
    pGC->inserirObstaculo(static_cast<Obstaculo*> (pPlat));
    }

    criarObstaculos();
    criarInimigos();
    Projetil::setpJogador1(pJog);
    Projetil::setpJogador2(pJog2);
}

FaseTeste::~FaseTeste()
{ }