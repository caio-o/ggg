#ifndef _FASE_TESTE_HPP
#define _FASE_TESTE_HPP

#include "Fases/Fase.hpp"
#include "Entidades/Entidade.hpp"
#include "Entidades/Obstaculos/Plataforma.hpp"
#include "Entidades/Obstaculos/Obstaculo.hpp"
#include "Entidades/Personagens/Inimigos/Quadrado.hpp"
#include "Entidades/Personagens/Jogador.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"

#include "Estados/Estado.hpp"

using namespace Entidades::Obstaculos;

namespace Fases
{
    class FaseTeste : public Estados::Estado, public Fase
    {
    private:
        int maxInimigos;

        void criarPlataforma         (float posX, float posY, float tamX = 300.f, float tamY = 100.f);
        void criarPlataformaGrudenta (float posX, float posY, float tamX = 300.f, float tamY = 100.f);
        void criarLapis              (float posX, float posY, int dano = 1);
        void criarTriangulo          (float posX, float posY);
        void criarQuadrado           (float posX, float posY);
        void criarBordas             ();
        
        void criarObstaculos();
        void criarInimigos();
        

    public:
        FaseTeste();

        ~FaseTeste();

        void executar(const float dT);
        void desenhar(){};
    };
}



#endif