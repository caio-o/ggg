/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Declaração da classe GerenciadorEstados, cujo objeto é o único responsável por 
 *             manipular os estados de jogo (como menu e execução das fases).
 * CRÉDITOS  : Código baseado na implementação do aluno Matheus Augusto Burda. Repositório disponível
 *             em https://github.com/MatheusBurda/Desert, tutorial disponível em: 
 *             https://youtu.be/2vFLfO-PKcw?si=opmw_KDV-Jbs0S0_
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
            void executarEstado(const idEstados id);
            const idEstados getIdEstadoAtual() const;
            Estado* getEstadoAtual();
            Estado* getEstado(const idEstados id);
    };
} // namespace Gerenciadores
