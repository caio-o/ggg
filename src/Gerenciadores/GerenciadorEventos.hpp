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

namespace Gerenciadores
{
    class GerenciadorEventos{
        private:
            Gerenciadores::GerenciadorGrafico* pGerenciadorGrafico;

            /*
             * Atributo provisório, após implementação da classe Jogador, será substituído por um
             * ponteiro do tipo Jogador, ou se relacionára com os objetos do padrão de projeto Observer.
             */
            sf::RectangleShape* pForma;
            
            static GerenciadorEventos* pGerenciadorEventos;

        private:
            //Construtora privada atendendo ao padrão de projeto Singleton
            GerenciadorEventos();

        public:
            ~GerenciadorEventos();
            static GerenciadorEventos* getGerenciadorEventos();
            //void setGerenciadorGrafico(GerenciadorGrafico* pG);
            //método desnecessário em função do ponteiro para o gGerenciadorGrafico ser estático
            void setForma(sf::RectangleShape* forma);
            void verificaTeclaSolta();
            void verificaTeclaPressionada();
            void executar();
    };
} // namespace Gerenciadores

#endif