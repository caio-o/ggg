/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Declaração da classe derivada EstadoMenu, responsável por executar métodos específicos
 *             aos menus do jogo.
 */

#pragma once

#include "Estado.hpp"
#include "Menu.hpp"

namespace Menus
{
    class MenuPrincipal: public Estado, public Menu
    {
        private:
            bool doisJogadores;
            bool sequenciaFases;
        
        public:
            MenuPrincipal(idEstados id = menuPrincipal);
            ~MenuPrincipal();
            
            void executar(const float dT);
            void desenhar();

            virtual void verificaTeclaPressionada(string tecla);
            virtual void verificaTeclaSolta(string tecla);
    };
} // namespace Menus
