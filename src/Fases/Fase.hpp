#ifndef _FASE_HPP
#define _FASE_HPP

#include "Listas/ListaEntidades.hpp"
#include "Gerenciadores/GerenciadorColisoes.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Gerenciadores/GerenciadorEventos.hpp"
#include "Entidades/Personagens/Jogador.hpp"

#define LARGURA_FASE   2580.0F
#define ALTURA_FASE    1440.0F
#define CHAO           ALTURA_FASE
#define TETO              0.0F
#define CANTO_ESQUERDO    0.0F
#define CANTO_DIREITO     LARGURA_FASE

namespace Fases
{
    class Fase : public Ente
    {
    protected:
        Forma efeitoGameOver;
        bool gameOver;
        ListaEntidades colecao;
        Gerenciadores::GerenciadorGrafico *pGG;
        Gerenciadores::GerenciadorColisoes *pGC;
        Gerenciadores::GerenciadorEventos *pGE;
        Jogador *pJog;
        Jogador *pJog2;
        float t0;
        float t1;
        float deltaT;

        virtual void criarObstaculos () = 0;
        virtual void criarInimigos   () = 0;
    
    public:
        Fase();
        virtual ~Fase();
        
        virtual void executar(const float dT = 0.f) = 0;
        virtual const bool verificaGameOver();

        virtual void salvar  ();

        void          criarProjetil            (const float x, const float y);
        void          criarPlataforma          (float posX, float posY, float tamX = 300.f, float tamY = 100.f);
        void          criarPlataformaGrudenta  (float posX, float posY, float tamX = 300.f, float tamY = 100.f);
        void          criarBordas              ();

        void          criarTriangulo           (float posX, float posY);
        void          criarQuadrado            (float posX, float posY);


    };
}

#endif