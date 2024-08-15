/*
 * AUTOR(A): Ana Julia Molinos Leite da Silva (ana-molinos)
 * DATA: 15/08/2024
 * Classe que permite o gerenciamento das ações do usuário via mouse e teclado usando
 * recursos da biblioteca SFML.
 * */

#pragma once

#include <SFML/Graphics.hpp>
#include "Grafico.hpp"

namespace Gerenciadores
{
    class Evento{
        private:
            Grafico* pGrafico;

            /*
             * Atributo provisório, após implementação da classe Jogador, será substituído por um
             * ponteiro do tipo Jogador, ou se relacionára com os objetos do padrão de projeto Observer.
             */
            sf::RectangleShape* pForma;
            
            static Evento* pEvento;

        private:
            //Construtora privada atendendo ao padrão de projeto Singleton
            Evento();

        public:
            ~Evento();
            static Evento* getEvento();
            //void setGerenciadorGrafico(Grafico* pG);
            //método desnecessário em função do ponteiro para o gGrafico ser estático
            void setForma(sf::RectangleShape* forma);
            void verificaTeclaSolta();
            void verificaTeclaPressionada();
            void executar();
    };
} // namespace Gerenciadores
