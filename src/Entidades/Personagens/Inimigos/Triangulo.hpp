#pragma once

#include "Inimigo.hpp"
#include "Entidades/Projetil.hpp"

namespace Inimigos
{
    class Triangulo: public Inimigo
    {
        private:
            float cooldown;
            float tempoUltimoAtaque;

        public:
            Triangulo(Especie _especie = inimigo, int maxVida = 10, int dano = 1);
            ~Triangulo();

            void salvar();
            void executar(const float dT);
            void atacar();
            void reagirAhColisao(Entidade* pE);            
    };
} // namespace Inimigos