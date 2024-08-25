#pragma once

#include "Entidades/Personagens/Personagem.hpp"
#include "Entidades/Personagens/Jogador.hpp"

namespace Inimigos
{
    class Inimigo: public Personagem
    {
        protected:
            int dano;
            static Jogador* pJogador1;
            static Jogador* pJogador2;

        public:
            Inimigo(Especie _especie, int maxVida = 10, int dano = 1);
            virtual ~Inimigo();

            virtual void salvar() = 0;
            virtual void executar() = 0;
            virtual void atacar() = 0;

            void setDano(const int d);
            const int getDano() const;

            static void setpJogador1(Jogador* pJ);
            static void setpJogador2(Jogador* pJ);
    };
} // namespace Inimigos
