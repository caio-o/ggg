#pragma once

#include "Inimigo.hpp"

namespace Inimigos
{
    class Quadrado: public Inimigo
    {
        private:
            bool esquerda;
            bool atacando;
            float tempoUltimoAtaque;
            float cooldown;

        public:
            Quadrado(Especie _especie, int maxVida = 10, int dano = 1);
            ~Quadrado();
            
            void salvar();
            void executar(const float dT);
            void atacar();
            void vira();
            void reagirAhColisao(Entidade* pE);
            
            bool rangePerseguir();
            bool rangeAtacar();
            bool jogadorAesquerda();
    };
} // namespace Inimigo
