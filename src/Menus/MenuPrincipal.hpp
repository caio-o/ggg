/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Declaração da classe derivada MenuPrincipal, responsável por executar métodos específicos
 *             ao menu incial do jogo.
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

            void verificaTeclaPressionada(string tecla);
            void verificaTeclaSolta(string tecla);
    };
} // namespace Menus
