#ifndef _GERENCIADOR_COLISOES_HPP
#define _GERENCIADOR_COLISOES_HPP

#include "Coordenada.hpp"
#include "Entidades/Personagens/Jogador.hpp"
#include "Entidades/Personagens/Inimigos/Inimigo.hpp"
#include "Listas/Lista.hpp"
#include "Entidades/Obstaculos/Obstaculo.hpp"
#include "Entidades/Projetil.hpp"

using namespace Coordenadas;
using namespace Entidades;
using namespace Inimigos;
using namespace Listas;
using namespace Entidades::Obstaculos;

/**
 * AUTOR: CAIO
 * CREDITOS: BURDA
 */

namespace Gerenciadores
{
    // << SINGLETON, GERENCIADOR >>
    class GerenciadorColisoes
    {
    private:
        static GerenciadorColisoes* pInstancia;

        Lista<Inimigo>    LI;
        Lista<Jogador>    LJ;
        Lista<Obstaculo>  LO;
        Lista<Projetil>   LP;
     
        Lista<Inimigo>::Iterador itInim;
        Lista<Jogador>::Iterador itJoga;
        Lista<Obstaculo>::Iterador itObst;
        Lista<Projetil>::Iterador itProj;

        // equivalente a Vetor2f(0.0F, 0.0F). Usado na verificacao da colisao.
        const Vetor2f zero;

        // Representa a area em comum ocupada por 2 corpos.
        Vetor2f interseccao;

        void verificaInimigos();
        void verificaObstaculos();
        void verificaProjeteis();
        GerenciadorColisoes();

    public:
        static GerenciadorColisoes* getInstancia();
        ~GerenciadorColisoes();

        void inserirInimigo   (Inimigo*   pI) { LI.push_back(pI); }
        void inserirJogador   (Jogador*   pJ) { LJ.push_back(pJ); }
        void inserirObstaculo (Obstaculo* pO) { LO.push_back(pO); }
        void inserirProjetil  (Projetil*  pP) { LP.push_back(pP); }

        /** METODO EXECUTAR verifica (nesta ordem) colisoes entre:
         *     1. Inimigos e jogadores;
         *     2. Obstaculos e inimigos;
         *     3. Obstaculos e jogadores.
         *   Garante aliás que eles não fiquem uns dentro dos outros,
         *  e chama o mehtodo reagirAhColisao de cada entidade colidida.
         */
        void executar();

        /**
         *   Encontra e retorna a interseccao entre a area ocupada
         *  por 2 entidades. O vetor resultante eh negativo quando
         *  nao ha colisao.
         */
        const Vetor2f calcularInterseccao (Entidade* pE1, Entidade* pE2) const;

        /**
         *    Remove uma entidade de dentro da outra, anulando sua
         *   interseccao. Se a interseccao for negativa, o efeito eh
         *   oposto (atracao) e o resultado eh imprevisivel. Este mehtodo
         *   poderia ser privado.
         */
        void          repelir   (Entidade* pRepelido, Entidade* pRepulsor, Vetor2f interseccao);

    };
}

#endif
