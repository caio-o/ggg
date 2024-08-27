#pragma once

#include "Inimigo.hpp"

namespace Inimigos
{
    class Quadrado: public Inimigo
    {
        private:
            int dano;
            bool esquerda;
            bool atacando;
            

        public:
            Quadrado(Especie _especie = inimigo, int maxVida = 10);
            ~Quadrado();
            
            void salvar();
            void executar(const float dT);
            void atacar();
            void vira();
            void reagirAhColisao(Entidade* pE);
            
            bool rangePerseguir();
            bool rangeAtacar();
            bool jogadorAesquerda();

            void setDano(const int d);
            const int getDano() const;
    };
} // namespace Inimigo
