#ifndef _FASE_HPP
#define _FASE_HPP

#include "Listas/ListaEntidades.hpp"
#include "Gerenciadores/GerenciadorColisoes.hpp"
#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Gerenciadores/GerenciadorEventos.hpp"
#include "Entidades/Personagens/Jogador.hpp"

namespace Fases
{
    class Fase : public Ente
    {
    protected:
        ListaEntidades colecao;
        Gerenciadores::GerenciadorGrafico *pGG;
        Gerenciadores::GerenciadorColisoes *pGC;
        Gerenciadores::GerenciadorEventos *pGE;
        Jogador *pJog;
        float t0;
        float t1;
        float deltaT;
        //ERRO DE COMPILAÇÃO: FALTA A IMPLEMENTAÇÃO DESSA FUNÇÃO
        virtual void criarObstaculos() = 0;
    
    public:
        Fase();
        virtual ~Fase();
        
        virtual void executar(const float dT = 0.f) = 0;
        virtual void salvar  ();
    };
}

#endif