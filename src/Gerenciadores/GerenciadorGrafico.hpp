/*
 * AUTOR(A): Ana Julia Molinos Leite da Silva (ana-molinos)
 * DATA: 12/08/2024
 * Classe que permite o gerenciamento dos elementos gráficos usando
 * recursos da biblioteca SFML.
 * */

#ifndef _GerenciadorGrafico_HPP
#define _GerenciadorGrafico_HPP

#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include "../Coordenada.hpp"

using namespace std;

namespace Gerenciadores
{
    class GerenciadorGrafico
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
            static GerenciadorGrafico* pGerenciadorGrafico;

            //Construtora privada para permitir execução do padrão de projeto Singleton
            GerenciadorGrafico();

        public:
            ~GerenciadorGrafico();
            static GerenciadorGrafico* getGerenciadorGrafico();
            sf::RenderWindow* getJanela() const;
            void renderizar(sf::RectangleShape* corpo);
            void renderizar(sf::Shape* corpo); // Com static_cast, desenhamos qualquer shape. Poderia ateh ser sf::drawable
            void renderizar(sf::Text* texto);
            void mostrar();
            void limpar();
            const bool janelaAberta() const;
            void fecharJanela();
            void setTamanhoJanela(const Coordenadas::Vetor2f tam);
            const Coordenadas::Vetor2f getTamanhoJanela() const;
            const Coordenadas::Vetor2f getPosicaoInicial() const;
            void centralizarCamera();
            void setTamanhoCamera(Coordenadas::Vetor2f tam);
            sf::View getCamera() const;
            sf::Texture* carregarTextura(const char* caminho);
            sf::Font* carregarFonte(const char* caminho);
            void resetarRelogio();
            const float getTempo() const;
    };
} // namespace Gerenciadores

#endif