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
            }

            //Configura a posição do Corpo
            pCorpo->setPosition(tamanho.x, tamanho.y);

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
    void Forma::setTextura(const char* caminho)
    {
        //Pede para o gerenciador gráfico carregar a textura
        sf::Texture* pAux = NULL;
        pAux = pGerenciadorGrafico->carregarTextura(caminho);
        
        if(pAux)
            pTextura = pAux;
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
        if(pCorpo)
            pGerenciadorGrafico->renderizar(pCorpo);
        else
            cout << "Erro em ElementosGraficos::Forma::renderizar(): " << ERRO_SET_NULLPTR << endl;
    }

} // namespace ElementosGraficos
