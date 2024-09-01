#include "MenuFinal.hpp"

namespace Menus
{
    MenuFinal::MenuFinal(idEstados id):
    Estado(id),
    Menu(),
    pFase(NULL),
    nomeJogador2(false),
    nome1(),
    nome2()
    {
        //Seta o título
        titulo.setInfo("GGG!");
        titulo.setAlinhamento(centro);
        titulo.setPosicao(pGG->getCentroCamera().x, 100.0);
        titulo.setTamanho(200);
        titulo.setCor(branco);

        //Aloca subtitulo - 0
        Texto* pTexto  = NULL;
        pTexto = new Texto("Pressione Enter para registrar sua pontuacao no ranking ou Esc para retornar ao menu principal.");

        if(pTexto)
            opcoes.push_back(pTexto);
        else
            cout << "Erro em Menus::MenuFinal::MenuFinal()::Texto*: " << ERRO_ALOCACAO << endl;
        
        //Aloca pontuação jogador1 - 1
        pTexto  = NULL;
        pTexto = new Texto("Pontuacao do jogador 1: ");

        if(pTexto)
            opcoes.push_back(pTexto);
        else
            cout << "Erro em Menus::MenuFinal::MenuFinal()::Texto*: " << ERRO_ALOCACAO << endl;

        //Se houver, aloca pontuação do jogador2 - 2
        if(pFase && pFase->getJogador2())
        {
            pTexto  = NULL;
            pTexto = new Texto("Pontuacao do jogador2: ");

            if(pTexto)
                opcoes.push_back(pTexto);
            else
                cout << "Erro em Menus::MenuFinal::MenuFinal()::Texto*: " << ERRO_ALOCACAO << endl;
        }
        else
            cout << "Atenção em Menus::MenuFinal::MenuFinal()::Fase* e/ou Jogador*: " << ERRO_NULLPTR << endl;

        //Aloca nome do jogador1 - 3
        pTexto  = NULL;
        pTexto = new Texto("Nome: ");

        if(pTexto)
            opcoes.push_back(pTexto);
        else
            cout << "Erro em Menus::MenuFinal::MenuFinal(): Texto*: " << ERRO_ALOCACAO << endl;

        //Se houver, aloca nome do jogador2 - 4
        if(pFase && pFase->getJogador2())
        {
            
            pTexto  = NULL;
            pTexto = new Texto("Nome: ");

            if(pTexto)
                opcoes.push_back(pTexto);
            else
                cout << "Erro em Menus::MenuFinal::MenuFinal(): Texto*: " << ERRO_ALOCACAO << endl;
        }
        else
            cout << "Atenção em Menus::MenuFinal::MenuFinal()::Fase* e/ou Jogador*: " << ERRO_NULLPTR << endl;

        //Percorre o vetor ajustando o texto das opções
        for(int i=0; i<(int)opcoes.size(); i++)
        {
            if(opcoes[i])
            {
                opcoes[i]->setAlinhamento(esquerda);
                opcoes[i]->setPosicao(pGG->getCentroCamera().x, 300.0 + (200.0*(i+1)));
                opcoes[i]->setTamanho(75);
                opcoes[i]->setCor(branco);
            }
            else
                cout << "Erro em Menus::MenuPause::MenuPause()::Texto*: " << ERRO_NULLPTR << endl;
        }
    }

    MenuFinal::~MenuFinal()
    {

    }

    
    void MenuFinal::executar(const float dT)
    {
        //Configura o titulo conforme o que aconteceu durante o jogo
        if(pFase)
        {
            if(pFase->getGameOver())
                titulo.setInfo("GAME OVER!");
            else
                titulo.setInfo("GGG!");
        }
        else
            cout << "Erro em Menus::MenuPause::executar()::Fase*: " << ERRO_NULLPTR << endl;

        //Deixa as opções brancas novamente
        for(int i=0; i<(int)opcoes.size(); i++)
        {
            if(opcoes[i])
                opcoes[i]->setCor(branco);
            else
                cout << "Erro em Menus::MenuPause::executar()::Texto*: " << ERRO_NULLPTR << endl;
        }

        //Seta o texto que mostra a pontuação dos jogadores
        if(pFase)
        {
            string textoPontuacao = "Pontuacao do jogador 1: ";
            if(pFase->getJogador1())
                textoPontuacao += pFase->getJogador1()->getPontos();
            else
                cout << "Erro em Menus::MenuFinal::executar()::Jogador*: " << ERRO_NULLPTR << endl;

            if(opcoes[1])
                opcoes[1]->setInfo(textoPontuacao);
            else
                cout << "Erro em Menus::MenuFinal::executar()::Texto*: " << ERRO_NULLPTR << endl;

            if(pFase->getJogador2())
            {
                textoPontuacao = "Pontuacao do jogador 2: ";
                textoPontuacao += pFase->getJogador1()->getPontos();

                if(opcoes[2])
                    opcoes[2]->setInfo(textoPontuacao);
                else
                    cout << "Erro em Menus::MenuFinal::executar()::Texto*: " << ERRO_NULLPTR << endl;
            }
            else
                cout << "Atenção em Menus::MenuFinal::executar()::Fase*: " << ERRO_NULLPTR << endl;
        }
        else
            cout << "Erro em Menus::MenuFinal::executar()::Texto*: " << ERRO_NULLPTR << endl;
        
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

    void MenuFinal::desenhar()
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


    void MenuFinal::verificaTeclaPressionada(string tecla)
    {
        if(tecla == "Enter" && !nomeJogador2)
        {
            if(opcoes[3])
                opcoes[3]->setCor(vermelho);
            else
                cout << "Erro em Menus::MenuFinal::verificaTeclaSolta()::Texto*: " << ERRO_NULLPTR << endl;
        }
        else if(tecla == "Enter" && nomeJogador2)
        {
            if(opcoes[4])
                opcoes[4]->setCor(vermelho);
            else
                cout << "Erro em Menus::MenuFinal::verificaTeclaSolta()::Texto*: " << ERRO_NULLPTR << endl;
        }
    }

    void MenuFinal::verificaTeclaSolta(string tecla)
    {
        if(pGEs)
        {
            if(verificaTeclaAlfaNumerica(tecla) && !nomeJogador2)
            {
                if(opcoes[3])
                {
                    nome1 += tecla;
                    opcoes[3]->setInfo(nome1);
                }
                else
                    cout << "Erro em Menus::MenuFinal::verificaTeclaSolta()::Texto*: " << ERRO_NULLPTR << endl;
            }
            else if(verificaTeclaAlfaNumerica(tecla) && pFase->getJogador2() && nomeJogador2)
            {
                if(opcoes[4])
                {
                    nome2 += tecla;
                    opcoes[4]->setInfo(nome2);
                }
                else
                    cout << "Erro em Menus::MenuFinal::verificaTeclaSolta()::Texto*: " << ERRO_NULLPTR << endl;
            }
            else if(tecla == "Enter" && !nomeJogador2)
                nomeJogador2 = true;
            else if(tecla == "Enter" && nomeJogador2)
                pGEs->executarEstado(ranking);
            else if(tecla == "Escape")
                pGEs->executarEstado(menuPrincipal);
        }
        else
            cout << "Erro em Menus::MenuFinal::verificaTeclaSolta(): " << ERRO_NULLPGES << endl;
    }

    void MenuFinal::setpFase(Fases::Fase* pF)
    {
        pFase = pF;

        if(pFase == NULL)
            cout << "Atenção em Menus::MenuFinal::setpFase()::pFase: " << ERRO_NULLPTR << endl;
    }

    const bool MenuFinal::verificaTeclaAlfaNumerica(string tecla)
    {
        return (bool)(tecla.size()==1 && ((tecla[0]>='0' && tecla[0]<='9') ||
                                          (tecla[0]>='A' && tecla[0]<='Z') ||
                                          (tecla[0]>='a' && tecla[0]<='z')));
    }

} // namespace Menus
