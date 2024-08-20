/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Declaração da classe derivada EstadoMenu, responsável por executar métodos específicos
 *             aos menus do jogo.
 */

#pragma once

#include "Estado.hpp"
//#include "Menu.hpp" /*Descomentar quando Menu for implementado*/

namespace Estados
{
    class Menu; //pré-definição de classe

    class EstadoMenu: public Estado
    {
        private:
            Menu* pMenu;

        public:
            EstadoMenu(idEstados id = desconhecido);
            ~EstadoMenu();
            void renderizar();
            void criarMenu();
            Menu* getMenu() const;
            void setObservador(const bool b);
            void executar();
    };
} // namespace Estados
