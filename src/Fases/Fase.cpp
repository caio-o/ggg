#include "Fases/Fase.hpp"
#include "Entidades/Projetil.hpp"

namespace Fases
{
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
    efeitoGameOver(Vetor2f (1290, 720.f), Vetor2f(2580.f, 1440.f), "../img/game_over.png", 1.f)
    {
        cout << "Fase::FASE" << endl;
        t0 = pGG->getTempo();
        t1 = pGG->getTempo();
    }

    Fase::~Fase()
    {
        if(pGC)
            delete pGC;
    }

    void Fase::salvar() 
    { }

    void Fase::criarProjetil(float x, float y)
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
} // namespace Fases
