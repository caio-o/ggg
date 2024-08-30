/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe responsável por conter os métodos relacionados a manipulação de 
 *             texto (cor, fonte, tamanho, alinhamento e etc). Essa classe vai utilizar os recursos 
 *             disponíveis da biblioteca gráfica SFML, permitindo maior desacoplamento.
 */

#include "Texto.hpp"
#include "Erros.hpp"

#define CAMINHO_FONTE "../fonte/ThaleahFat.ttf"

namespace ElementosGraficos
{
    Gerenciadores::GerenciadorGrafico* Texto::pGG(NULL);
    
    Texto::Texto(string info):
    pTexto(NULL),
    info(info)
    {   
        cout << "Inicio de construção de objeto texto: " << endl;

        //Alocação da fonte  
        sf::Font* pFonte = NULL;

        cout << "Alocação de fonte iniciada!" << endl;

        if(pGG)
            pFonte = pGG->carregarFonte(CAMINHO_FONTE);
        else
            cout << "Erro em ElementosGraficos::Texto::Texto()::pGG: " << ERRO_NULLPTR << endl;

        cout << "Alocação de fonte completa!" << endl;
        
        if(pFonte)
        {
            //Alocação do corpo de texto
            pTexto = new sf::Text(info, *pFonte);

            cout << "Alocação de texto completa!" << endl;

            if(pTexto == NULL)
                cout << "Erro em ElementosGraficos::Texto::Texto()::pTexto: " << ERRO_ALOCACAO << endl;
        }
        else
            cout << "Erro em ElementosGraficos::Texto::Texto()::pFonte: " << ERRO_ALOCACAO << endl;

        cout << "Construção de objeto de texto completa!" << endl;

        setAlinhamento(centro);
    }

    Texto::~Texto()
    {
        //Desaloca o texto
        if(pTexto)
            delete pTexto;

        pTexto = NULL;
    }

    void Texto::setGerenciadorGrafico()
    {
        pGG = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();

        if(pGG==NULL)
            cout << "Erro em ElementosGraficos::Texto::setGerenciadorGrafico()::pGG: " << ERRO_NULLPTR << endl;
    }

    //Recebe uma string que consistirá no conteúdo da caixa de texto
    void Texto::setInfo(const string inf)
    {
        info = inf;

        if(pTexto)
            pTexto->setString(info);
        else
            cout << "Erro em ElementosGraficos::Texto::setInfo()::pTexto: " << ERRO_NULLPTR << endl;
    }

    //Seta a posição da caixa de texto
    void Texto::setPosicao(const Coordenadas::Vetor2f pos)
    {
        if(pTexto)
            pTexto->setPosition(pos.x, pos.y);
        else
            cout << "Erro em ElementosGraficos::Texto::setPosicao()::pCorpo: " << ERRO_NULLPTR << endl;
    }

    //Seta a posição da caixa de texto
    void Texto::setPosicao(const float x, const float y)
    {
        if(pTexto)
            pTexto->setPosition(x, y);
        else
            cout << "Erro em ElementosGraficos::Texto::setPosicao()::pCorpo: " << ERRO_NULLPTR << endl;
    }

    //Seta a cor do preenchimento do texto conforme a lista de cores presentes no namespace ElementosGraficos
    void Texto::setCor(Cores cor)
    {
        if(pTexto)
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
        else
            cout << "Erro em ElementosGraficos::Texto::setCor()::pTexto: " << ERRO_NULLPTR << endl;
    }

    //Seta o tamanho da fonte
    void Texto::setTamanho(const int tam)
    {
        if(pTexto)
            pTexto->setCharacterSize(tam);
        else
            cout << "Erro em ElementosGraficos::Texto::setTamanho()::pTexto: " <<ERRO_NULLPTR << endl;
    }

    //Seta o alinhamento do texto em relação a caixa de texto conforme opções do namespace ElementosGraficos:
    //Esquerda: posiciona o texto à esquerda na horizontal e no centro na vertical
    //Centro: posiciona o texto no centro tanto na horizontal quanto na vertical
    //Direita: posiciona o texto à direita na horizontal e no centro na vertical
    void Texto::setAlinhamento(Alinhamento posicao)
    {
        if(pTexto)
        {
            switch (posicao)
            {
            case esquerda:
                pTexto->setOrigin(0.0, 0.0);
                break;

            case centro:
                pTexto->setOrigin(getTamanhoCaixaTexto().x/2, getTamanhoCaixaTexto().y);
                break;

            case direita:
                pTexto->setOrigin(getTamanhoCaixaTexto().x, 0.0);
                break;

            default:
                pTexto->setOrigin(getTamanhoCaixaTexto().x/2, getTamanhoCaixaTexto().y);
                break;
            }
        }
        else
            cout << "Erro em ElementosGraficos::Texto::setAlinhamento()::pTexto: " << ERRO_NULLPTR << endl;
    }
    
    //Retorna as dimensões da caixa de texto
    const Coordenadas::Vetor2f Texto::getTamanhoCaixaTexto() const
    {
        if(pTexto)
        {
            sf::FloatRect caixaTexto = pTexto->getLocalBounds();

            return Coordenadas::Vetor2f(caixaTexto.width, caixaTexto.height);
        }

        cout << "Erro em ElementosGraficos::Texto::getTamanhoCaixaTexto()::pTexto: " << ERRO_NULLPTR << endl;
        exit(1);
    }

    const Coordenadas::Vetor2f Texto::getPosicao() const
    {
        if(pTexto)
            return Coordenadas::Vetor2f(pTexto->getPosition().x, pTexto->getPosition().y);
        
        cout << "Erro em ElementosGraficos::Texto::getPosicao()::pTexto: " << ERRO_NULLPTR << endl;
        exit(1);
    }

    string Texto::getInfo() const
    {
        return info;
    }

    void Texto::renderizar()
    {
        if(pGG)
            pGG->renderizar(pTexto);
        else
            cout << "Erro em ElementosGraficos::Texto::renderizar()::pTexto: " << ERRO_NULLPTR << endl;
    }
    
} // namespace Elementos Gráficos
