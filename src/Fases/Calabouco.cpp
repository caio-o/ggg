#include "Entidades/Personagens/Inimigos/Triangulo.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Entidades/Obstaculos/Lapis.hpp"
#include "Entidades/Obstaculos/PlataformaGrudenta.hpp"
#include "Fases/Calabouco.hpp"

#define GRAVIDADE      1000.0F
/*#define LARGURA_FASE   2580.0F
#define ALTURA_FASE    1440.0F
#define CHAO           ALTURA_FASE
#define TETO              0.0F
#define CANTO_ESQUERDO    0.0F
#define CANTO_DIREITO     LARGURA_FASE*/

using namespace Fases;

void Fases::Calabouco::criarObstaculos() 
{
    criarPlataforma ((CANTO_DIREITO + CANTO_ESQUERDO)/2.F - 200.F, CHAO-540.F, LARGURA_FASE-400.F, 100.f);  // SEGUNDO  PISO
    criarPlataforma ((CANTO_DIREITO + CANTO_ESQUERDO)/2.F + 200.F, CHAO-1140.F, LARGURA_FASE-400.F, 100.f); // TERCEIRO PISO
    criarPlataforma (CANTO_DIREITO - 250.F, CHAO - 300.f, 400.f, 100.f);
    criarPlataforma (CANTO_ESQUERDO + 250.F, CHAO - 740.f, 400.F, 300.F);
    criarPlataforma (800.f, CHAO-100.f, 500.f,  100.F);
    criarPlataforma (700.f, CHAO-900.f, 500.f,  100.F);
    
    if((bool) rand()%3) 
        criarPlataforma(CANTO_DIREITO - 250.F, CHAO - 1000.f, 500.F, 300.F);

    if((bool) rand()%3) 
        criarPlataforma(CANTO_DIREITO - 350.F, CHAO - 1600.f, 400.F, 300.F);
}

void Fases::Calabouco::criarInimigos()
{
    Inimigos::Triangulo::setpFase(this);
    Inimigo:: setpJogador1(pJog);
    Inimigo:: setpJogador2(pJog2);
    Projetil::setpJogador1(pJog);
    Projetil::setpJogador2(pJog2);

    criarQuadrado(CANTO_DIREITO-230.F, CHAO-150.F);
    criarQuadrado(CANTO_DIREITO-400.F, CHAO-150.F);
    criarQuadrado(CANTO_DIREITO-150.F, CHAO-150.F);
    criarTriangulo(900.f, 900.f);
    criarTriangulo(1000.f, 600.F-100);
    criarTriangulo(400.f, CHAO-900.f);

    if(rand()%2)
        criarTriangulo(700.F, CHAO+300);

}

/** TODO: Talvez por isto na fase abstrata, e chamar
 *     Fase::Executar no fim do loop de cada fase. 
 *     Isto pouparia tempo.
 */ 
void Fases::Calabouco::executar(const float dT)
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

Fases::Calabouco::Calabouco():
    Fase(),
    maxInimigos(100)
{
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

Fases::Calabouco::~Calabouco()
{ }