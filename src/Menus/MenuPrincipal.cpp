/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe derivada EstadoMenu, responsável por executar métodos específicos
 *             aos menus do jogo.
 */

#include "Erros.hpp"
#include "MenuPrincipal.hpp"

#include "Gerenciadores/GerenciadorEstados.hpp"
#include "Gerenciadores/GerenciadorEventos.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"

#include "iostream"
using namespace std;

namespace Menus
{
    MenuPrincipal::MenuPrincipal(idEstados id):
    Estado(id),
    Menu()
    {
        cout << "Inicio da alocação do MenuPrincipal" << endl;
        
        //Seta o título
        titulo.setInfo("GGG: GRANDE GUERRA GEOMETRICA");
        titulo.setAlinhamento(centro);
        titulo.setPosicao(pGG->getCentroCamera().x, 100.0);
        titulo.setTamanho(125);
        titulo.setCor(branco);

        cout << "Setou titulo" << endl;
        opcoes.clear();
        
        //Seta as opções
        //Subtitulo:
        ElementosGraficos::Texto* pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("Escolha uma das opcoes abaixo: ");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;

        //Op1:
        pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("1. Jogar com um jogador");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;

         //Op2:
        pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("2. Jogar com dois jogadores");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;

         //Op3:
        pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("3. Recuperar jogo salvo");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;

         //Op4:
        pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("4. Ver ranking");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;

         //Op5:
        pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("5. Encerrar jogo");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;

        cout << "Alocou opções" << endl;

        //Percorre o vetor ajustando o texto das opções
        for(int i=0; i<(int)opcoes.size(); i++)
        {
            opcoes[i]->setAlinhamento(esquerda);
            opcoes[i]->setPosicao(pGG->getCentroCamera().x, 300.0 + (100.0*(i+1)));
            opcoes[i]->setTamanho(50);
            opcoes[i]->setCor(branco);
        }

        cout << "2 - Menu principal construido com título e opções!" << endl;
        
    }

    MenuPrincipal::~MenuPrincipal()
    {

    }
    
    void MenuPrincipal::executar(const float dT)
    {
        while (pGG->janelaAberta())
        {
            cout << "Solicita limpeza da tela e checagem das teclas" << endl;
            pGG->limpar();
            pGE->executar(); // Checar se a janela deve ser fechada.

            cout << "Solicita renderezição do texto" << endl;
            desenhar();

            cout << "SOlicita mostrar na tela" << endl;
            pGG->mostrar();
        } 

        cout << "Execução do menu principal concluida" << endl;    
    }
    
    void MenuPrincipal::desenhar()
    {
        titulo.renderizar();

        for(int i=0; i<(int)opcoes.size(); i++)
            opcoes[i]->renderizar();

        cout << "Renderização do menuPrincipal concluida!" << endl;
    }

    //Precisa implementar e adaptar o código
    void MenuPrincipal::verificaTeclaPressionada(string tecla)
    {
        if(tecla == "1")
            opcoes[1]->setCor(vermelho); //Começa em 1 pq no 0 é o subtitulo
        else if(tecla == "2")
            opcoes[2]->setCor(vermelho);
        else if(tecla == "3")
            opcoes[3]->setCor(vermelho);
        else if(tecla == "4")
            opcoes[4]->setCor(vermelho);
        else if(tecla == "5")
            opcoes[5]->setCor(vermelho);
    }

    void MenuPrincipal::verificaTeclaSolta(string tecla)
    {
        if(tecla == "1") //Jogar com um jogador
            pGEs->executarEstado(menuFase); //Começa em 1 pq no 0 é o subtitulo
        else if(tecla == "2") //Jogar com dois jogadores
        {
            //pFase->setDoisJogadores(true);
            //pGEs->executarEstado(menuFase);
            pGEs->executarEstado(fase1);//provisorio
        }
        else if(tecla == "3") //Recuperar jogo salvo
            pGEs->executarEstado(jogo);
        else if(tecla == "4") //Ver ranking
            pGEs->executarEstado(ranking);
        else if(tecla == "5")
            pGG->fecharJanela();
        //Obs.: só o caso 0 está corretamente implementado até o momento...
        // switch (tecla)
        // {
        //     case 1:
        //         pGEs->executarEstado(menuFase);
        //         break;
            
        //     //Selecionar jogar com um ou dois jogadores leva ao menu de seleção das fases...
        //     case 2:
        //         //pFase->setDoisJogadores(true);
        //         pGEs->executarEstado(menuFase);
        //         break;
            
        //     case 3:
        //         pGEs->executarEstado(jogo);
        //         break;
            
        //     case 4:
        //         pGEs->executarEstado(ranking);
        //         break;

        //     case 5:
        //         pGG->fecharJanela();
        //         break;
            
        //     default:
        //         break;
        // }
    }

} // namespace Menus
