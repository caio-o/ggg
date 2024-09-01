#ifndef _JOGADOR_HPP
#define _JOGADOR_HPP

#include "Personagem.hpp"
#include "json.hpp"
#include "Ente.hpp"
#include <SFML/Graphics.hpp>
using namespace Entidades;

namespace Entidades
{
    class Jogador : public Personagem   
    {
    private:
        int pontos;
        bool ehJogador1;
        bool noChao;
        float agilidade; // velocidade do CAMINHAR do jogador (no eixo X)
        float lentidao;
        float velPulo;   // velocidade inicial do PULO do jogador (no eixo Y)
        virtual void morrer()  { forma.setEscala(2.f, 1.0f); }; //efeito da morte no 
        

    public:
        Jogador(int _maxVida = 60, const bool j1 = true, const int _pontos = 0);

        ~Jogador();

        const bool  getChao      () const                 { return noChao;        }
        void        setChao      (const bool _noChao)     { noChao   = _noChao;   }
        void        setLentidao  (const float _lentidao)  { lentidao = (_lentidao > 0.0f ? _lentidao : 1.0f); }
        void        pular();
        
        void        operator+=  (int num)          { pontos += num;    }
        void        operator-=  (int num)          { pontos -= num;    }
        const int   getPontos   () const           { return pontos;    }
        void        setPontos (const int _pontos)  { pontos = _pontos; }

        void danificar(Personagem *pPers);
        void carregar(nlohmann::ordered_json &j);
        void salvar(std::ofstream &os);
        void atacar();
        void executar(const float dT);
        void reagirAhColisao(Entidade* pE);
        void controlarse();
    };
}

#endif