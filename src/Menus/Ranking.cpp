#define CAMINHO_RANKING "../dados/ranking.dat"

#include "Ranking.hpp"
#include "Erros.hpp"

using namespace std;

namespace Menus
{
    Ranking::Ranking(idEstados id):
    Estado(id),
    Menu(),
    mapaRegistros()
    {
        //Seta o título
        titulo.setInfo("RANKING");
        titulo.setTamanho(125); //o tamanho muda a caixa de texto
        titulo.setPosicao(200.0, 100.0);
        titulo.setCor(branco);
        
        /* ========================= CARREGAMENTO DO RANKING ============================*/
        
        //objeto que manipula o arquivo
        ifstream arquivo;

        //abertura do arquivo
        arquivo.open(CAMINHO_RANKING, ios::in);

        if(!arquivo)
            cout << "Erro em Menus::Ranking::Ranking(): falha na leitura de arquivo." << endl;

        string nome;
        int pontos;
        
        mapaRegistros.clear();
        
        //Leitura e extração dos dados salvos em arquivo
        while(arquivo >> nome >> pontos)
        {
            

            if(nome != "")
                mapaRegistros.insert(pair<int, string>(pontos, nome));
        }

        arquivo.close();
    }

    Ranking::~Ranking()
    {
        
        cout << "Entrou na destrutora do ranking ======================*********" << endl; 
        
        
        limparOpcoes();

        mapaRegistros.clear();
    }


    void Ranking::executar(const float dT)
    {
        atualizarOpcoes();

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

    void Ranking::desenhar()
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

    void Ranking::inserirRegistro(const int pontos, string nome)
    {
        mapaRegistros.insert(pair<int, string>(pontos, nome));

        /*/*===================== SALVAMENTO DO RANKING ============================ */
        
        //objeto que manipula arquivo;
        ofstream arquivo;

        //abertura do arquivo
        arquivo.open(CAMINHO_RANKING, ios::out);

        if(!arquivo)
            cout << "Erro em Menus::Ranking::Ranking(): falha na leitura de arquivo." << endl;

        map<int, string>::iterator it;

        for(it=mapaRegistros.begin(); it!=mapaRegistros.end(); it++)
        {    
            arquivo << it->second << " " << it->first << endl;
            cout << "SALVANDO NO RANKING " << it->second << " " << it->first << endl;
        }

        arquivo.close();
    }

    void Ranking::atualizarOpcoes()
    {
        limparOpcoes();
        
        multimap<int, string>::reverse_iterator it = mapaRegistros.rbegin();

        int cont = 0;

        string nome, pontos, tracos = "..........................................................................";

        ElementosGraficos::Texto* pOpcao;

        //Pegando os dados do mapa e transformando no texto para o ranking
        while(it!=mapaRegistros.rend() && cont<10)
        {
            //Armazena nome e pontuações em variáveis
            pontos = to_string(it->first);
            nome = it->second;

            //Formata as informações como uma unica string
            for(int i=0; i<(pontos.size()+nome.size()); i++)
                tracos.pop_back();

            tracos.append(pontos);
            nome.append(tracos);

            //Passa essa string como texto da opcao a ser alocada no vetor de opcoes
            pOpcao = NULL;
            pOpcao = new ElementosGraficos::Texto((to_string(cont+1).append(". ")).append(nome));

            if (pOpcao)
                opcoes.push_back(pOpcao);
            else
                cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;

            //Formata o texto
            pOpcao->setTamanho(50);
            pOpcao->setPosicao(200.0, 250.0 + (100.0*(cont+1)));
            pOpcao->setCor(branco);

            tracos = "..........................................................................";
            cont++;
            it++;
        }

        //Opcao final (voltar para o menu principal)
        pOpcao = NULL;
        pOpcao = new ElementosGraficos::Texto("Pressione Esc para voltar ao menu principal.");

        if (pOpcao)
            opcoes.push_back(pOpcao);
        else
            cout << "Erro em Menus::MenuPrincipal::MenuPrincipal()::pOpcao: " << ERRO_ALOCACAO << endl;

        //Formata o texto
        pOpcao->setTamanho(50);
        pOpcao->setPosicao(pGG->getTamanhoJanela().x/2, 250.0 + (100.0*(cont+2)));
        pOpcao->setCor(vermelho);
    }

    void Ranking::limparOpcoes()
    {
        for(int i=0; i<opcoes.size(); i++)
        {
            if(opcoes[i])
                delete opcoes[i];
        }

        opcoes.clear();
    }

    void Ranking::verificaTeclaSolta(string tecla)
    {
        if(tecla == "Escape")
        {
            if(pGEs)
                pGEs->executarEstado(menuPrincipal);
            else
                cout << "Erro em Menus::Ranking::verificaTeclaSolta(): " << ERRO_NULLPGES << endl;
        }
    }

} // namespace Menus
