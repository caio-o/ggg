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
        titulo.setInfo("GGG: GRANDE GUERRA GEOMÉTRICA");
        titulo.setPosicao(pGG->getTamanhoJanela().x/2, pGG->getTamanhoJanela().y-50);
        titulo.setTamanho(20);
        titulo.setCor(branco);
        titulo.setAlinhamento(centro);

        cout << "Setou titulo" << endl;
        opcoes.clear();
        
        //Seta as opções
        //Subtitulo:
        ElementosGraficos::Texto* pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("Escolha uma das opções abaixo: ");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;

        //Op1:
        pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("1 - Jogar com um jogador;");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;

         //Op2:
        pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("2 - Jogar com dois jogadores;");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;

         //Op3:
        pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("3 - Recuperar jogo salvo;");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;

         //Op4:
        pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("4 - Ver ranking;");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;

         //Op5:
        pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("5 - Encerrar jogo.");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;

        cout << "Alocou opções" << endl;

        //Percorre o vetor ajustando o texto das opções
        for(int i=0; i<(int)opcoes.size(); i++)
        {
            opcoes[i]->setPosicao(pGG->getTamanhoJanela().x/2, pGG->getTamanhoJanela().y-(100.0*i));
            opcoes[i]->setTamanho(10);
            opcoes[i]->setCor(branco);
            opcoes[i]->setAlinhamento(centro);
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
    // void MenuPrincipal::verificaTeclaPressionada(string tecla)
    // {
    //     bool doisJogadores = false;

    //     int op = -1;

    //     cin >> op;

    //     //Obs.: só o caso 0 está corretamente implementado até o momento...
    //     switch (op)
    //     {
    //         case 0:
    //             pGEs->executarEstado(faseTeste);
            
    //         //Selecionar jogar com um ou dois jogadores leva ao menu de seleção das fases...
    //         case 1:
    //             pGEs->executarEstado(menuFase);
    //             break;
            
    //         case 2:
    //             doisJogadores = true; //isso funciona?? dois comandos no bloco sem chave?
    //             pGEs->executarEstado(menuFase);
    //             break;
            
    //         case 5:
    //             Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico()->fecharJanela();

    //         default:
    //             break;
    //     }
    // }

} // namespace Menus
