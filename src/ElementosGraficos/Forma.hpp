/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * ALTERAÇÕES: Caio e Silva Barbieri
 * DESCRIÇÃO : Declaração da classe responsável por conter os métodos relacionados a manipulação de 
 *             formas (como mover, redimensionar, animar e etc). Essa classe vai utilizar os recursos 
 *             disponíveis da biblioteca gráfica SFML, permitindo maior desacoplamento.
 * CRÉDITOS  : Código baseado na implementação do aluno Matheus Augusto Burda. Repositório disponível
 *             em https://github.com/MatheusBurda/Desert, tutorial disponível em: 
 *             https://youtu.be/e22ddfm1fBI?si=Clm-QH8AGKQyr3nK
 */

#pragma once

#include "SFML/Graphics.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Coordenada.hpp"

#define TAM_PADRAO 10.0

namespace ElementosGraficos
{
    enum Cores
    {
        transparente = 0,
        branco,
        preto,
        azul,
        ciano,
        verde,
        magenta,
        vermelho,
        amarelo,
        cinza
    };
    
    class Forma
    {
        private:
            sf::Texture* pTextura;
            sf::RectangleShape* pCorpo;
            static Gerenciadores::GerenciadorGrafico* pGerenciadorGrafico;

        public:
            Forma(Coordenadas::Vetor2f posicao = Coordenadas::Vetor2f(0.f, 0.f), 
                  Coordenadas::Vetor2f tamanho = Coordenadas::Vetor2f(TAM_PADRAO, TAM_PADRAO), 
                  const char* caminhoText = "",
                  float escala = 1.0);

            /*Forma(const char* caminhoText,
                  Coordenadas::Vetor2f posicao = Coordenadas::Vetor2f(0.f, 0.f), 
                  Coordenadas::Vetor2f tamanho = Coordenadas::Vetor2f(TAM_PADRAO, TAM_PADRAO), 
                  float escala = 1.0);*/
            //Forma();
            ~Forma();
            static void setGerenciadorGrafico();
            
            void setTextura(const char* caminho, const bool resetarTamanho = false);
            void setTamanho(const float x, const float y);
            void setEscala (const float escala);
            void setEscala (const float escalaX, const float escalaY);
            void setCorPreenchimento(Cores cor);

            sf::RectangleShape* getpCorpo() const;
            void atualizar(Coordenadas::Vetor2f posicao);
            void renderizar();
    };
} // namespace ElementosGraficos
