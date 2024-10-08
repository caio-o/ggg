/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe derivada MenuPrincipal, responsável por permitir ao jogador 
 *             iniciar a execução das fases, escolher a quantidade de jogadores, exibir o ranking,
 *             carregar um jogo salvo ou encerrar a execução da aplicação.
 */

#include "Erros.hpp"

#include "MenuPrincipal.hpp"
#include "MenuFinal.hpp"

#include "Fases/Fase.hpp"

#include "Gerenciadores/GerenciadorEstados.hpp"
#include "Gerenciadores/GerenciadorEventos.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"

#include "Fases/Fase.hpp"
#include "Fases/Calabouco.hpp"
#include "Fases/Tuneis.hpp"

#include "iostream"
using namespace std;

namespace Menus
{
    MenuPrincipal::MenuPrincipal(idEstados id):
    Estado(id),
    Menu(),
    doisJogadores(false)
    {        
        //Seta o título
        titulo.setInfo("GGG: GRANDE GUERRA GEOMETRICA");
        titulo.setTamanho(125); //o tamanho muda a caixa de texto
        titulo.setPosicao(200.0, 100.0);
        titulo.setCor(branco);

        opcoes.clear();
        
        //Aloca as opções
        //Subtitulo:
        ElementosGraficos::Texto* pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("Escolha uma das opcoes abaixo: ");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;

        //Op1: ----------------------------------------------------------------------------------------
        pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("1. Jogar com um jogador");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;

         //Op2: ----------------------------------------------------------------------------------------
        pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("2. Jogar com dois jogadores");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;

        //Op3: ----------------------------------------------------------------------------------------
        pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("3. Jogar sequencia de fases");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;

        //Op4: ----------------------------------------------------------------------------------------
        pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("4. Jogar apenas fase Calabouco");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;
        
        //Op5: ----------------------------------------------------------------------------------------
        pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("5. Jogar apenas fase Tuneis");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;
        
        //Op6:
        pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("6. Recuperar jogo salvo");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;

         //Op7:
        pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("7. Ver ranking");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;

         //Op8:
        pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("8. Encerrar jogo");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;

        //Percorre o vetor ajustando o texto das opções
        for(int i=0; i<(int)opcoes.size(); i++)
        {
            if(opcoes[i])
            {
                opcoes[i]->setTamanho(50);
                opcoes[i]->setPosicao(200.0, 250.0 + (100.0*(i+1)));
                opcoes[i]->setCor(branco);
            }
            else
                cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::Texto*: " << ERRO_NULLPTR << endl;
        }       
    }

    MenuPrincipal::~MenuPrincipal()
    {
        for(int i=0; i<(int)opcoes.size(); i++)
        {
            if(opcoes[i])
                delete opcoes[i];
        }

        opcoes.clear();
    }
    
    //Permite que o jogador navegue entre todas as opções iniciais do jogo (quantidade de jogadores,
    //fases, ranking, jogo salvo ou finalização)
    void MenuPrincipal::executar(const float dT)
    {
        //Reseta 2 jogadores
        doisJogadores = false;
        
        //Deixa as opções brancas novamente
        for(int i=0; i<(int)opcoes.size(); i++)
        {
            if(opcoes[i])
                opcoes[i]->setCor(branco);
            else
                cout << "Erro em Menus::MenuPrincipal::executar()::Texto*: " << ERRO_NULLPTR << endl;
        }
        
        //Executa o loop
        if(pGG)
        {
            while (pGG->janelaAberta())
            {
                pGG->limpar(); //Limpar a janela
                
                if(pGE)
                    pGE->executar(); // Checar se a janela deve ser fechada.
                else
                    cout << "Erro em Menus::MenuPrincipal::executar(): " << ERRO_NULLPGE << endl;

                desenhar(); //Colocar na tela titulo e opções

                pGG->mostrar();
            } 
        }
        else
            cout << "Erro em Menus::MenuPrincipal::executar(): " << ERRO_NULLPGG << endl;
        
    }
    
    //Renderiza título e opções na tela.
    void MenuPrincipal::desenhar()
    {
        titulo.renderizar();

        for(int i=0; i<(int)opcoes.size(); i++)
        {
            if(opcoes[i])
                opcoes[i]->renderizar();
            else
                cout << "Erro em Menus::MenuPrincipal::desenhar()::Texto*: " << ERRO_NULLPTR << endl;
        }

    }

    //Destaca a tecla pressionada com a cor vermelho 
    void MenuPrincipal::verificaTeclaPressionada(string tecla)
    {
        if(tecla == "1")
        {
            if(opcoes[1] && opcoes[2]) //Começa em 1 pq no 0 é o subtitulo
            {
                opcoes[1]->setCor(vermelho); 
                opcoes[2]->setCor(branco);
            }
            else
                cout << "Erro em Menus::MenuPrincipal::verificaTeclaPressionada()::Texto*: " << ERRO_NULLPTR << endl;
        }
        else if(tecla == "2")
        {            
            if(opcoes[2] && opcoes[1])
            {
                opcoes[2]->setCor(vermelho);
                opcoes[1]->setCor(branco);
            }
            else
                cout << "Erro em Menus::MenuPrincipal::verificaTeclaPressionada()::Texto*: " << ERRO_NULLPTR << endl;
        }
        else if(tecla == "3")
        {
             if(opcoes[3])
                opcoes[3]->setCor(vermelho);
            else
                cout << "Erro em Menus::MenuPrincipal::verificaTeclaPressionada()::Texto*: " << ERRO_NULLPTR << endl;
        }
        else if(tecla == "4")
        {
             if(opcoes[4])
                opcoes[4]->setCor(vermelho);
            else
                cout << "Erro em Menus::MenuPrincipal::verificaTeclaPressionada()::Texto*: " << ERRO_NULLPTR << endl;
        }
        else if(tecla == "5")
        {
             if(opcoes[5])
                opcoes[5]->setCor(vermelho);
            else
                cout << "Erro em Menus::MenuPrincipal::verificaTeclaPressionada()::Texto*: " << ERRO_NULLPTR << endl;
        }
        else if(tecla == "6")
        {
             if(opcoes[6])
                opcoes[6]->setCor(vermelho);
            else
                cout << "Erro em Menus::MenuPrincipal::verificaTeclaPressionada()::Texto*: " << ERRO_NULLPTR << endl;
        }
        else if(tecla == "7")
        {
             if(opcoes[7])
                opcoes[7]->setCor(vermelho);
            else
                cout << "Erro em Menus::MenuPrincipal::verificaTeclaPressionada()::Texto*: " << ERRO_NULLPTR << endl;
        }
        else if(tecla == "8")
        {
             if(opcoes[8])
                opcoes[8]->setCor(vermelho);
            else
                cout << "Erro em Menus::MenuPrincipal::verificaTeclaPressionada()::Texto*: " << ERRO_NULLPTR << endl;
        }
    }

    //Chama a ação pertinente a tecla solta
    void MenuPrincipal::verificaTeclaSolta(string tecla)
    {
        if(pGEs)
        {
            if(tecla == "1") //Jogar com um jogador
            {
                doisJogadores = false; 
                static_cast<MenuFinal*>(pGEs->getEstado(menuFimJogo))->setDoisJogadores(doisJogadores);

                cout << "doisJogadores = " << doisJogadores << endl;
            }
            
            if(tecla == "2") //Jogar com dois jogadores
            {
                doisJogadores = true; 
                static_cast<MenuFinal*>(pGEs->getEstado(menuFimJogo))->setDoisJogadores(doisJogadores);
                
                cout << "doisJogadores = " << doisJogadores << endl;
            }
            
            else if(tecla == "3") //Jogar sequência de fases
            {
                Fases::Fase::setDeveCarregar(false);
                Fases::Fase::setDoisJogadores(doisJogadores);
                Fases::Fase::setSequenciaFases(true);
                
                pGEs->executarEstado(fase1);
            }

            else if(tecla == "4") //Jogar fase calabouco
            {
                Fases::Fase::setDoisJogadores(doisJogadores);
                Fases::Fase::setSequenciaFases(false);

                pGEs->executarEstado(fase1);
            }

            else if(tecla == "5") //Jogar fase tuneis
            {
                Fases::Fase::setDoisJogadores(doisJogadores);
                Fases::Fase::setDoisJogadores(doisJogadores);

                pGEs->executarEstado(fase2);
            }

            else if(tecla == "6") //Recuperar jogo salvo
            {
                Fases::Fase::setDeveCarregar(true);
                Fases::Fase::setDoisJogadores(doisJogadores);
            }

            else if(tecla == "7") //Ver ranking
            {
                pGEs->executarEstado(ranking);
            }
            
            else if(tecla == "8") //Encerrar jogo
            {
                if(pGG)
                    pGG->fecharJanela();
                else
                    cout << "Erro em Menus::MenuPrincipal::verificaTeclaSolta(): " << ERRO_NULLPGG << endl;
            }
        }
        else
            cout << "Erro em Menus::MenuPrincipal::verificaTeclaSolta(): " << ERRO_NULLPGES << endl;
    }

} // namespace Menus
