#ifndef _GERENCIADOR_COLISOES_HPP
#define _GERENCIADOR_COLISOES_HPP

#include "Coordenada.hpp"
#include "Entidades/Personagens/Jogador.hpp"
#include "Entidades/Personagens/Inimigos/Inimigo.hpp"
#include "Listas/Lista.hpp"
#include "Entidades/Obstaculos/Obstaculo.hpp"

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

    class GerenciadorColisoes
    {
    private:
        static GerenciadorColisoes* pInstancia;

        Lista<Inimigo> LI;
        Lista<Jogador> LJ;
        Lista<Obstaculo> LO;
     
        Lista<Inimigo>::Iterador itInim;
        Lista<Jogador>::Iterador itJoga;
        Lista<Obstaculo>::Iterador itObst;

        const Vetor2f zero; 
        Vetor2f interseccao;

        void verificaInimigos();
        void verificaObstaculos();
        GerenciadorColisoes();

    public:
        static GerenciadorColisoes* getInstancia();
        ~GerenciadorColisoes();

        void inserirInimigo   (Inimigo*   pI) { LI.push_back(pI); }
        void inserirJogador   (Jogador*   pJ) { LJ.push_back(pJ); }
        void inserirObstaculo (Obstaculo* pO) { LO.push_back(pO); }

        void executar();

        const Vetor2f calcularInterseccao (Entidade* pE1, Entidade* pE2) const;
        void          repelir   (Entidade* pRepelido, Entidade* pRepulsor, Vetor2f interseccao);

    };
}

#endif