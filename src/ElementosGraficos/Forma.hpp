/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Declaração da classe responsável por conter os métodos relacionados a manipulação de 
 *             formas (como mover, redimensionar, animar e etc). Essa classe vai utilizar os recursos 
 *             disponíveis da biblioteca gráfica SFML, permitindo maior desacoplamento.
 */

#pragma once

#include "SFML/Graphics.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Coordenada.hpp"

#define TAM_PADRAO 10.0

namespace ElementosGraficos
{
    class Forma
    {
        private:
            sf::Texture* pTextura;
            sf::RectangleShape* pCorpo;
            static Gerenciadores::GerenciadorGrafico* pGerenciadorGrafico;

        public:
            Forma(const char* caminhoText = "", 
                  Coordenada::Vetor2f posicao = Coordenada::Vetor2f(0.f, 0.f), 
                  Coordenada::Vetor2f tamanho = Coordenada::Vetor2f(TAM_PADRAO, TAM_PADRAO), 
                  float escala = 1.0);

            Forma();
            ~Forma();
            void setTextura(const char* caminho);
            sf::RectangleShape* getpCorpo() const;
            void atualizar(Coordenada::Vetor2f posicao);
            void renderizar();
    };
} // namespace ElementosGraficos
