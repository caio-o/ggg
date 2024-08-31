#ifndef _FASE_TESTE_HPP
#define _FASE_TESTE_HPP

#include "Fases/Fase.hpp"
#include "Entidades/Entidade.hpp"
#include "Entidades/Obstaculos/Plataforma.hpp"
#include "Entidades/Obstaculos/Obstaculo.hpp"
#include "Entidades/Personagens/Inimigos/Quadrado.hpp"
#include "Entidades/Personagens/Jogador.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"

#include "Estado.hpp"

using namespace Entidades::Obstaculos;

namespace Fases
{
    class Calabouco : public Estado, public Fase
    {
    private:
        int maxInimigos;
        void criarObstaculos();
        void criarInimigos();
        

    public:
        Calabouco();

        ~Calabouco();

        const bool verificaVitoria();
        void executar(const float dT);
        void desenhar(){};

        void verificaTeclaPressionada(string tecla);
        void verificaTeclaSolta(string tecla);
    };
}



#endif