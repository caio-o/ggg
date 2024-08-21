/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Declaração da classe GerenciadorEstados, cujo objeto é o único responsável por 
 *             manipular os estados de jogo (como menu e execução do próprio jogo).
 */

#pragma once

#include <map>
#include "Estados/Estado.hpp"

using namespace std;

namespace Gerenciadores
{
    class GerenciadorEstados
    {
        private:
            Estados::idEstados idEstadoAtual;
            map<Estados::idEstados, Estados::Estado*> mapaEstados;
            static GerenciadorEstados* pEstados;

        private:
            GerenciadorEstados();

        public:
            ~GerenciadorEstados();
            static GerenciadorEstados* getGerenciadorEstados();
            void mudarEstado(Estados::idEstados id);
            Estados::idEstados getEstadoAtual() const;
            void setObservadores();
    };
} // namespace Gerenciadores
