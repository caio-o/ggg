#pragma once

#include "Entidades/Personagens/Personagem.hpp"
#include "Entidades/Personagens/Jogador.hpp"

namespace Inimigos
{
    class Inimigo: public Personagem
    {
        protected:
            float tempoUltimoAtaque;
            float cooldown;
            static Jogador* pJogador1;
            static Jogador* pJogador2;
            int nivelMaldade;

        public:
            Inimigo(Especie _especie = inimigo, int const maxVida = 10);
            virtual ~Inimigo();

            virtual void salvar() = 0;
            virtual void executar(const float dT) = 0;
            virtual void atacar() = 0;
            virtual void danificar(Personagem *pPers) = 0;

            virtual void reagirAhColisao(Entidade* pE) = 0;

            void        setCooldown(const float c);
            const float getCooldown() const;

            void        setMaldade(const int mal);
            const int   getMaldade() const;

            const float getTempoUltimoAtaque() const;

            static void setpJogador1(Jogador* pJ);
            static void setpJogador2(Jogador* pJ);
    };
} // namespace Inimigos
