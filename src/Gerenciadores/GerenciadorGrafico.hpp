/*
 * AUTOR(A)  : Ana Julia Molinos Leite da Silva
 * ALTERAÇÕES: Caio e Silva Barbieri
 * DESCRIÇÃO : Classe que permite o gerenciamento dos elementos gráficos usando
 *             recursos da biblioteca SFML.
 * CRÉDITOS  : Código baseado nas implementações dos alunos Matheus Augusto Burda (repositório 
 *             disponívelem https://github.com/MatheusBurda/Desert, tutorial disponível em: 
 *             https://youtu.be/RFSOXXsm4Ug?si=k1Uctco4N9yD9dzh e https://youtu.be/NODjfdL2Uv0?si=-gTZ4zPqxBcbNOJu) 
 *             e Geovane Lima Salvi (repositório disponível em https://github.com/Giovanenero/JogoPlataforma2D-Jungle,
 *             tutorial disponível em: https://youtu.be/RXmFcBGD8T8?si=zjLJBro0E3dok864)
 * */

#ifndef _GerenciadorGrafico_HPP
#define _GerenciadorGrafico_HPP

#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include "../Coordenada.hpp"


using namespace std;

namespace ElementosGraficos{ class Forma; }

namespace Gerenciadores
{
    class GerenciadorGrafico
    {
        private:
            sf::RenderWindow* pJanela;
            sf::View camera;
            map<const char*, sf::Texture*> mapaTexturas;
            sf::Font* pFonte;
            sf::Clock relogio;
            
            static float dT;
            static GerenciadorGrafico* pGerenciadorGrafico;

            //Construtora privada para permitir execução do padrão de projeto Singleton
            GerenciadorGrafico();

        public:
            ~GerenciadorGrafico();
            static GerenciadorGrafico* getGerenciadorGrafico();
            sf::RenderWindow* getJanela() const;
            void renderizar(ElementosGraficos::Forma* pForma);
            void renderizar(sf::RectangleShape* corpo);
            void renderizar(sf::Shape* corpo); // Com static_cast, desenhamos qualquer shape. Poderia ateh ser sf::drawable
            void renderizar(sf::Text* texto);
            void mostrar();
            void limpar();
            const bool janelaAberta() const;
            void fecharJanela();
            void setTamanhoJanela(const Coordenadas::Vetor2f tam);
            const Coordenadas::Vetor2f getTamanhoJanela() const;
            const Coordenadas::Vetor2f getCentroCamera() const;
            void centralizarCamera(Coordenadas::Vetor2f centro);
            void setTamanhoCamera(Coordenadas::Vetor2f tam);
            sf::View getCamera() const;
            sf::Texture* carregarTextura(const char* caminho);
            sf::Font* carregarFonte(const char* caminho);
            void resetarRelogio();
            const float getTempo() const;
    };
} // namespace Gerenciadores

#endif