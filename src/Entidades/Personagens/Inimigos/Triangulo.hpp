/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Declaração da classe responsável por definir o comportamento e características do 
 *             inimigo Triângulo, que lança projéteis contra os jogadores.
 */

#pragma once

#include "Inimigo.hpp"
#include "Entidades/Projetil.hpp"
#include "Fases/Fase.hpp"

namespace Inimigos
{
    class Triangulo: public Inimigo
    {
        private:
            static Fases::Fase* pFase;

        public:
            Triangulo(Especie _especie = inimigo, int maxVida = 10, int dano = 1);
            ~Triangulo();

            void salvar();
            void executar(const float dT);
            void atacar();
            void reagirAhColisao(Entidade* pE);

            static void setpFase(Fases::Fase* pF) { pFase = pF; };            
    };
} // namespace Inimigos