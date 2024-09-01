/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe derivada MenuPause, responsável por executar métodos específicos
 *             aos menu de pausa do jogo.
 */

#include "MenuPause.hpp"
#include "Erros.hpp"

namespace Menus
{
    MenuPause::MenuPause(idEstados id):
    Estado(id),
    Menu()
    {        
        //Seta o título
        titulo.setInfo("JOGO PAUSADO");
        titulo.setTamanho(125);
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
            cout << "Erro em Menus::MenuPause::MenuPause()::pOpcao: " << ERRO_ALOCACAO << endl;

        //Op1: ----------------------------------------------------------------------------------------
        pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("1. Voltar ao jogo");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPause::MenuPause()::pOpcao: " << ERRO_ALOCACAO << endl;
        
        //Op2: ----------------------------------------------------------------------------------------
        pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("2. Salvar e voltar ao menu principal");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPause::MenuPause()::pOpcao: " << ERRO_ALOCACAO << endl;

         //Op3: ----------------------------------------------------------------------------------------
        pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("3. Voltar ao menu principal");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPause::MenuPause()::pOpcao: " << ERRO_ALOCACAO << endl;

        //Percorre o vetor ajustando o texto das opções
        for(int i=0; i<(int)opcoes.size(); i++)
        {
            if(opcoes[i])
            {
                opcoes[i]->setTamanho(50);
                opcoes[i]->setPosicao(200, 250.0 + (100.0*(i+1)));
                opcoes[i]->setCor(branco);
            }
            else
                cout << "Erro em Menus::MenuPause::MenuPause()::Texto*: " << ERRO_NULLPTR << endl;
        }       
    }

    MenuPause::~MenuPause()
    {
        for(int i=0; i<(int)opcoes.size(); i++)
        {
            if(opcoes[i])
                delete opcoes[i];
        }

        opcoes.clear();
    }
    
    //Executa o loop para renderizar e mostrar os elementos do menu principal na tela.
    void MenuPause::executar(const float dT)
    {
        //Deixa as opções brancas novamente
        for(int i=0; i<(int)opcoes.size(); i++)
        {
            if(opcoes[i])
                opcoes[i]->setCor(branco);
            else
                cout << "Erro em Menus::MenuPause::executar()::Texto*: " << ERRO_NULLPTR << endl;
        }
        
        //Executa o loop principal
        if(pGG)
        {
            while (pGG->janelaAberta())
            {
                pGG->limpar(); //Limpar a janela
                
                if(pGE)
                    pGE->executar(); // Checar se a janela deve ser fechada.
                else
                    cout << "Erro em Menus::MenuPause::executar(): " << ERRO_NULLPGE << endl;

                desenhar(); //Colocar na tela titulo e opções

                pGG->mostrar();
            } 
        }
        else
            cout << "Erro em Menus::MenuPause::executar(): " << ERRO_NULLPGG << endl;
    }
    
    //Renderiza título e opções na tela.
    void MenuPause::desenhar()
    {
        titulo.renderizar();

        for(int i=0; i<(int)opcoes.size(); i++)
        {
            if(opcoes[i])
                opcoes[i]->renderizar();
            else
                cout << "Erro em Menus::MenuPause::desenhar()::Texto*: " << ERRO_NULLPTR << endl;
        }

    }

    void MenuPause::verificaTeclaPressionada(string tecla)
    {
        if(tecla == "1") //Começa em 1 em função do subtitulo que ocupa a posição 0 do vetor
        {
            if(opcoes[1])
                opcoes[1]->setCor(vermelho);
            else
                cout << "Erro em Menus::MenuPause::verificaTeclaPressionada()::Texto*: " << ERRO_NULLPTR << endl;
        }
        else if(tecla == "2")
        {
            if(opcoes[2])
                opcoes[2]->setCor(vermelho);
            else
                cout << "Erro em Menus::MenuPause::verificaTeclaPressionada()::Texto*: " << ERRO_NULLPTR << endl;
        }
        else if(tecla == "3")
        {
            if(opcoes[3])
                opcoes[3]->setCor(vermelho);
            else
                cout << "Erro em Menus::MenuPause::verificaTeclaPressionada()::Texto*: " << ERRO_NULLPTR << endl;
        }
    }
    
    void MenuPause::verificaTeclaSolta(string tecla)
    {
        if(pGEs)
        {
            //pGEs->getEstadoAtual()->setAtivo(false);

            if(tecla == "1") //Voltar ao jogo
            {
                if(pGEs->getEstado(fase1))
                {
                    cout<<"JOGO DESPAUSADO" << endl;
                    cout << "Entrou em if(pGEs->getEstado(fase1))" << endl;
                    if(pGEs->getEstado(fase1)->getAtivo())
                        {cout << "Entrou em if(pGEs->getEstado(fase1)->getAtivo())" << endl; pGEs->executarEstado(fase1);}
                }
                else
                    cout << "Erro em Menus::MenuPause::verificaTeclaPressionada()::Estado*: " << ERRO_NULLPTR << endl;
                
                if(pGEs->getEstado(fase2))
                {   
                    cout <<"Entrou no if da fase 2" << endl;
                    if(pGEs->getEstado(fase2)->getAtivo())  
                        pGEs->executarEstado(fase2);
                }
                else    
                    cout << "Erro em Menus::MenuPause::verificaTeclaPressionada()::Estado*: " << ERRO_NULLPTR << endl;
            }
            else if(tecla == "2")
            {
                //comando para salvamento
                pGEs->executarEstado(menuPrincipal);
            }
            else if(tecla == "2")
                pGEs->executarEstado(menuPrincipal);
        }
        else
            cout << "Erro em Menus::MenuPause::verificaTeclaSolta(): " << ERRO_NULLPGES << endl;
    }
}