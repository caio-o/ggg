/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe responsável por conter os métodos relacionados a manipulação de 
 *             texto (cor, fonte, tamanho, alinhamento e etc). Essa classe vai utilizar os recursos 
 *             disponíveis da biblioteca gráfica SFML, permitindo maior desacoplamento.
 */

#include "Texto.hpp"
#include "Erros.hpp"

#define CAMINHO_FONTE ""

namespace ElementosGraficos
{
    Gerenciadores::GerenciadorGrafico* Texto::pGG(NULL);
    
    Texto::Texto(const string info):
    pTexto(new sf::Text()),
    info(info)
    {
        sf::Font* pFonte = pGG->carregarFonte(CAMINHO_FONTE);

        if(pFonte)
            pTexto->setFont(*pFonte);
        else
            cout << "Erro em ElementosGraficos::Texto::Texto()::pFonte: " << ERRO_ALOCACAO << endl;
    }

    Texto::~Texto()
    {
        //Desaloca o texto
        if(pTexto)
            delete pTexto;

        pTexto = NULL;
    }

    void Texto::setpGG()
    {
        pGG = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
    }
    
    //Recebe uma string que consistirá no conteúdo da caixa de texto
    void Texto::setInfo(const string inf)
    {
        info = inf;

        pTexto->setString(info);
    }

    //Seta a posição da caixa de texto
    void Texto::setPosicao(const Coordenadas::Vetor2f pos)
    {
        pTexto->setPosition(pos.x, pos.y);
    }

    //Seta a posição da caixa de texto
    void Texto::setPosicao(const float x, const float y)
    {
        pTexto->setPosition(x, y);
    }

    //Seta a cor do preenchimento do texto conforme a lista de cores presentes no namespace ElementosGraficos
    void Texto::setCor(Cores cor)
    {
        switch (cor)
        {
        case transparente:
            pTexto->setFillColor(sf::Color::Transparent);
            break;

        case branco:
            pTexto->setFillColor(sf::Color::White);
            break;

        case preto:
            pTexto->setFillColor(sf::Color::Black);
            break;

        case azul:
            pTexto->setFillColor(sf::Color::Blue);
            break;
            
        case ciano:
            pTexto->setFillColor(sf::Color::Cyan);
            break;
        
        case verde:
            pTexto->setFillColor(sf::Color::Green);
            break;

        case magenta:
            pTexto->setFillColor(sf::Color::Magenta);
            break;

        case vermelho:
            pTexto->setFillColor(sf::Color::Red);
            break;

        case amarelo:
            pTexto->setFillColor(sf::Color::Yellow);
            break;
        
        default:
            cout << "Erro em ElementosGraficos::Texto::setCor(): argumento invalido, cor não alterada!" << endl;
            break;
        }
    }

    //Seta o tamanho da fonte
    void Texto::setTamanho(const int tam)
    {
        pTexto->setCharacterSize(tam);
    }

    //Seta o alinhamento do texto em relação a caixa de texto conforme opções do namespace ElementosGraficos:
    //Esquerda: posiciona o texto à esquerda na horizontal e no centro na vertical
    //Centro: posiciona o texto no centro tanto na horizontal quanto na vertical
    //Direita: posiciona o texto à direita na horizontal e no centro na vertical
    void Texto::setAlinhamento(Alinhamento posicao)
    {
        switch (posicao)
        {
        case esquerda:
            pTexto->setOrigin(0.0, getTamanhoCaixaTexto().y/2);
            break;

        case centro:
            pTexto->setOrigin(getTamanhoCaixaTexto().x/2, getTamanhoCaixaTexto().y/2);
            break;

        case direita:
            pTexto->setOrigin(getTamanhoCaixaTexto().x, getTamanhoCaixaTexto().y/2);
            break;

        default:
            pTexto->setOrigin(0.0, getTamanhoCaixaTexto().y/2);
            break;
        }
    }
    
    //Retorna as dimensões da caixa de texto
    const Coordenadas::Vetor2f Texto::getTamanhoCaixaTexto() const
    {
        sf::FloatRect caixaTexto = pTexto->getLocalBounds();

        return Coordenadas::Vetor2f(caixaTexto.width, caixaTexto.height);
    }

    const Coordenadas::Vetor2f Texto::getPosicao() const
    {
        return Coordenadas::Vetor2f(pTexto->getPosition().x, pTexto->getPosition().y);
    }

    const string Texto::getInfo() const
    {
        return info;
    }

    void Texto::renderizar()
    {
        pGG->renderizar(pTexto);
    }
    
} // namespace Elementos Gráficos
