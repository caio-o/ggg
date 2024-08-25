#pragma once

#include "Inimigo.hpp"

namespace Inimigos
{
    class Quadrado: public Inimigo
    {
        private:
            bool esquerda;

        public:
            Quadrado(Especie _especie, int maxVida = 10, int dano = 1);
            ~Quadrado();
            
            void salvar();
            void executar();
            void mover();
            void atacar();
            void vira();
            
            bool rangePerseguir();
            bool rangeAtacar();
            bool jogadorAesquerda();
    };
} // namespace Inimigo
