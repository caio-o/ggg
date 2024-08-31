#ifndef _ESTRELA_HPP
#define _ESTRELA_HPP
#include "Entidades/Personagens/Inimigos/Inimigo.hpp"
#include "Fases/Tuneis.hpp"

namespace Inimigos
{
    class Estrela : public Inimigo
    {
    private:
        static Fases::Tuneis *pFase;
        bool  arrependimento;
        float momentoUltimaChamada;
        int   nivelMaldade;
        int   nCapangas;
        void arrependerse();

    public:
        Estrela();
        ~Estrela();

        void danificar(Personagem* pPers);
        void reagirAhColisao(Entidade *pE);
        void salvar(ofstream &ofs){};
        void atacar();
        void executar(const float deltaT);
        static void setFase(Fases::Tuneis* _pFase) { pFase = _pFase; }
        void setNumCapangas(const int num) { nCapangas = num; }
        const bool chamaCapangas();
    };
}

#endif