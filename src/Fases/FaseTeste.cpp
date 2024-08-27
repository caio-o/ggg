#include "Fases/FaseTeste.hpp"
#include "Entidades/Personagens/Inimigos/Triangulo.hpp"


using namespace Fases;
#define GRAVIDADE 1000.0F

void FaseTeste::criarObstaculos() 
{
    pJog = new Jogador;
    Inimigo::setpJogador1(pJog);
    pJog->setPos(300.f, 200.f);
    pGC->inserirJogador(pJog);
    colecao.incluir(static_cast<Entidade*>(pJog));

    Obstaculos::Plataforma* pPlat = new Obstaculos::Plataforma(100.f, pGG->getTamanhoJanela().y);
    pPlat->setPos(25.f, 360.f);
    colecao.incluir(static_cast<Entidade*> (pPlat));
    pGC->inserirObstaculo(static_cast<Obstaculo*>(pPlat));

    pPlat = new Obstaculos::Plataforma(100.f, pGG->getTamanhoJanela().y);
    pPlat->setPos(1265.f, 360.f);
    colecao.incluir(static_cast<Entidade*> (pPlat));
    pGC->inserirObstaculo(static_cast<Obstaculo*> (pPlat));

    pPlat = new Obstaculos::Plataforma(pGG->getTamanhoJanela().x, 100.f);
    pPlat->setPos(645.f, 700.f);
    colecao.incluir(static_cast<Entidade*> (pPlat));
    pGC->inserirObstaculo(static_cast<Obstaculo*> (pPlat));

    pPlat = new Obstaculos::Plataforma();
    pPlat->setPos(500.f, 400.f);
    colecao.incluir(static_cast<Entidade*> (pPlat));
    pGC->inserirObstaculo(static_cast<Obstaculo*> (pPlat));
    
    colecao.irAoInicio();
}

void FaseTeste::criarInimigos()
{
    Inimigos::Triangulo* pTri;
    Inimigo* pIni = static_cast<Inimigo*> (new Quadrado(Especie::inimigo, 10));
    Inimigo::setpJogador1(pJog);
    Projetil::setpJogador1(pJog);

    pIni->setPos(800.f, 300.f);
    pGC->inserirInimigo(pIni);
    colecao.incluir(static_cast<Entidade*> (pIni));
    /*pIni = static_cast<Inimigo*> (new Quadrado(Especie::inimigo, 10, 100));
    pIni->setPos(700.f, 300.f);
    pGC->inserirInimigo(pIni);
    colecao.incluir(static_cast<Entidade*> (pIni));*/

    pTri = new Triangulo;
    pTri->setpFase(this);
    pIni = static_cast<Inimigo*>(pTri);
    
    pIni->setPos(500., 425.);
    pGC->inserirInimigo(pIni);
    colecao.incluir(static_cast<Entidade*>(pIni));
}

/** TODO: Talvez por isto na fase abstrata, e chamar
 *     Fase::Executar no fim do loop de cada fase. 
 *     Isto pouparia tempo.
 */ 
void FaseTeste::executar(const float dT = 0.f)
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

        if(pJog->getY() < -50.f || pJog->getY() > 770.f) pJog->setPos(500.f, 500.f);
        if(pJog->getX() < -50.f || pJog->getY() > 1340.f) pJog->setPos(500.f, 500.f);

        if(pJog && pJog2)
        {
            
        }
        else if(pJog)
        {
            if(verificaGameOver())
            {
                efeitoGameOver.setTamanho(pGG->getTamanhoJanela().x, pGG->getTamanhoJanela().y);
                efeitoGameOver.atualizar(pGG->getTamanhoJanela()/2.f);
                efeitoGameOver.renderizar();
            }
        }

        pGG->mostrar();
    }
}

FaseTeste::FaseTeste():
    Fase(),
    maxInimigos(100)
{
    colecao.setGravidade(GRAVIDADE);
    criarObstaculos();
    criarInimigos();
}

FaseTeste::~FaseTeste()
{ }