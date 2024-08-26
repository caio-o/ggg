/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Declaração da classe responsável por definir o comportamento do obstáculo tipo Borracha
 *             que dá dano ao contato com o jogador.
 */

#pragma once

#include "Obstaculo.hpp"
#include "Entidades/Personagens/Jogador.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Borracha: public Obstaculo
        {
            private:
                int dano;
                
                //ponteiros temporários enquanto não há desenvolvimento da fase
                static Jogador* pJogador1;
                static Jogador* pJogador2;

            public:
                Borracha(Especie _especie = obstaculo, const bool _permeavel = true, int dano = 1);
                ~Borracha();
                
                void executar(const float dT);
                void reagirAhColisao(Entidade* pE);

                void setDano(const int d);
                const int getDano() const;

                static void setpJogador1(Jogador* pJ);
                static void setpJogador2(Jogador* pJ);
        };
    } // namespace Obstaculos
    
} // namespace Entidades
