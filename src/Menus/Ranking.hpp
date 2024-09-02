/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Declaração da classe derivada Ranking, responsável por armazenar nome e pontuação dos 
 *             jogadores e exibi-lás em ordem decrescente.
 */

#pragma once

#include "Menu.hpp"
#include "Estado.hpp"

#include <fstream>
#include <iostream>

#include <map>

using namespace std;

namespace Menus
{
    class Ranking: public Menu, public Estado
    {
        private:
            multimap<int, string> mapaRegistros;

        public:
            Ranking(idEstados id = ranking);
            ~Ranking();

            void executar(const float dT);
            void desenhar();
            void inserirRegistro(const int pontos, string nome);
            void atualizarOpcoes();
            void limparOpcoes();
            void verificaTeclaSolta(string tecla);
    };
} // namespace Menus
