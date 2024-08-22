/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe responsável por conter os métodos relacionados a manipulação de 
 *             formas (como mover, redimensionar, animar e etc). Essa classe vai utilizar os recursos 
 *             disponíveis da biblioteca gráfica SFML, permitindo maior desacoplamento.
 */

#include "Forma.hpp"
#include "Erros.hpp"

#include <iostream>
using namespace std;

namespace ElementosGraficos
{
    Gerenciadores::GerenciadorGrafico* Forma::pGerenciadorGrafico(Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico());
    
    Forma::Forma(const char* caminhoText, Coordenada::Vetor2f posicao, Coordenada::Vetor2f tamanho, float escala):
    pTextura(NULL),
    pCorpo(NULL)
    {
        //Pede para o gerenciador gráfico carregar a textura
        pTextura = pGerenciadorGrafico->carregarTextura(caminhoText);

        //Instancia um novo Corpo
        pCorpo = new sf::RectangleShape(sf::Vector2f(tamanho.x, tamanho.y));

        //Passa a textura para o Corpo
        pCorpo->setTexture(pTextura);

        //Configura a posição do Corpo
        pCorpo->setPosition(tamanho.x, tamanho.y);

        //Configura a escala do Corpo
        pCorpo->setScale(escala, escala);
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

    //Configura a nova posição da forma, possibilitando movimento.
    void Forma::atualizar(Coordenada::Vetor2f posicao)
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
