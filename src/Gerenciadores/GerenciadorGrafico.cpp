/*
 * AUTOR(A): Ana Julia Molinos Leite da Silva (ana-molinos)
 * DATA: 12/08/2024
 * Implementação da classe que permite o gerenciamento dos elementos
 * gráficos usando recursos da biblioteca SFML.
 * */

#include <string.h>

#include "ElementosGraficos/Forma.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Erros.hpp"

//DIMENSÕES PROVISÓRIAS
#define ALTURA_JANELA 720.0
#define LARGURA_JANELA 1290.0

namespace Gerenciadores
{
    float GerenciadorGrafico::dT(0);
    GerenciadorGrafico* GerenciadorGrafico::pGerenciadorGrafico(NULL);

    GerenciadorGrafico::GerenciadorGrafico():
    pJanela(NULL), 
    /* camera(centro, tamanho) //(o Caio seta a camera como 2x a janela)
     * O primeiro argumento (sf::Vector2f((LARGURA/2), (ALTURA_JANELA_JANELA/2))) se trata do centro
     * da janela.
     * Já, o segundo (sf::Vector2f(LARGURA, ALTURA_JANELA)) é o tamanho da janela
     * Ou seja, seta a camêra como a própria janela inicialmente...
     */
    camera(sf::Vector2f((LARGURA_JANELA), (ALTURA_JANELA)), sf::Vector2f(LARGURA_JANELA*2, ALTURA_JANELA*2)),
    mapaTexturas(),
    pFonte(NULL),
    relogio()
    {
        //instancia a janela adequadamente
        pJanela = new sf::RenderWindow(sf::VideoMode(LARGURA_JANELA, ALTURA_JANELA), "GGG - Grande Guerra Geometrica");
        //associa a camera à janela
        if(pJanela)
            pJanela->setView(camera);
        else
        {
            cout << "GerenciadorGrafico::GerenciadorGrafico: " << ERRO_ALOCACAO << endl;
            enterFechar();
        }

        //garante que as coleções de textura e fontem iniciem vazias
        mapaTexturas.clear();

        //Aloca espaço para a fonte
        pFonte = new sf::Font();

        if(pFonte == NULL)
            cout << "Erro em Gerenciadores::GerenciadorGrafico::GerenciadorGrafico()::pFonte: " << ERRO_ALOCACAO << endl;
        
        //inicializa o relogio zerado
        resetarRelogio();
    }
    
    GerenciadorGrafico::~GerenciadorGrafico()
    {

        cout << "ENTRA NA DESTRUTORA DO GG" << endl;
        //desaloca a janela
        if(pJanela)
            delete pJanela;
        
        pJanela = NULL;

        //desaloca texturas
        if(!mapaTexturas.empty())
        {
            map<const char*, sf::Texture*>::iterator it;
            sf::Texture* pTxt = NULL;

            for(it=mapaTexturas.begin(); it!=mapaTexturas.end(); it++)
            {
                pTxt = it->second;
                if(pTxt)
                    delete pTxt;

                pTxt = NULL;                
            }
            
            mapaTexturas.clear();
        }

        dT = -1.0;

        //desaloca o ponteiro para o gerenciador
        /*if(pGerenciadorGrafico)
            delete pGerenciadorGrafico;*/

        pGerenciadorGrafico = NULL;

        if(pFonte)
            delete pFonte;

        pFonte = NULL;

        cout << "SAI DA DESTRUTORA DO GG" << endl;
    }

    /* 
     * Se o ponteiro para o gerenciador for nulo, ele instancia um novo objeto do
     * tipo Gerenciador Gráfico e o retorna. Caso contrário, retorna o endereço
     * do gerenciador já existente. Isso garante que exista apenas um Gerenciador
     * Gráfico instanciado no programa, característica do padrão de projeto
     * Singleton.
     */
    GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico()
    {
        if(pGerenciadorGrafico == NULL)
            pGerenciadorGrafico = new Gerenciadores::GerenciadorGrafico();
            
        if (pGerenciadorGrafico)
        {
            return pGerenciadorGrafico;
        }
        else
        {
            enterFechar(); // contem exit(1)
        }
    }
    
    //Retorna um ponteiro para a janela do gerenciador gráfico
    sf::RenderWindow* GerenciadorGrafico::getJanela() const
    {
        if(pJanela)
            return pJanela;

        cout << "Erro em Gerenciadores::GerenciadorGrafico::getJanela()::pJanela: " << ERRO_NULLPTR << endl;
        exit(1);
    }
    
    //Renderiza um corpo na janela
    void GerenciadorGrafico::renderizar(sf::RectangleShape* corpo)
    {
        //cout << "GerenciadorGrafico::renderizar()" << endl;
        
        if(pJanela && corpo)
            pJanela->draw(*corpo);
        else
            cout << "RectangleShape inexistente." << endl;
            /* P.s: draw(const sf::Drawable &drawable, const sf...)
             * o primeiro argumento é passado por referencia escondida,
             * ou seja, ele espera receber um objeto do tipo drawable, e não um ptr...
             */
    }
    void GerenciadorGrafico::renderizar(sf::Shape* corpo)
    {
        if(pJanela && corpo)
            pJanela->draw(*corpo);
            /* P.s: draw(const sf::Drawable &drawable, const sf...)
             * o primeiro argumento é passado por referencia escondida,
             * ou seja, ele espera receber um objeto do tipo drawable, e não um ptr...
             */
    }

    //Renderiza texto na janela
    void GerenciadorGrafico::renderizar(sf::Text* texto)
    {
        if(pJanela && texto)
            pJanela->draw(*texto);
        else
            cout << "Erro em Gerenciadores::GerenciadorGrafico::renderizar()::texto e/ou pJanela: " << ERRO_NULLPTR << endl;
    }
    
    //Mostra na janela todos os objetos renderizados
    void GerenciadorGrafico::mostrar()
    {
        if(pJanela)
            pJanela->display();
        else
            cout << "Erro em Gerenciadores::GerenciadorGrafico::mostar()::pJanela: " << ERRO_NULLPTR << endl;
    }
    
    //Limpa a janela
    void GerenciadorGrafico::limpar()
    {
        if(pJanela)
            pJanela->clear();
        else
            cout << "Erro em Gerenciadores::GerenciadorGrafico::mostar()::pJanela: " << ERRO_NULLPTR << endl;
    }
    
    //Retorna true se a janela estiver aberta
    const bool GerenciadorGrafico::janelaAberta() const
    {
        if(pJanela)
            return pJanela->isOpen();

        cout << "Erro em Gerenciadores::GerenciadorGrafico::janelaAberta()::pJanela: " << ERRO_NULLPTR << endl;
        exit(1);
    }
    
    //Encerra a janela
    void GerenciadorGrafico::fecharJanela()
    {
        if(pJanela)
            pJanela->close();
        else
            cout << "Erro em Gerenciadores::GerenciadorGrafico::fecharJanela()::pJanela: " << ERRO_NULLPTR << endl;
    }
    
    /* 
     * Ajusta o tamanho da janela conforme dimensões na variável tam
     */
    void GerenciadorGrafico::setTamanhoJanela(const Coordenadas::Vetor2f tam)
    {
        sf::Vector2u dimensao(tam.x, tam.y);

        if(pJanela)
        {
            pJanela->setSize(dimensao);
            cout << "Tamanho da janela: " << tam.x << ", " << tam.y << endl;
        }
        else
            cout << "Erro em Gerenciadores::GerenciadorGrafico::setTamanhoJanela()::pJanela: " << ERRO_NULLPTR << endl;
    }

    //Retorna o tamanho da janela por meio de variavel do tipo Coordenada
    const Coordenadas::Vetor2f GerenciadorGrafico::getTamanhoJanela() const
    {
        if(pJanela)
        {
            sf::Vector2u dimensao(pJanela->getSize());
            return Coordenadas::Vetor2f((float)dimensao.x, (float)dimensao.y);
        }

        cout << "Erro em Gerenciadores::GerenciadorGrafico::getTamanhoJanela()::pJanela: " << ERRO_NULLPTR << endl;
        exit(1);
    }
    
    /*
     * Retorna o centro da camera
     */
    const Coordenadas::Vetor2f GerenciadorGrafico::getCentroCamera() const
    {
        return Coordenadas::Vetor2f(camera.getCenter().x, camera.getCenter().y);
    }
    
    /* Atualiza a posição do centro da camera.*/
    void GerenciadorGrafico::centralizarCamera(Coordenadas::Vetor2f centro)
    {
        camera.setCenter(centro.x, centro.y);

        cout << "Centro da camera: " << centro.x << ", " << centro.y << endl;
    }

    /* Atualiza o tamanho e o centro da câmera conforme dimensões na variável tam.
     */
    void GerenciadorGrafico::setTamanhoCamera(Coordenadas::Vetor2f tam)
    {
        camera.setSize(tam.x, tam.y);
        camera.setCenter(tam.x/2, tam.y/2);

        cout << "Tamanho da camera: " << tam.x << ", " << tam.y << endl;
        cout << "Centro da camera: " << tam.x/2 << ", " << tam.y/2 << endl;
    }
    
    //Retorna a camera
    sf::View GerenciadorGrafico::getCamera() const
    {
        return camera;
    }
    
    /* 
     * Procura se a textura requerida já foi carregada anteriormente e a retorna.
     * Caso não a encontre, carrega e retorna a nova textura.
     * */
    sf::Texture* GerenciadorGrafico::carregarTextura(const char* caminho)
    {
        //Procura se a textura já existe no mapa de texturas
        if(!mapaTexturas.empty())
        {
            map<const char*, sf::Texture*>::iterator it;

            for(it=mapaTexturas.begin(); it!=mapaTexturas.end(); it++)
            {
                //caso encontre o caminho procurado, retorna a textura correspondente
                if (!strcmp(caminho, it->first))
                {
                    if(it->second)
                        return it->second;
                    
                    cout << "Erro de gerenciamento GerenciadorGrafico: textura correspondente ao caminho "
                            << caminho << " nao alocada adequadamente!" << endl;

                    exit(1);
                }   
            }
        }

        //Se não encontrar a textura no mapa, cria e carrega uma nova:

        //Cria a textura
        sf::Texture* pTxt = new sf::Texture();

        if(pTxt)
        {
            //Carrega a imagem na textura
            if(!pTxt->loadFromFile(caminho))
            {
                cout << "Erro ao carregar arquivo de textura!" << endl;
                exit(1);
            }

            /* 
             * Adiciona a textura criada no mapa de texturas, linkando caminho e
             * textura.
             */
            mapaTexturas.insert(std::pair<const char*, sf::Texture*>(caminho, pTxt));

            //retorna a textura criada
            return pTxt;
        }

        cout << "Erro de gerenciamento GerenciadorGrafico: textura nao alocada!" << endl;
        exit(1);
    }
    
    /* 
     * Carrega a fonte dos textos
     * */
    sf::Font* GerenciadorGrafico::carregarFonte(const char* caminho)
    {
        if(!(pFonte->loadFromFile(caminho)))
            cout << "Erro em Gerenciadores::GerenciadorGrafico::carregarFonte(): carregamento de fonte falhou!" << endl;
        
        return pFonte;
    }
    
    //Reinicia a contagem de tempo
    void GerenciadorGrafico::resetarRelogio()
    {
        relogio.restart();
    }
    
    //Retorna quanto tempo passsou (em segundos) desde que o relógio foi iniciado.
    const float GerenciadorGrafico::getTempo() const
    {
        return relogio.getElapsedTime().asSeconds();
    }

    void GerenciadorGrafico::renderizar(ElementosGraficos::Forma *pForma)
    {
        //cout << "GerenciadorGrafico::renderizar()" << endl;
        
        if(pJanela && pForma && pForma->getpCorpo())
            pJanela->draw(*(pForma->getpCorpo()));
        else
            cout << "RectangleShape inexistente." << endl;
            /* P.s: draw(const sf::Drawable &drawable, const sf...)
             * o primeiro argumento é passado por referencia escondida,
             * ou seja, ele espera receber um objeto do tipo drawable, e não um ptr...
             */
    }
}
