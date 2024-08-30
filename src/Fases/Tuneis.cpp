#include "Fases/Tuneis.hpp"
#include "Entidades/Obstaculos/Lapis.hpp"
#include "Tuneis.hpp"
#include "Entidades/Personagens/Inimigos/Estrela.hpp"
#include "Entidades/Personagens/Inimigos/Triangulo.hpp"
#define X_SAIDA CANTO_DIREITO-550.0F
#define Y_SAIDA TETO+200.0F

void Fases::Tuneis::criarLapis(float posX, float posY, int dano)
{
    Obstaculos::Lapis *pLap = new Obstaculos::Lapis();
    
    if(pLap)
    {
        pLap->setPos(posX, posY);
        colecao.incluir(static_cast<Entidade*> (pLap));
        pGC->inserirObstaculo(static_cast<Obstaculo*> (pLap));
    }
}

void Fases::Tuneis::criarChefaoEstrela(const float posX, const float posY, const int nCapangas)
{
    Estrela* pChefao = new Estrela();
    pChefao->setNumCapangas(nCapangas);
    pChefao->setPos(posX, posY);
    colecao.incluir(static_cast<Entidade*>(pChefao));
    pGC->inserirInimigo(static_cast<Inimigo*> (pChefao));
}

void Fases::Tuneis::criarObstaculos()
{
    criarPlataforma ((CANTO_DIREITO + CANTO_ESQUERDO)/2.F - 200.F, CHAO-540.F, LARGURA_FASE-400.F, 100.f);  // SEGUNDO  PISO
    criarPlataforma ((CANTO_DIREITO + CANTO_ESQUERDO)/2.F + 200.F, CHAO-1140.F, LARGURA_FASE-400.F, 100.f); // TERCEIRO PISO
    criarPlataforma (CANTO_DIREITO - 250.F, CHAO - 300.f, 400.f, 100.f);
    criarPlataforma (CANTO_ESQUERDO + 250.F, CHAO - 740.f, 400.F, 300.F);
    criarPlataforma (700.f, CHAO-900.f, 500.f,  100.F);
    
    criarPlataformaGrudenta (800.f, CHAO-20.F, 500.F,  50.F);
    criarPlataformaGrudenta (850.F, CHAO-550.F, 90.F,  50.F);
    criarPlataformaGrudenta (900.F, CHAO-550.F, 80.F,  50.F);

    criarLapis(800.f, CHAO);
    criarLapis(650.f, CHAO-50.F);
    criarLapis(500.f, CHAO-30.F);
    
    if((bool) rand()%3) 
        criarPlataforma(CANTO_DIREITO - 250.F, CHAO - 1000.f, 500.F, 300.F);

    if((bool) rand()%3) 
        criarPlataforma(CANTO_DIREITO - 350.F, CHAO - 1600.f, 400.F, 300.F);
}

void Fases::Tuneis::criarInimigos()
{
    Inimigo:: setpJogador1(pJog);
    Inimigo:: setpJogador2(pJog2);
    Projetil::setpJogador1(pJog);
    Projetil::setpJogador2(pJog2);
    Inimigos::Triangulo::setpFase(static_cast<Fase*>(this));
    Estrela::setFase(this);

    criarQuadrado(CANTO_ESQUERDO+800.F, CHAO-150.F);
    if(rand()%2) criarTriangulo(CANTO_ESQUERDO+900.F, CHAO-150.F);
    
    criarChefaoEstrela(CANTO_DIREITO-400, CHAO-150.F, maxInimigos/maxChefao);
    criarChefaoEstrela(CANTO_ESQUERDO+400, CHAO-665.F, maxInimigos/maxChefao);
    criarChefaoEstrela(CANTO_DIREITO-400, CHAO-1315.F, maxInimigos/maxChefao);
}

Fases::Tuneis::Tuneis():
    Fase(),
    maxInimigos(9),
    maxChefao(3)
    //saida(Vetor2f(X_SAIDA+200.F, Y_SAIDA-250.F), Vetor2f(400.f, 300.f), "", 1.f)
{
    Ente::setGerenciadorGrafico();
    saida.getpCorpo()->setFillColor(sf::Color::Yellow);
    pGG->setTamanhoCamera(Vetor2f(LARGURA_FASE, ALTURA_FASE));
    pGG->centralizarCamera();

    pJog = new Jogador(15.f, true);
    pJog2 = new Jogador(15.f, false);
    
    pJog->setPos(190.f, CHAO-100.f);
    pJog2->setPos(190.f, CHAO-100.f);
    pGC->inserirJogador(pJog);
    pGC->inserirJogador(pJog2);
    colecao.incluir(static_cast<Entidade*>(pJog));
    colecao.incluir(static_cast<Entidade*>(pJog2));

    colecao.setGravidade(GRAVIDADE);
    
    criarBordas();
    criarObstaculos();
    criarInimigos();

    colecao.irAoInicio();
}

Fases::Tuneis::~Tuneis()
{
    if(pGC)
        delete pGC;
}

void Fases::Tuneis::executar(const float dT)
{
    while (pGG->janelaAberta())
    {
        pGG->limpar();
        pGC->executar(); // Checar colisoes e gerar seus efeitos.
        pGE->executar(); // Checar se a janela deve ser fechada.

        t0 = t1;
        t1 = pGG->getTempo();
        deltaT = t1 - t0;

        // Executar, mover e desenhar entidades.
        colecao.percorrer(deltaT);

        pGG->renderizar(&saida);

        if(pJog)
        {
            if(verificaVitoria())
            {
                cout << "GANHARAM!" << endl;
            }
            else if(verificaGameOver())
            {
                pGG->renderizar(&efeitoGameOver);
            }
        }

        pGG->mostrar();
    }
}

const bool Fases::Tuneis::verificaVitoria()
{
    static Vetor2f limiteSaida(X_SAIDA, Y_SAIDA);

    if(pJog && pJog->getVivo())
    {
        if(pJog2 && pJog2->getVivo())
        {
            return pJog->getX() > X_SAIDA && pJog->getY() < Y_SAIDA &&  pJog2->getX() > X_SAIDA && pJog2->getY() < Y_SAIDA;
        }
        else
        {
            return pJog->getX() > X_SAIDA && pJog->getY() < Y_SAIDA;
        }
    }
    else if(pJog2 && pJog2->getVivo())
    {
        return pJog2->getX() > X_SAIDA && pJog2->getY() < Y_SAIDA;
    }
    else
    {
        return false;
    }
}
