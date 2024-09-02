/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Declaração da classe responsável por definir o comportamento do obstáculo tipo Lapis
 *             que dá dano ao contato com o jogador.
 */

#pragma once

#include "Obstaculo.hpp"
#include "Entidades/Personagens/Jogador.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Lapis: public Obstaculo
        {
            private:
                int dano;
                
                //ponteiros temporários enquanto não há desenvolvimento da fase
                static Jogador* pJogador1;
                static Jogador* pJogador2;

            public:
                Lapis(const bool _permeavel = false, const int dano = 1);
                ~Lapis();
                
                void salvar(std::ofstream &os);
                virtual void carregar(nlohmann::ordered_json &j);
                void obstacular(Jogador *pJog);
                void executar(const float dT);

                void      setDano(const int d);
                const int getDano() const;

                static void setpJogador1(Jogador* pJ);
                static void setpJogador2(Jogador* pJ);
        };
    } // namespace Obstaculos
    
} // namespace Entidades
