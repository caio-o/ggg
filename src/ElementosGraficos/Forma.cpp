/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe responsável por conter os métodos relacionados a manipulação de 
 *             formas (como mover, redimensionar, animar e etc). Essa classe vai utilizar os recursos 
 *             disponíveis da biblioteca gráfica SFML, permitindo maior desacoplamento.
 */

#include "Forma.hpp"
#include "Erros.hpp"
#include "string.h"

#include <iostream>
using namespace std;

namespace ElementosGraficos
{
    Gerenciadores::GerenciadorGrafico* Forma::pGerenciadorGrafico(Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico());
    
    Forma::Forma(Coordenadas::Vetor2f posicao, Coordenadas::Vetor2f tamanho, const char* caminhoText, float escala):
    pTextura(NULL),
    pCorpo(NULL)
    {
        //Instancia um novo Corpo
        pCorpo = new sf::RectangleShape(sf::Vector2f(tamanho.x, tamanho.y));

        if(pCorpo)
        {
            if(strcmp(caminhoText, ""))
            {
                //Pede para o gerenciador gráfico carregar a textura
                pTextura = pGerenciadorGrafico->carregarTextura(caminhoText);
                
                //Passa a textura para o Corpo
                pCorpo->setTexture(pTextura);

                //Faz o corpo se posicionar pelo seu centro, nao pelo seu canto superior esquerdo.
                pCorpo->setOrigin(pCorpo->getSize() / 2.f);
            }

            //Configura a posição do Corpo
            pCorpo->setPosition(posicao.x, posicao.y);

            //Configura a escala do Corpo
            pCorpo->setScale(escala, escala);
        }
        else
            cout << "Erro em ElementosGraficos::Forma::Forma() com pCorpo: " << ERRO_SET_NULLPTR << endl;
    }

    Forma::~Forma()
    {
        //Se houver corpo alocado, o desaloca
        if(pCorpo)
            delete pCorpo;

        pCorpo = NULL;

        //Não desaloca a textura pois isso é feito pelo gerenciador gráfico
        pTextura = NULL;
    }

    /*
     * Configura uma nova textura para a forma. Se a alocação da textura pelo Gerenciador Gráfico 
     * falhar, o ponteiro para a textura não é atualizado, retornando mensagem de erro.
     */
    void Forma::setTextura(const char* caminho, const bool resetarTamanho)
    {
        //Pede para o gerenciador gráfico carregar a textura
        sf::Texture* pAux = NULL;
        pAux = pGerenciadorGrafico->carregarTextura(caminho);
        
        if(pAux)
        {
            pTextura = pAux;
            pCorpo->setTexture(pTextura, resetarTamanho);
            pCorpo->setOrigin(pCorpo->getSize() / 2.f);
        }
        else
            cout << "Erro em ElementosGraficos::Forma::setTextura(): textura não atualizada!" << endl;
    }

    sf::RectangleShape* Forma::getpCorpo() const
    {
        if(pCorpo == NULL)
            cout << "Erro em ElementosGraficos::Forma::getpCorpo(): " << ERRO_RETURN_NULLPTR << endl;
        return pCorpo;
    }

    //Configura a nova posição da forma, possibilitando movimento.
    void Forma::atualizar(Coordenadas::Vetor2f posicao)
    {
        if(pCorpo)
            pCorpo->setPosition(posicao.x, posicao.y);
        else
            cout << "Erro em ElementosGraficos::Forma::atualizar(): " << ERRO_SET_NULLPTR << endl;
    }

    //Renderiza a forma por meio do Gerenciador Gráfico.
    void Forma::renderizar()
    {
        //cout << "Forma::renderizar()" << endl;
        
        if(pCorpo)
            pGerenciadorGrafico->renderizar(pCorpo);
        else
            cout << "Erro em ElementosGraficos::Forma::renderizar(): " << ERRO_SET_NULLPTR << endl;
    }

    void Forma::setGerenciadorGrafico()
    {
        Forma::pGerenciadorGrafico = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
    }

    void Forma::setEscala (float escala)
    {
        if(escala = 0.f) { escala = 1.f; }
        pCorpo->setScale(escala, escala);
    }

    void Forma::setEscala (float escalaX, float escalaY)
    {
        if(escalaX == 0.f) { escalaX = 1.f; }
        if(escalaY == 0.f) { escalaY = 1.f; }
        pCorpo->setScale(escalaX, escalaY);
    }

    void Forma::setTamanho   (const float x, const float y)
    {
        pCorpo->setSize (sf::Vector2f(x, y));

        pCorpo->setOrigin((pCorpo->getSize().x)/2, (pCorpo->getSize().y)/2); // Centraliza a origem do shape de acordo com o novo tamanho.

    }
} // namespace ElementosGraficos
