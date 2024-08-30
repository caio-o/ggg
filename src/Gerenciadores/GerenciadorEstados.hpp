/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Declaração da classe GerenciadorEstados, cujo objeto é o único responsável por 
 *             manipular os estados de jogo (como menu e execução do próprio jogo).
 */

#pragma once

#include <map>
#include "Estado.hpp"

using namespace std;

namespace Gerenciadores
{
    class GerenciadorEstados
    {
        private:
            idEstados idEstadoAtual;
            map<idEstados, Estado*> mapaEstados;
            static GerenciadorEstados* pGEs;

        private:
            GerenciadorEstados();

        public:
            ~GerenciadorEstados();
            static GerenciadorEstados* getGerenciadorEstados();
            void executarEstado(idEstados id);
            const idEstados getIdEstadoAtual() const;
            Estado* getEstadoAtual();
            void setObservadores();
    };
} // namespace Gerenciadores
