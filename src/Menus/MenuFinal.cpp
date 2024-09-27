/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe derivada MenuFinal, responsável informar se os jogadores morreram
 *             ou completaram a fase, quais foram suas pontuações, e por possibilitar o registro do
 *             nome e pontuação no ranking, ou o retorno ao menu principal.
 */

#include "MenuFinal.hpp"
#include "Ranking.hpp"

namespace Menus
{
    MenuFinal::MenuFinal(idEstados id):
    Estado(id),
    Menu(),
    pFase(NULL),
    nomeJogador2(false),
    nome1(),
    nome2(),
    subtitulo1(),
    subtitulo2(),
    doisJogadores(false)
    {        
        //Seta o título
        titulo.setInfo("GAME OVER!");
        titulo.setTamanho(300);
        titulo.setPosicao(200.0, 10.0);
        titulo.setCor(branco);

        //Seta o subtitulo parte 1
        subtitulo1.setInfo("Digite seu nome e pressione Enter para registrar sua pontuacao no ranking");
        subtitulo1.setTamanho(60);
        subtitulo1.setPosicao(200.0, 400.0);
        subtitulo1.setCor(branco);

        //Aloca subtitulo parte 2
        subtitulo2.setInfo("ou pressione Esc para retornar ao menu principal.");
        subtitulo2.setTamanho(60);
        subtitulo2.setPosicao(200.0, 450.0);
        subtitulo2.setCor(branco);
        
        //Aloca pontuação jogador1 - 0
        Texto* pTexto  = NULL;
        pTexto = new Texto("Pontuacao do jogador 1: ");

        if(pTexto)
            opcoes.push_back(pTexto);
        else
            cout << "Erro em Menus::MenuFinal::MenuFinal()::Texto*: " << ERRO_ALOCACAO << endl;

        //Aloca nome do jogador1 - 1
        pTexto  = NULL;
        pTexto = new Texto("Nome do jogador 1: ");

        if(pTexto)
            opcoes.push_back(pTexto);
        else
            cout << "Erro em Menus::MenuFinal::MenuFinal(): Texto*: " << ERRO_ALOCACAO << endl;

        if(doisJogadores)
        {
            //Aloca pontuação do jogador2 - 2
            pTexto  = NULL;
            pTexto = new Texto("Pontuacao do jogador 2: ");

            if(pTexto)
                opcoes.push_back(pTexto);
            else
                cout << "Erro em Menus::MenuFinal::MenuFinal()::Texto*: " << ERRO_ALOCACAO << endl;

            //Aloca nome do jogador2 - 3
            pTexto  = NULL;
            pTexto = new Texto("Nome do jogador 2: ");

            if(pTexto)
                opcoes.push_back(pTexto);
            else
                cout << "Erro em Menus::MenuFinal::MenuFinal(): Texto*: " << ERRO_ALOCACAO << endl;
        }

        //Percorre o vetor ajustando o texto das opções
        ajustaTextoVetor();
    }

    MenuFinal::~MenuFinal()
    {
        for(int i=0; i<(int)opcoes.size(); i++)
        {
            if(opcoes[i])
                delete opcoes[i];
        }

        opcoes.clear();
    }

    
    //Informa se os jogadores morreram ou completaram a fase, quais foram suas pontuações, e possibilita
    //o registro do nome e pontuação no ranking ou o retorno ao menu principal
    void MenuFinal::executar(const float dT)
    {
        //Reinicializa as strings e booleano referentes ao nome dos jogadores
        nome1 = "";
        nome2 = "";
        nomeJogador2 = false;
        
        //Atualiza as opcoes de texto
        atualizaVetorOpcoes();

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

        //Limpa os nomes dos jogadores
        if(opcoes[1])
            opcoes[1]->setInfo("Nome do jogador 1: ");
        else
            cout << "Erro em Menus::MenuPause::executar()::Texto*: " << ERRO_NULLPTR << endl;   

        if(doisJogadores)
        {
            if(opcoes[3])
                opcoes[3]->setInfo("Nome do jogador 2: ");
            else
                cout << "Erro em Menus::MenuPause::executar()::Texto*: " << ERRO_NULLPTR << endl;   
        }

        //Seta o texto que mostra a pontuação dos jogadores
        if(pFase)
        {
            string textoPontuacao = "Pontuacao do jogador 1: ";
            if(pFase->getJogador1())
                textoPontuacao += to_string(pFase->getJogador1()->getPontos());
            else
                cout << "Erro em Menus::MenuFinal::executar()::Jogador*: " << ERRO_NULLPTR << endl;

            if(opcoes[0])
                opcoes[0]->setInfo(textoPontuacao);
            else
                cout << "Erro em Menus::MenuFinal::executar()::Texto*: " << ERRO_NULLPTR << endl;

            if(doisJogadores)
            {
                textoPontuacao = "Pontuacao do jogador 2: ";
                if(pFase->getJogador2())
                    textoPontuacao += to_string(pFase->getJogador2()->getPontos());
                else
                   cout << "Erro em Menus::MenuFinal::executar()::Jogador*: " << ERRO_NULLPTR << endl; 

                if(opcoes[2])
                    opcoes[2]->setInfo(textoPontuacao);
                else
                    cout << "Erro em Menus::MenuFinal::executar()::Texto*: " << ERRO_NULLPTR << endl;
            }
        
        }
        else
            cout << "Erro em Menus::MenuFinal::executar()::Fase*: " << ERRO_NULLPTR << endl;

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

    //Renderiza as opções na tela
    void MenuFinal::desenhar()
    {
        titulo.renderizar();
        subtitulo1.renderizar();
        subtitulo2.renderizar();

        for(int i=0; i<(int)opcoes.size(); i++)
        {
            if(opcoes[i])
                opcoes[i]->renderizar();
            else
                cout << "Erro em Menus::MenuPause::desenhar()::Texto*: " << ERRO_NULLPTR << endl;
        }
    }

    //Destaca a tecla pressionada com a cor vermelho    
    void MenuFinal::verificaTeclaPressionada(string tecla)
    {
        if(tecla == "Enter" && !nomeJogador2)
        {
            if(opcoes[1])
                opcoes[1]->setCor(vermelho);
            else
                cout << "Erro em Menus::MenuFinal::verificaTeclaSolta()::Texto*: " << ERRO_NULLPTR << endl;
        }
        else if(tecla == "Enter" && nomeJogador2)
        {
            if(opcoes[3])
                opcoes[3]->setCor(vermelho);
            else
                cout << "Erro em Menus::MenuFinal::verificaTeclaSolta()::Texto*: " << ERRO_NULLPTR << endl;
        }
    }

    //Chama a ação pertinente a tecla solta
    void MenuFinal::verificaTeclaSolta(string tecla)
    {
        cout <<"Entrou em verificaTeclaSolta()" << endl;
        if(pGEs)
        {
            //Se a entrada for uma tecla alfa numerica e não estiver preenchendo o nome do jogador 2...
            if((verificaTeclaAlfaNumerica(tecla) || tecla == "-") && !nomeJogador2)
            {
                //Atualiza a string que armazena o nome do Jogador 1 e o texto da tela
                if(opcoes[1])
                {
                    nome1 += tecla;
                    opcoes[1]->setInfo(opcoes[1]->getInfo().append(tecla));
                }
                else
                    cout << "Erro em Menus::MenuFinal::verificaTeclaSolta()::Texto*: " << ERRO_NULLPTR << endl;
            }
            
            //Se a entrada for uma tecla alfa numerica e estiver preenchendo o nome do jogador 2...
            else if((verificaTeclaAlfaNumerica(tecla) || tecla == "-") && doisJogadores && nomeJogador2)
            {
                //Atualiza a string que armazena o nome do Jogador 2 e o texto da tela
                if(opcoes[3])
                {
                    nome2 += tecla;
                    opcoes[3]->setInfo(opcoes[3]->getInfo().append(tecla));
                }
                else
                    cout << "Erro em Menus::MenuFinal::verificaTeclaSolta()::Texto*: " << ERRO_NULLPTR << endl;
            }
            
            //Se a entrada for "apagar" e não estiver preenchendo o nome do jogador 2...
            else if(tecla == "Apagar" && !nomeJogador2)
            {
                //Remove o ultimo caractere da string que armazena o nome do Jogador 1 e do texto na tela
                if(nome1!="")
                {
                    nome1.pop_back();
                    if(opcoes[1])
                        opcoes[1]->setInfo("Nome do jogador 1: " + nome1);
                }
            }

            //Se a entrada for "apagar" e estiver preenchendo o nome do jogador 2...
            else if(tecla == "Apagar" && nomeJogador2)
            {
                //Remove o ultimo caractere da string que armazena o nome do Jogador 2 e do texto na tela  
                if(nome2!="")
                {
                    nome2.pop_back();
                    if(opcoes[3])
                        opcoes[3]->setInfo("Nome do jogador 2: " + nome2);
                }
            }

            //Se teclar enter enquanto digita o nome do jogador 1 e houver 2 jogadores, passa para 
            //o próximo nome
            else if(tecla == "Enter" && doisJogadores && !nomeJogador2)
                nomeJogador2 = true;

            //Se teclar enter enquanto digita o nome do jogador 2 (se houver 2 jogadores) OU
            //se teclar enter enquanto digita o nome do jogador 1, passa as infos para o ranking
            //e pede para executá-lo
            else if((tecla == "Enter" && doisJogadores && nomeJogador2) ||
                    (tecla == "Enter" && !doisJogadores))
            {
                //Insere os nomes e pontuações dos jogadores no ranking
                if(pFase)
                {
                    if(nome1!="" && pFase->getJogador1())
                        static_cast<Ranking*>(pGEs->getEstado(ranking))->inserirRegistro(pFase->getJogador1()->getPontos(), nome1);
                    else
                        cout << "Erro em Menus::MenuFinal::verificaTeclaSolta()::Jogador*: " << ERRO_NULLPTR << endl;

                    if(nome2!="" && pFase->getJogador2())
                        static_cast<Ranking*>(pGEs->getEstado(ranking))->inserirRegistro(pFase->getJogador2()->getPontos(), nome2);
                    else
                        cout << "Erro em Menus::MenuFinal::verificaTeclaSolta()::Jogador*: " << ERRO_NULLPTR << endl;
                }
                else
                    cout << "Erro em Menus::MenuFinal::verificaTeclaSolta()::Fase*: " << ERRO_NULLPTR << endl;

                pGEs->executarEstado(ranking);
            }

            //Se teclar esc, volta ao menu principal
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

    //Retornar true se a entrada é uma caracter alfanumerico (tanto letras maiúsculas, quanto minúsculas)
    const bool MenuFinal::verificaTeclaAlfaNumerica(string tecla)
    {
        
        return (bool)(tecla.size()==1 && ((tecla[0]>='0' && tecla[0]<='9') ||
                                          (tecla[0]>='A' && tecla[0]<='Z') ||
                                          (tecla[0]>='a' && tecla[0]<='z')));
    }

    void MenuFinal::setDoisJogadores(const bool b)
    {
        doisJogadores = b;
    }

    /*Atualiza o vetor de opcoes do menu conforme a quantidade de jogadores selecionada no menu principal*/
    void MenuFinal::atualizaVetorOpcoes()
    {
        //Se o vetor de opcoes só tem as opcoes para jogador 1 mas o jogo foi setado para 2 jogadores
        if(doisJogadores && opcoes.size() == 2)
        {
            //Aloca pontuação do jogador2 - 2
            Texto* pTexto  = NULL;
            pTexto = new Texto("Pontuacao do jogador 2: ");

            if(pTexto)
                opcoes.push_back(pTexto);
            else
                cout << "Erro em Menus::MenuFinal::atualizaVetorOpcoes()::Texto*: " << ERRO_ALOCACAO << endl;

            //Aloca nome do jogador2 - 3
            pTexto  = NULL;
            pTexto = new Texto("Nome do jogador 2: ");

            if(pTexto)
                opcoes.push_back(pTexto);
            else
                cout << "Erro em Menus::MenuFinal::AtualizaVetorOcoes(): Texto*: " << ERRO_ALOCACAO << endl;
            
            ajustaTextoVetor();
        }
        //Se o vetor de opcoes tem as opcoes para ambos os jogadores mas o jogo foi setado para 1 jogador
        else if(!doisJogadores && opcoes.size() == 4)
        {
            //Deleta opcao referente a pontuacao do jogador 2
            if(opcoes[2])
                delete opcoes[2];
            else
                cout << "Erro em Menus::MenuFinal::AtualizaVetorOcoes(): Texto*: " << ERRO_NULLPTR << endl;

            //Deleta opcao referente ao nome do jogador 2
            if(opcoes[3])
                delete opcoes[3];
            else
                cout << "Erro em Menus::MenuFinal::AtualizaVetorOcoes(): Texto*: " << ERRO_NULLPTR << endl;

            //Remove do vetor
            opcoes.pop_back();
            opcoes.pop_back();
        }
    }

    //Percorre o vetor para ajustar o texto
    void MenuFinal::ajustaTextoVetor()
    {
        for(int i=0; i<(int)opcoes.size(); i++)
        {
            if(opcoes[i])
            {
                opcoes[i]->setTamanho(75);
                opcoes[i]->setPosicao(200.0, 400.0 + (200.0*(i+1)));
                opcoes[i]->setCor(branco);
            }
            else
                cout << "Erro em Menus::MenuPause::ajustaTextoVetor()::Texto*: " << ERRO_NULLPTR << endl; 
        }
    }

} // namespace Menus
