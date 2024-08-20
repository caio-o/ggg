/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe derivada EstadoJogo, responsável por executar métodos específicos
 *             a execução do jogo e fases.
 */

#pragma once

#include "Estado.hpp"
//#include "Fase1.hpp" /*Descomentar quando Jogo for implementado*/
//#include "Fase2.hpp" /*Descomentar quando Jogo for implementado*/

namespace Estados
{
    class Fase; //pré-definição de classe

    class EstadoJogo: public Estado
    {
        private:
            Fase* pFase;

        public:
            EstadoJogo(idEstados id = desconhecido);
            ~EstadoJogo();
            void renderizar();
            void criarFase();
            Fase* getFase() const;
            void passarFase();
            void setObservador(const bool b);
            void executar();
    };
} // namespace Estados
