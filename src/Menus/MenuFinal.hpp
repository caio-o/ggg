/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Declaração da classe derivada MenuFinal, responsável por executar métodos específicos
 *             aos procedimentos de finalização do jogo (quando os jogadores morrem ou completam as
 *             fases).
 */

#pragma once

#include "Estado.hpp"
#include "Menu.hpp"
#include "Fases/Fase.hpp"

namespace Menus
{
    class MenuFinal: public Estado, public Menu
    {
        private: // Atributos privados
            Fases::Fase* pFase;
            string nome1;
            string nome2;
            ElementosGraficos::Texto subtitulo1;
            ElementosGraficos::Texto subtitulo2;
            bool nomeJogador2;
            bool doisJogadores;

        private: // Metodos privados
            void ajustaTextoVetor();
            const bool verificaTeclaAlfaNumerica(string tecla);
            void atualizaVetorOpcoes();
        
        public:
            MenuFinal(idEstados id = menuFimJogo);
            ~MenuFinal();
            
            void executar(const float dT);
            void desenhar();

            void verificaTeclaPressionada(string tecla);
            void verificaTeclaSolta(string tecla);

            void setpFase(Fases::Fase* pF);
            void setDoisJogadores(const bool b);
    };
} // namespace Menus