#ifndef _FASE_HPP
#define _FASE_HPP

#include "Listas/ListaEntidades.hpp"
#include "Gerenciadores/GerenciadorColisoes.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Gerenciadores/GerenciadorEventos.hpp"
#include "Entidades/Personagens/Jogador.hpp"
#include "Estado.hpp"

#define GRAVIDADE      1000.0F
#define LARGURA_FASE   2580.0F
#define ALTURA_FASE    1440.0F
#define CHAO           ALTURA_FASE
#define TETO              0.0F
#define CANTO_ESQUERDO    0.0F
#define CANTO_DIREITO     LARGURA_FASE

namespace Inimigos 
{
    class Quadrado;
    class Triangulo;
    class Estrela;
} using namespace Inimigos;

//class Projetil;

namespace Entidades::Obstaculos
{
    class Plataforma;
    class PlataformaGrudenta;
    class Lapis;
} using namespace Entidades::Obstaculos;

namespace Fases
{
    class Fase : public Ente, public Estado
    {
    protected:
        static bool deveCarregar;
        static bool doisJogadores;
        Forma forma; // background
        Forma saida;
        Forma efeitoGameOver;
        bool gameOver;
        ListaEntidades colecao;
        static Gerenciadores::GerenciadorColisoes *pGC;
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
        virtual void desenhar();
        virtual const bool verificaGameOver();
        virtual const bool verificaVitoria() = 0;

        virtual void salvar  (string nomeArquivo);
        virtual void carregar(string nomeArquivo);

        void                  criarBordas              ();

        Plataforma*           criarPlataforma          (float posX, float posY, float tamX = 300.f, float tamY = 100.f);
        PlataformaGrudenta*   criarPlataformaGrudenta  (float posX, float posY, float tamX = 300.f, float tamY = 100.f);
        Projetil*             criarProjetil            (const float x, const float y);

        Triangulo*            criarTriangulo           (float posX, float posY);
        Quadrado*             criarQuadrado            (float posX, float posY);

        void verificaTeclaPressionada(string tecla);
        void verificaTeclaSolta(string tecla);

        static void setGerenciadorColisoes();

        Jogador* getJogador1() const;
        Jogador* getJogador2() const;

        const bool getGameOver() const;

        static void setDeveCarregar(const bool deve) { deveCarregar = deve; }
        static void setDoisJogadores(const bool dois) { doisJogadores = dois; }
    };
}

#endif