#include "Entidades/Personagens/Inimigos/Triangulo.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Entidades/Obstaculos/Lapis.hpp"
#include "Entidades/Obstaculos/PlataformaGrudenta.hpp"
#include "Fases/Calabouco.hpp"
#include "Menus/MenuFinal.hpp"
#include "Calabouco.hpp"
#include "Jogo.hpp"

//#define GRAVIDADE      1000.0F
/*#define LARGURA_FASE   2580.0F
#define ALTURA_FASE    1440.0F
#define CHAO           ALTURA_FASE
#define TETO              0.0F
#define CANTO_ESQUERDO    0.0F
#define CANTO_DIREITO     LARGURA_FASE*/
#define X_SAIDA_CA CANTO_DIREITO-250.0F
#define Y_SAIDA_CA TETO+200.0F

using namespace Fases;

void Fases::Calabouco::criarObstaculos() 
{
    criarPlataforma ((CANTO_DIREITO + CANTO_ESQUERDO)/2.F - 200.F, CHAO-540.F, LARGURA_FASE-400.F, 100.f);  // SEGUNDO  PISO
    criarPlataforma ((CANTO_DIREITO + CANTO_ESQUERDO)/2.F + 200.F, CHAO-1140.F, LARGURA_FASE-400.F, 100.f); // TERCEIRO PISO
    criarPlataforma (CANTO_DIREITO - 250.F, CHAO - 300.f, 400.f, 100.f);
    criarPlataforma (CANTO_ESQUERDO + 250.F, CHAO - 740.f, 400.F, 300.F);
    criarPlataforma (800.f, CHAO-100.f, 500.f,  100.F);
    criarPlataforma (700.f, CHAO-900.f, 500.f,  100.F);
    criarPlataformaGrudenta (700.f, CHAO-950.f, 200.f, 50.f);
    criarPlataformaGrudenta (950.f, CHAO-1190.F, 230.f, 50.f);
    criarPlataformaGrudenta (1200.f, CHAO-1190.F, 200.f, 50.f);
    
    if((bool) rand()%3) 
        criarPlataforma(CANTO_DIREITO - 250.F, CHAO - 1000.f, 500.F, 300.F);

    if((bool) rand()%3) 
        criarPlataforma(CANTO_DIREITO - 350.F, CHAO - 1600.f, 400.F, 300.F);

    if((bool) rand()%100 < 60) 
        criarPlataformaGrudenta(CANTO_DIREITO - 350.F, CHAO - 1650.f, 400.F, 300.F);
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

    if(rand()%100 + 1 <= 80)
        criarTriangulo(700.F, CHAO+300);
    if(rand()%100 + 1 <= 80)
        criarQuadrado(CANTO_DIREITO-450.F, CHAO-1000.F);
    if(rand()%100 + 1 <= 50)
        criarTriangulo(CANTO_DIREITO-500.F, CHAO-1000.F);

}

const bool Fases::Calabouco::verificaVitoria()
{
    static Vetor2f limiteSaida(X_SAIDA_CA-150, Y_SAIDA_CA+320);

    if(pJog && pJog->getVivo())
    {
        if(doisJogadores && pJog2 && pJog2->getVivo())
        {
            return pJog->getX() > limiteSaida.x && pJog->getY() < limiteSaida.y &&  pJog2->getX() > limiteSaida.x && pJog2->getY() < limiteSaida.y;
        }
        else
        {
            return pJog->getX() > limiteSaida.x && pJog->getY() < limiteSaida.y;
        }
    }
    else if(doisJogadores && pJog2 && pJog2->getVivo())
    {
        return pJog2->getX() > limiteSaida.x && pJog2->getY() < limiteSaida.y;
    }
    else
    {
        return false;
    }
}

/** TODO: Talvez por isto na fase abstrata, e chamar
 *     Fase::Executar no fim do loop de cada fase. 
 *     Isto pouparia tempo.
 */
void Fases::Calabouco::executar(const float dT) 
{
    while (pGG->janelaAberta())
    {
        /*if(pGC)
            cout << "Tem pgc" << endl;
        else
            cout <<"não tem pgc" << endl;*/

        pGG->limpar();
        //cout << "Passou limpar" << endl;
        pGC->executar(); // Checar colisoes e gerar seus efeitos.
        //cout << "Passou gc" << endl;
        pGE->executar(); // Checar se a janela deve ser fechada.


        t0 = t1;
        t1 = pGG->getTempo();
        deltaT = t1 - t0;

        // Executar, mover e desenhar entidades.
        
        desenhar();
        pGG->renderizar(&saida);
        //cout << "Passou corpo saida" << endl;
        colecao.percorrer(deltaT);


        if(verificaVitoria())
        {
            Estado::setAtivo(false);

            if(pGEs)
            {
                if(sequenciaFases)
                    pGEs->executarEstado(idEstados::fase2);
                else
                {
                    static_cast<Menus::MenuFinal*>(pGEs->getEstado(menuFimJogo))->setpFase(this);
                    pGEs->executarEstado(menuFimJogo);
                }
            }
            else
                cout << "Erro em Fases::Calabouco::executar(): " << ERRO_NULLPGES << endl;
            
            cout << "GANHARAM!" << endl;
        }
        else if(verificaGameOver())
        {
            Estado::setAtivo(false);

            if(pGEs)
            {
                static_cast<Menus::MenuFinal*>(pGEs->getEstado(menuFimJogo))->setpFase(this);
                pGEs->executarEstado(menuFimJogo);
            }
            else
                cout << "Erro em Fases::Calabouco::executar(): " << ERRO_NULLPGES << endl;
            
        }
        
        pGG->mostrar();
    }
}

Fases::Calabouco::Calabouco():
    Fase(),
    maxInimigos(100)
{
    nome = "../dados/calabouco.json";
    idEstado = fase1;
    
    saida.atualizar(Vetor2f(X_SAIDA_CA, Y_SAIDA_CA));
    if(pJog2) pJog2->setAtivo(doisJogadores);

    criarBordas();
    
    if(deveCarregar)
    {
        carregar("../dados/calabouco.json");
        deveCarregar = false;
    }
    else
    {
        pJog->setPos(190.f, CHAO-100.f);
        pJog->setPontos(0);
        pJog->setVida(pJog->getMaxVida());
        
        if(doisJogadores && pJog2)
        {
            pJog2->setPos(170.f, CHAO-100.f);
            pJog2->setPontos(0);
            pJog2->setVida(pJog2->getMaxVida());
        }
        
        criarObstaculos();
        criarInimigos();
    }

    colecao.setGravidade(GRAVIDADE);

    colecao.irAoInicio();
}

Fases::Calabouco::~Calabouco()
{ 

}