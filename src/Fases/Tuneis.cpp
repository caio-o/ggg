#include <iostream>
#include <fstream>

#include "Fases/Tuneis.hpp"
#include "Tuneis.hpp"

#include "Menus/MenuFinal.hpp"

#include "Entidades/Personagens/Inimigos/Quadrado.hpp"
#include "Entidades/Personagens/Inimigos/Triangulo.hpp"
#include "Entidades/Personagens/Inimigos/Estrela.hpp"

#include "Entidades/Obstaculos/Plataforma.hpp"
#include "Entidades/Obstaculos/PlataformaGrudenta.hpp"
#include "Entidades/Obstaculos/Lapis.hpp"

#define X_SAIDA CANTO_DIREITO-250.0F
#define Y_SAIDA TETO+200.0F

Lapis* Fases::Tuneis::criarLapis(float posX, float posY, int dano)
{
    Obstaculos::Lapis *pLap = new Obstaculos::Lapis();
    
    if(pLap)
    {
        pLap->setPos(posX, posY);
        colecao.incluir(static_cast<Entidade*> (pLap));
        pGC->inserirObstaculo(static_cast<Obstaculo*> (pLap));
    }

    return pLap;
}

Estrela* Fases::Tuneis::criarChefaoEstrela(const float posX, const float posY, const int nCapangas)
{
    if(numChefoes < maxChefao)
    {
        Estrela* pChefao = new Estrela();
        
        if(pChefao)
        {
            pChefao->setNumCapangas(nCapangas);
            pChefao->setPos(posX, posY);
            colecao.incluir(static_cast<Entidade*>(pChefao));
            pGC->inserirInimigo(static_cast<Inimigo*> (pChefao));

            numChefoes++;
        }
        return pChefao;
    }
    else
    {
        return NULL;
    }

}

void Fases::Tuneis::criarObstaculos()
{
    criarPlataforma ((CANTO_DIREITO + CANTO_ESQUERDO)/2.F - 200.F, CHAO-540.F, LARGURA_FASE-400.F, 100.f);  // SEGUNDO  PISO
    criarPlataforma ((CANTO_DIREITO + CANTO_ESQUERDO)/2.F + 200.F, CHAO-1140.F, LARGURA_FASE-400.F, 100.f); // TERCEIRO PISO
    criarPlataforma (CANTO_DIREITO - 250.F, CHAO - 300.f, 400.f, 100.f);
    criarPlataforma (CANTO_ESQUERDO + 250.F, CHAO - 740.f, 400.F, 300.F);
    criarPlataforma (700.f, CHAO-900.f, 500.f,  100.F);
    
    criarPlataformaGrudenta (800.f, CHAO-40.F, 500.F,  50.F);
    criarPlataformaGrudenta (850.F, CHAO-600.F, 90.F,  50.F);
    criarPlataformaGrudenta (990.F, CHAO-600.F, 80.F,  50.F);

    criarLapis(500.f, CHAO-60.F);
    criarLapis(650.f, CHAO-65.F);
    if ((bool) rand()%3) criarLapis(700.f, CHAO-30.F);
    criarLapis(750.f, CHAO-60.F);
    if ((rand()%100) <  2) criarLapis ( 800.f, CHAO-72.F);
    if ((rand()%100) <  2) criarLapis ( 850.f, CHAO-78.F);
    if ((rand()%100) <  2) criarLapis ( 900.f, CHAO-75.F);
    if ((rand()%100) <  2) criarLapis ( 950.f, CHAO-72.F);
    if ((rand()%100) < 10) criarLapis (1000.f, CHAO-70.F);
    if ((rand()%100) < 10) criarLapis (1050.f, CHAO-73.F);
    if ((rand()%100) < 10) criarLapis (1100.f, CHAO-63.F);
    if ((rand()%100) < 10) criarLapis (1150.f, CHAO-63.F);
    if ((rand()%100) < 10) criarLapis (1200.f, CHAO-53.F);
    if ((rand()%100) < 10) criarLapis (1250.f, CHAO-58.F);
    if ((rand()%100) < 10) criarLapis (1300.f, CHAO-73.F);
    if ((rand()%100) < 10) criarLapis (1350.f, CHAO-73.F);
    if ((rand()%100) < 10) criarLapis (1400.f, CHAO-53.F);
    if ((rand()%100) < 10) criarLapis (1450.f, CHAO-43.F);
    if ((rand()%100) < 10) criarLapis (1500.f, CHAO-43.F);
    if ((rand()%100) < 10) criarLapis (1550.f, CHAO-43.F);
    if ((rand()%100) < 10) criarLapis (1600.f, CHAO-43.F);
    if ((rand()%100) < 10) criarLapis (1650.f, CHAO-68.F);
    if ((rand()%100) < 10) criarLapis (1700.f, CHAO-53.F);
    if ((rand()%100) < 10) criarLapis (1750.f, CHAO-53.F);
    if ((rand()%100) < 10) criarLapis (1800.f, CHAO-53.F);
    if ((rand()%100) < 10) criarLapis (1850.f, CHAO-53.F);
    if ((rand()%100) < 10) criarLapis (1900.f, CHAO-69.F);
    if ((rand()%100) < 10) criarLapis (1950.f, CHAO-49.F);
    

    if ((bool) rand()%3) 
        criarPlataforma(CANTO_DIREITO - 250.F, CHAO - 1000.f, 500.F, 300.F);

    if ((bool) rand()%3) 
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
    
    criarChefaoEstrela(CANTO_DIREITO-400, CHAO-150.F, maxCapangas/maxChefao);
    criarChefaoEstrela(CANTO_ESQUERDO+400, CHAO-665.F, maxCapangas/maxChefao);
    criarChefaoEstrela(CANTO_DIREITO-400, CHAO-1315.F, maxCapangas/maxChefao);
}

Fases::Tuneis::Tuneis():
    Fase(),
    maxChefao(3),
    numChefoes(0)
    //saida(Vetor2f(X_SAIDA+200.F, Y_SAIDA-250.F), Vetor2f(400.f, 300.f), "", 1.f)
{
    maxInimigos = 100;
    maxCapangas = 10;

    nome = "../dados/tuneis.json";

    cout << "CONSTRUTORA FASE 2"<< endl;
    idEstado = fase2;
    forma.setTextura("../img/fundo_marrom.png", false);

    Ente::setGerenciadorGrafico();
    saida.getpCorpo()->setFillColor(sf::Color::Yellow);
    saida.atualizar(Vetor2f(X_SAIDA, Y_SAIDA));

    pJog->setPos(190.f, CHAO-100.f);
    
    cout << "ACCESSANDO JOGADOR 2" << endl;
    if(doisJogadores && pJog2)
    {
        pJog2->setPos(190.f, CHAO-100.f);
    }

    colecao.setGravidade(GRAVIDADE);
    
    criarBordas();
    
    if(deveCarregar)
    {
        cout << "CARREGANDO" << endl;
        carregar();
        deveCarregar = false;
    }
    else
    {
        criarObstaculos();
        criarInimigos();
    }

    Inimigo:: setpJogador1(pJog);
    Inimigo:: setpJogador2(pJog2);
    Projetil::setpJogador1(pJog);
    Projetil::setpJogador2(pJog2);
    Inimigos::Triangulo::setpFase(static_cast<Fase*>(this));
    Estrela::setFase(this);

    colecao.irAoInicio();
}

Fases::Tuneis::~Tuneis()
{

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

        desenhar();
        pGG->renderizar(&saida);
        colecao.percorrer(deltaT);

        if(pJog)
        {
            if(verificaVitoria() || verificaGameOver())
            {
                if(pGEs)
                {
                    setAtivo(false);
                    static_cast<Menus::MenuFinal*>(pGEs->getEstado(menuFimJogo))->setpFase(this);
                    pGEs->executarEstado(menuFimJogo);
                }
                else
                    cout << "Erro em Fases::Calabouco::executar(): " << ERRO_NULLPGES << endl;
            }
        }

        pGG->mostrar();
    }
}

const bool Fases::Tuneis::verificaVitoria()
{
    static Vetor2f limiteSaida(X_SAIDA-150, Y_SAIDA+320);

    if(pJog && pJog->getVivo())
    {
        if(pJog2 && doisJogadores && pJog2->getVivo())
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
void Fases::Tuneis::carregar(string nomeArquivo)
{
    cout << "FASE CARREGAR 1" << endl;
    // FUTURAMENTE USAR TRY CATCH
    if(nomeArquivo == "")
        nomeArquivo = nome;
    
    ifstream ifs(nomeArquivo);
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
                        if (pJog2 && doisJogadores) { pJog2->carregar(j);                        }
                        else      { if(doisJogadores) pJog2 = new Jogador(); pJog2->carregar(j); }
                    }
                    break;


                case plataforma:
                    criarPlataforma(0.f, 0.f)->carregar(j);
                    break;

                case plataformaGrudenta:
                    criarPlataformaGrudenta(0.f,0.f)->carregar(j);
                    break;

                case lapis:
                    criarLapis(0.f, 0.f)->carregar(j);
                    break;

                case quadrado:
                    criarQuadrado(0.f,0.f)->carregar(j);
                    break;

                case triangulo:
                    criarTriangulo(0.f, 0.f)->carregar(j);
                    break;
                    
                case estrela:
                    criarChefaoEstrela(0.f, 0.f, 100)->carregar(j);
                    break;

                case projetil:
                    criarProjetil(0.f, 0.f)->carregar(j);
                    break;

                default:
                    break;
                }
            }
        }
        cout << "FASE CARREGAR 3 (DEPOIS DO LOOP)" << endl;
    }
        
}
