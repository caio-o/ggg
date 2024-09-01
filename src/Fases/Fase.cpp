#include "Fases/Fase.hpp"
#include "Entidades/Obstaculos/Plataforma.hpp"
#include "Entidades/Obstaculos/PlataformaGrudenta.hpp"
#include "Entidades/Personagens/Inimigos/Quadrado.hpp"
#include "Entidades/Personagens/Inimigos/Triangulo.hpp"
#include "Entidades/Projetil.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include "Fase.hpp"

namespace Fases
{
    Gerenciadores::GerenciadorColisoes* Fase::pGC(NULL);
    
    Fase::Fase():
    Estado(),
    Ente(),
    t0(0.0f),
    t1(0.0f),
    deltaT(0.0f),
    colecao(),
    pJog(NULL),
    pJog2(NULL),
    gameOver(false),
    saida(Vetor2f(CANTO_DIREITO-350.0F, TETO-50.0F), Vetor2f(400.f, 400.f), "../img/saida_luz.png", 1.f),
    efeitoGameOver(Vetor2f (1290, 720.f), Vetor2f(2580.f, 1440.f), "../img/game_over.png", 1.f)
    {
        t0 = pGG->getTempo();
        t1 = pGG->getTempo();

        setGerenciadorColisoes();
    }

    Fase::~Fase()
    {
        if(pGC)
            delete pGC;
    }

    void Fase::salvar() 
    {
        ofstream ofs("../dados/save.json");

        colecao.salvar(ofs); // delegar a tarefa para a ListaEntidades, especificando o arquivo correspondente.

        ofs.close();
    }

    void Fase::carregar()
    {
        cout << "FASE CARREGAR 1" << endl;
        // FUTURAMENTE USAR TRY CATCH
        ifstream ifs("../dados/save.json");
        string linha = "";
        nlohmann::ordered_json j;
        Especie esp = indefinido;
        
        // Se o arquivo eh acessivel
        if(ifs.good())
        {
            cout << "FASE CARREGAR 2 (ANTES DO LOOP)" << endl;
            while(! ifs.eof() && j["especie"] != -1)
            {
                linha = "";
                std::getline(ifs, linha);

                j = nlohmann::ordered_json::parse(linha);

                if(! j.is_null())
                {
                    esp = j["especie"];

                    switch(esp)
                    {
                    case jogador:
                        if(j["ehJogador1"])
                        {
                            if(pJog) { pJog->carregar(j);                       }
                            else     { pJog = new Jogador(); pJog->carregar(j); }
                        }
                        else
                        {
                            if(pJog2) { pJog2->carregar(j);                        }
                            else      { pJog2 = new Jogador(); pJog2->carregar(j); }
                        }
                        break;


                    case plataforma:
                        criarPlataforma(0.f, 0.f)->carregar(j);
                        break;

                    case plataformaGrudenta:
                        criarPlataformaGrudenta(0.f,0.f)->carregar(j);
                        break;

                    case quadrado:
                        criarQuadrado(0.f,0.f)->carregar(j);
                        break;

                    case triangulo:
                        criarTriangulo(0.f, 0.f)->carregar(j);
                        break;
                    
                    default:
                        break;
                    }
                }
            }
            cout << "FASE CARREGAR 3 (DEPOIS DO LOOP)" << endl;
        }
        
    }

    Projetil* Fase::criarProjetil(const float x, const float y)
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

        return pProj;
    }

    Plataforma* Fase::criarPlataforma(float posX, float posY, float tamX, float tamY)
    {
        Plataforma *pPlat = new Obstaculos::Plataforma(tamX, tamY);

        if(pPlat)
        {
            pPlat->setPos(posX, posY);
            colecao.incluir(static_cast<Entidade*> (pPlat));
            pGC->inserirObstaculo(static_cast<Obstaculo*> (pPlat));
        }

        else cout << "Faseteste::criarPlataforma: " << ERRO_ALOCACAO << "\n" << ERRO_INCLUI_NULLPTR << endl;
    
        return pPlat;
    }

    PlataformaGrudenta* Fase::criarPlataformaGrudenta(float posX, float posY, float tamX, float tamY)
    {
        PlataformaGrudenta *pPlat = new PlataformaGrudenta(tamX, tamY);

        if(pPlat)
        {
            pPlat->setPos(posX, posY);
            colecao.incluir(static_cast<Entidade*> (pPlat));
            pGC->inserirObstaculo(static_cast<Obstaculo*> (pPlat));
        }

        else cout << "Faseteste::criarPlataforma: " << ERRO_ALOCACAO << "\n" << ERRO_INCLUI_NULLPTR << endl;
        return pPlat;
    }

    void Fase::criarBordas()
    {
            //                 POS_X                                    POS_Y           TAM_X           TAM_Y
        criarPlataforma (CANTO_ESQUERDO,                         ALTURA_FASE/2.F,   100.f,          ALTURA_FASE); // PAREDE ESQUERDA
        criarPlataforma (CANTO_DIREITO,                          ALTURA_FASE/2.F,   100.f,          ALTURA_FASE); // PAREDE DIREITA
        criarPlataforma ((CANTO_DIREITO + CANTO_ESQUERDO)/2.F,   CHAO,              LARGURA_FASE,   100.f);       // CHAO
        criarPlataforma ((CANTO_DIREITO + CANTO_ESQUERDO)/2.F,   TETO,              LARGURA_FASE,   100.f);       // TETO

    }

    Triangulo* Fase::criarTriangulo(float posX, float posY)
    {
        Triangulo* pTri = new Triangulo(Especie::inimigo);
        
        if(pTri)
        {
            pTri->setPos(posX, posY);
            pGC->inserirInimigo(static_cast<Inimigo*>(pTri));
            colecao.incluir(static_cast<Entidade*> (pTri));
        }
        else cout << "Em funcao Fase::criarTriangulo:" << ERRO_ALOCACAO << endl;

        return pTri;
    }

    Quadrado* Fase::criarQuadrado(float posX, float posY)
    {
        Quadrado* pQuad = new Quadrado(Especie::inimigo, 10);

        if(pQuad)
        {
            pQuad->setPos(posX, posY);
            pGC->inserirInimigo(static_cast<Inimigo*>(pQuad));
            colecao.incluir(static_cast<Entidade*> (pQuad));
        }
        else cout << "Em funcao Fase::criarQuadrado:" << ERRO_ALOCACAO << endl;

        return pQuad;
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
    }

    void Fase::setGerenciadorColisoes()
    {
        pGC = Gerenciadores::GerenciadorColisoes::getInstancia();
    }
} // namespace Fases
