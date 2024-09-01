/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Declaração da classe derivada MenuPause, responsável por executar métodos específicos
 *             aos menu de pausa do jogo.
 */

#pragma once

#include "Estado.hpp"
#include "Menu.hpp"
#include "Fases/Fase.hpp"

namespace Menus
{
    class MenuPause: public Estado, public Menu
    {
        private:
            Fases::Fase* pFase;
        
        public:
            MenuPause(idEstados id = menuPause);
            ~MenuPause();
            
            void executar(const float dT);
            void desenhar();

            void verificaTeclaPressionada(string tecla);
            void verificaTeclaSolta(string tecla);

            void setpFase(Fases::Fase* pF);
    };
} // namespace Menus