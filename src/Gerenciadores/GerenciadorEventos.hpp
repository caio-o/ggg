/*
 * AUTOR(A): Ana Julia Molinos Leite da Silva (ana-molinos)
 * DATA: 15/08/2024
 * Classe que permite o gerenciamento das ações do usuário via mouse e teclado usando
 * recursos da biblioteca SFML.
 * */

#ifndef _GerenciadorEventos_HPP
#define _GerenciadorEventos_HPP

#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Gerenciadores/GerenciadorEstados.hpp"
#include "ElementosGraficos/Forma.hpp"

namespace Gerenciadores
{
    class GerenciadorEventos{
        private:         
            static GerenciadorEventos* pGerenciadorEventos;
            static GerenciadorEstados* pGEs;
            static GerenciadorGrafico* pGG;

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