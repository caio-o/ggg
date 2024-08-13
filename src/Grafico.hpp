/*
 * AUTOR(A): Ana Julia Molinos Leite da Silva (ana-molinos)
 * DATA: 12/08/2024
 * Classe que permite o gerenciamento dos elementos gráficos usando
 * recursos da biblioteca SFML.
 * */

#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include "Coordenada.hpp"

using namespace std;

namespace Gerenciadores
{
    class Grafico
    {
        private:
            sf::RenderWindow* pJanela;
            sf::View camera;
            map<const char*, sf::Texture*> mapaTexturas;
            //avaliar a necessidade uma vez que há a possibilidade de 
            //se utilizar apenas uma fonte no jogo todo.
            map<const char*, sf::Font*> mapaFontes;
            sf::Clock relogio;
            
            static float dT;
            static Grafico* pGrafico;

            //Construtora privada para permitir execução do padrão de projeto Singleton
            Grafico();

        public:
            ~Grafico();
            static Grafico* getGrafico();
            sf::RenderWindow* getJanela() const;
            void renderizar(sf::RectangleShape* corpo);
            void renderizar(sf::Text* texto);
            void mostrar();
            void limpar();
            const bool janelaAberta() const;
            void fecharJanela();
            void setTamanhoJanela(const Coordenada<float> tam);
            const Coordenada<float> getTamanhoJanela() const;
            const Coordenada<float> getPosicaoInicial() const;
            void centralizarCamera();
            void setTamanhoCamera(Coordenada<float> tam);
            sf::View getCamera() const;
            sf::Texture* carregarTextura(const char* caminho);
            sf::Font* carregarFonte(const char* caminho);
            void resetarRelogio();
            const float getTempo() const;
    };
} // namespace Gerenciadores
