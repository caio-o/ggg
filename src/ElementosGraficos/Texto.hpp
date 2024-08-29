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
            Texto(const string info = "");
            ~Texto();

            static void setpGG();
            
            void setInfo(const string inf);
            void setPosicao(const Coordenadas::Vetor2f pos);
            void setPosicao(const float x, const float y);
            void setCor(Cores cor);
            void setTamanho(const int tam);
            void setAlinhamento(Alinhamento posicao);
            
            const Coordenadas::Vetor2f getTamanhoCaixaTexto() const;
            const Coordenadas::Vetor2f getPosicao() const;
            const string getInfo() const;

            void renderizar();
    };
} // namespace ElementosGraficos
