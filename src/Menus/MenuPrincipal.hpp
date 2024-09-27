/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Declaração da classe derivada MenuPrincipal, responsável por permitir ao jogador 
 *             iniciar a execução das fases, escolher a quantidade de jogadores, exibir o ranking,
 *             carregar um jogo salvo ou encerrar a execução da aplicação.
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
        
        public:
            MenuPrincipal(idEstados id = menuPrincipal);
            ~MenuPrincipal();
            
            void executar(const float dT);
            void desenhar();

            void verificaTeclaPressionada(string tecla);
            void verificaTeclaSolta(string tecla);
    };
} // namespace Menus
