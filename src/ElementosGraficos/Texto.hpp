/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Declaração da classe responsável por conter os métodos relacionados a manipulação de 
 *             texto (cor, fonte, tamanho, alinhamento e etc). Essa classe vai utilizar os recursos 
 *             disponíveis da biblioteca gráfica SFML, permitindo maior desacoplamento.
 * CRÉDITOS  : Código baseado na implementação do aluno Matheus Augusto Burda. Repositório disponível
 *             em https://github.com/MatheusBurda/Desert, tutorial disponível em: 
 *             https://youtu.be/e22ddfm1fBI?si=Clm-QH8AGKQyr3nK
 */

#pragma once

#include "SFML/Graphics.hpp"
#include <string>

#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Coordenada.hpp"
#include "Forma.hpp"

using namespace std;

namespace ElementosGraficos
{
    enum Alinhamento
    {
        esquerda = 0,
        centro,
        direita
    };
    
    class Texto
    {
        private:
            sf::Text* pTexto;
            string info;
            static Gerenciadores::GerenciadorGrafico* pGG;

        public:
            Texto(string info = "");
            ~Texto();

            static void setGerenciadorGrafico();
            
            void setInfo(string inf);
            void setPosicao(const Coordenadas::Vetor2f pos);
            void setPosicao(const float x, const float y);
            void setCor(Cores cor);
            void setTamanho(const int tam);
            void setAlinhamento(Alinhamento posicao);
            
            const Coordenadas::Vetor2f getTamanhoCaixaTexto() const;
            const Coordenadas::Vetor2f getPosicao() const;
            string getInfo() const;

            void renderizar();
    };
} // namespace ElementosGraficos
