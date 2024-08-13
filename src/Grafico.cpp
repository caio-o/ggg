/*
 * AUTOR(A): Ana Julia Molinos Leite da Silva (ana-molinos)
 * DATA: 12/08/2024
 * Implementação da classe que permite o gerenciamento dos elementos
 * gráficos usando recursos da biblioteca SFML.
 * */

#pragma once

#include <string.h>

#include "Grafico.hpp"
//DIMENSÕES PROVISÓRIAS
#define ALTURA 500.0
#define LARGURA 500.0

namespace Gerenciadores
{
    float Grafico::dT(0);
    Grafico* Grafico::pGrafico(NULL);

    Grafico::Grafico():
    pJanela(NULL), 
    /* O primeiro argumento (sf::Vector2f((LARGURA/2), (ALTURA/2))) se trata do centro
     * da janela.
     * Já, o segundo (sf::Vector2f(LARGURA, ALTURA)) é o tamanho da janela
     * Ou seja, seta a camêra como a própria janela inicialmente...
     */
    camera(sf::Vector2f((LARGURA/2), (ALTURA/2)), sf::Vector2f(LARGURA, ALTURA)),
    mapaTexturas(),
    mapaFontes(),
    relogio()
    {
        //instancia a janela adequadamente
        pJanela = new sf::RenderWindow(sf::VideoMode(LARGURA, ALTURA), "GGG - Grande Guerra Geométrica");

        //associa a camera à janela
        if(pJanela)
            pJanela->setView(camera);
        
        //garante que as coleções de textura e fontem iniciem vazias
        mapaTexturas.clear();
        mapaFontes.clear();

        //inicializa o relogio zerado
        resetarRelogio();
    }
    
    Grafico::~Grafico()
    {
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

        //desaloca fontes
        if(!mapaFontes.empty())
        {
            map<const char*, sf::Font*>::iterator it;
            sf::Font* pFnt = NULL;

            for(it=mapaFontes.begin(); it!=mapaFontes.end(); it++)
            {
                pFnt = it->second;
                if(pFnt)
                    delete pFnt;

                pFnt = NULL;
            }

            mapaFontes.clear();
        }

        dT = -1.0;

        //desaloca o ponteiro para o gerenciador
        if(pGrafico)
            delete pGrafico;

        pGrafico = NULL;
    }

    /* 
     * Se o ponteiro para o gerenciador for nulo, ele instancia um novo objeto do
     * tipo Gerenciador Gráfico e o retorna. Caso contrário, retorna o endereço
     * do gerenciador já existente. Isso garante que exista apenas um Gerenciador
     * Gráfico instanciado no programa, característica do padrão de projeto
     * Singleton.
     */
    Grafico* Grafico::getGrafico()
    {
        if(pGrafico == NULL)
            pGrafico = new Gerenciadores::Grafico();
            
        return pGrafico;
    }
    
    //Retorna um ponteiro para a janela do gerenciador gráfico
    sf::RenderWindow* Grafico::getJanela() const
    {
        if(pJanela)
            return pJanela;

        cout << "Erro de gerenciamento gráfico: janela de visualizacao nao alocada!" << endl;
        exit(1);
    }
    
    //Renderiza um corpo na janela
    void Grafico::renderizar(sf::RectangleShape* corpo)
    {
        if(pJanela && corpo)
            pJanela->draw(*corpo);
            /* P.s: draw(const sf::Drawable &drawable, const sf...)
             * o primeiro argumento é passado por referencia escondida,
             * ou seja, ele espera receber um objeto do tipo drawable, e não um ptr...
             */
    }
    
    //Renderiza texto na janela
    void Grafico::renderizar(sf::Text* texto)
    {
        if(pJanela && texto)
            pJanela->draw(*texto);
    }
    
    //Mostra na janela todos os objetos renderizados
    void Grafico::mostrar()
    {
        if(pJanela)
            pJanela->display();
    }
    
    //Limpa a janela
    void Grafico::limpar()
    {
        if(pJanela)
            pJanela->clear();
    }
    
    //Retorna true se a janela estiver aberta
    const bool Grafico::janelaAberta() const
    {
        if(pJanela)
            return pJanela->isOpen();

        cout << "Erro de gerenciamento gráfico: janela de visualizacao nao alocada!" << endl;
        exit(1);
    }
    
    //Encerra a janela
    void Grafico::fecharJanela()
    {
        if(pJanela)
            pJanela->close();
    }
    
    /* 
     * Ajusta o tamanho da janela e da camera conforme largura e 
     * altura passadas por parâmetro por meio da variavel do tipo 
     * Coordenada
     */
    void Grafico::setTamanhoJanela(const Coordenada<float> tam)
    {
        sf::Vector2u dimensao(tam.x, tam.y);

        if(pJanela)
        {
            pJanela->setSize(dimensao);
            setTamanhoCamera(tam);
        }
    }
    
    //Retorna o tamanho da janela por meio de variavel do tipo Coordenada
    const Coordenada<float> Grafico::getTamanhoJanela() const
    {
        if(pJanela)
        {
            sf::Vector2u dimensao(pJanela->getSize());
            return Coordenada<float>((float)dimensao.x, (float)dimensao.y);
        }

        cout << "Erro de gerenciamento gráfico: janela de visualizacao nao alocada!" << endl;
        exit(1);
    }
    
    /*
     * Retorna a posição superior esquerda da janela
     * Obs.: analisar se é a posição mais conveniente para nosso interesse durante
     * o desenvolvimento.
     * */
    const Coordenada<float> Grafico::getPosicaoInicial() const
    {
        if(pJanela)
        {
            Coordenada<float> posicao((float)pJanela->getPosition().x,(float)pJanela->getPosition().y);
            
            posicao -= Coordenada<float>((float)pJanela->getSize().x/2.0, (float)pJanela->getSize().y/2.0);

            return posicao;
        }

        cout << "Erro de gerenciamento gráfico: janela de visualizacao nao alocada!" << endl;
        exit(1);
    }
    
    /* Atualiza a posição do centro da camera para o centro (da janela).
     * Obs.: analisar a utilidade desse método. Talvez seja mais util ter um método
     * que atualiza a posição para uma posição desejada que é passado como argumento.*/
    void Grafico::centralizarCamera()
    {
        sf::Vector2f centro(pJanela->getSize());

        camera.setCenter(centro.x/2, centro.y/2);
    }

    /* Atualiza o tamanho da camera conforme dimensões passadas por meio da variavel
     * do tipo Coordenada<float>
     */
    void Grafico::setTamanhoCamera(Coordenada<float> tam)
    {
        camera.setSize(tam.x, tam.y);
    }
    
    //Retorna a camera
    sf::View Grafico::getCamera() const
    {
        return camera;
    }
    
    /* 
     * Procura se a textura requerida já foi carregada anteriormente e a retorna.
     * Caso não a encontre, carrega e retorna a nova textura.
     * */
    sf::Texture* Grafico::carregarTextura(const char* caminho)
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
                    
                    cout << "Erro de gerenciamento grafico: textura correspondente ao caminho "
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

        cout << "Erro de gerenciamento grafico: textura nao alocada!" << endl;
        exit(1);
    }
    
    /* 
     * Procura se a fonte requerida já foi carregada anteriormente e a retorna.
     * Caso não a encontre, carrega e retorna a nova fonte.
     * */
    sf::Font* Grafico::carregarFonte(const char* caminho)
    {
        if(!mapaFontes.empty())
        {
            map<const char*, sf::Font*>::iterator it;

            for(it=mapaFontes.begin(); it!=mapaFontes.end(); it++)
            {
                if(!strcmp(caminho, it->first))
                {
                    if(it->second)
                        return it->second;

                    cout << "Erro de gerenciamento grafico: textura correspondente ao caminho "
                            << caminho << " nao esta alocada adequadamente!" << endl;

                    exit(1);
                }
            }
        }

        sf::Font* pFnt = new sf::Font();

        if(pFnt)
        {
            if(!pFnt->loadFromFile(caminho))
            {
                cout << "Erro ao carregar arquivo de textura!" << endl;
                exit(1);
            }

            mapaFontes.insert(std::pair<const char*,sf::Font*>(caminho, pFnt));

            return pFnt;
        }

        cout << "Erro de gerenciamento grafico: textura nao alocada!" << endl;
        exit(1); 
    }
    
    //Reinicia a contagem de tempo
    void Grafico::resetarRelogio()
    {
        relogio.restart();
    }
    
    //Retorna quanto tempo passsou (em segundos) desde que o relógio foi iniciado.
    const float Grafico::getTempo() const
    {
        relogio.getElapsedTime().asSeconds();
    }

}