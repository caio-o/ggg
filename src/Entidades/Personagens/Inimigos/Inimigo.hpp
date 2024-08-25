#pragma once

#include "Entidades/Personagens/Personagem.hpp"
#include "Entidades/Personagens/Jogador.hpp"

namespace Inimigos
{
    class Inimigo: public Personagem
    {
        protected:
            int dano;
            Jogador* pJogador;

        public:
            Inimigo(Especie _especie, int maxVida = 10, int dano = 1, Jogador* pJ = NULL);
            virtual ~Inimigo();

            virtual void salvar() = 0;
            virtual void executar() = 0;
            virtual void mover() = 0;
            virtual void atacar() = 0;

            void setDano(const int d);
            const int getDano() const;

            void setpJogador(Jogador* pJ);
            Jogador* getpJogador() const;
    };
} // namespace Inimigos
