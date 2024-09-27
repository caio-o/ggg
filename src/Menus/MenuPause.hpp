/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Declaração da classe derivada MenuPause, responsável por dar as opções de retorno ao
 *             jogo, salvamento da fase no estado atual e retorno ao menu principal.
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