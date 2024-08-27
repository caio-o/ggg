/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Declaração da classe responsável por definir o comportamento e características do 
 *             projétil lançado pelo inimigo do tipo Triângulo.
 */

#pragma once

#include "Entidade.hpp"
#include "Personagens/Jogador.hpp"

namespace Entidades
{
    class Projetil: public Entidade
    {
        protected:
            int dano;
            bool perseguindo; //não usa pra nada
            static Jogador* pJogador1;
            static Jogador* pJogador2;

        public:
            Projetil(const int _dano = 2, const bool pers = false);
            ~Projetil();

            void reagirAhColisao(Entidade* pE);
            void executar(const float dT);

            void setDano(const int d);
            const int getDano() const;

            //A principio o atributo perseguindo não é utilizado, remover métodos posteriormente
            void setPerseguindo(const bool p);
            const bool getPerseguindo() const;

            static void setpJogador1(Jogador* pJ);
            static void setpJogador2(Jogador* pJ);
    };
} // namespace Entidades
