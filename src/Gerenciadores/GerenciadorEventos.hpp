/*
 * AUTOR(A)  : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Classe que permite o gerenciamento das ações do usuário via mouse e teclado usando
 *             recursos da biblioteca SFML.
 * CRÉDITOS  : Código baseado nas implementações dos alunos Matheus Augusto Burda (repositório 
 *             disponível em https://github.com/MatheusBurda/Desert, tutorial disponível em: 
 *             https://youtu.be/bacO-m3-HnA?si=bSiWxTsi90R5eNJH)ce Geovane Lima Salvi (repositório 
 *             disponível em https://github.com/Giovanenero/JogoPlataforma2D-Jungle, tutorial 
 *             disponível em: https://youtu.be/FYlLKwSUrW0?si=qOwhLSCrHhIM6gzM)
 * */

#ifndef _GerenciadorEventos_HPP
#define _GerenciadorEventos_HPP

#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Gerenciadores/GerenciadorEstados.hpp"
#include "ElementosGraficos/Forma.hpp"

#include <map>
using namespace std;

namespace Gerenciadores
{
    class GerenciadorEventos{
        private:         
            static GerenciadorEventos* pGerenciadorEventos;
            static GerenciadorEstados* pGEs;
            static GerenciadorGrafico* pGG;

            map<sf::Keyboard::Key, string> mapaTeclas;

        private:
            //Construtora privada atendendo ao padrão de projeto Singleton
            GerenciadorEventos();

        public:
            ~GerenciadorEventos();
            static GerenciadorEventos* getGerenciadorEventos();
            static void setGerenciadorGrafico();
            static void setGerenciadorEstados();
   
            void verificaTeclaSolta(sf::Keyboard::Key tecla);
            void verificaTeclaPressionada(sf::Keyboard::Key tecla);
            void executar();
    };
} // namespace Gerenciadores

#endif