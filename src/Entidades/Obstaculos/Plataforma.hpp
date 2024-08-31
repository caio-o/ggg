#ifndef _PLATAFORMA_HPP
#define _PLATAFORMA_HPP

#include "Entidades/Obstaculos/Obstaculo.hpp"
namespace Entidades::Obstaculos
{
    class Plataforma : public Obstaculo
    {
    private:
        const bool armadilha;
        bool caindo;
        float tempoDuracao;
        float tempoAtual;

    public:
        Plataforma(float largura = 300.f, float altura = 50.f, Especie _especie = plataforma):
            armadilha(false),
            caindo(false),
            tempoDuracao(3),
            tempoAtual(0.0f),
            Obstaculo(_especie, false)
        {
            setAcelVertical(-1000.f);
            setTamanho(largura, altura);
        }

        ~Plataforma()
        {

        }

        void executar(const float dT)
        { }

        virtual void obstacular(Jogador* pJog) 
        { }

        void salvar(std::ofstream &os) {}
    };
}

#endif