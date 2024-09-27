/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * ALTERAÇÕES: Caio e Silva Barbieri
 * DESCRIÇÃO : Declaração da classe responsável por definir o comportamento e características do 
 *             inimigo Quadrado, que persegue e se lança contra o jogador, conforme a distância entre
 *             eles.
 */

#pragma once

#include "Inimigo.hpp"
#include "json.hpp"

namespace Inimigos
{
    class Quadrado: public Inimigo
    {
        private:
            int dano;
            Jogador* pJogadorPerseguido;
            bool atacando;
            

        public:
            Quadrado(int maxVida = 10);
            ~Quadrado();
            
            void salvar(ofstream &ofs);
            virtual void carregar(nlohmann::ordered_json &j);
            void executar(const float dT);
            void atacar();
            void vira();
            void reagirAhColisao(Entidade* pE);
            virtual void danificar(Personagem *pPers) { pPers->receberDano(dano, true); };
            void definirPerseguido();
            
            //Esses métodos poderiam ter sido definidos como privados...
            bool rangePerseguir();
            bool rangeAtacar();
            bool jogadorAesquerda();

            void setDano(const int d);
            const int getDano() const;
    };
} // namespace Inimigo
