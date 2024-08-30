#pragma once

#include "Inimigo.hpp"

namespace Inimigos
{
    class Quadrado: public Inimigo
    {
        private:
            int dano;
            Jogador* pJogadorPerseguido;
            bool atacando;
            

        public:
            Quadrado(Especie _especie = inimigo, int maxVida = 10);
            ~Quadrado();
            
            void salvar();
            void executar(const float dT);
            void atacar();
            void vira();
            void reagirAhColisao(Entidade* pE);
            virtual void danificar(Personagem *pPers) { pPers->receberDano(dano, true); };
            void definirPerseguido();
            
            bool rangePerseguir();
            bool rangeAtacar();
            bool jogadorAesquerda();

            void setDano(const int d);
            const int getDano() const;
    };
} // namespace Inimigo
