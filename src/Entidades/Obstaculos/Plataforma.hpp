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
        Plataforma(float largura = 300.f, float altura = 50.f, const bool _armadilha = false):
            armadilha(_armadilha),
            caindo(false),
            tempoDuracao(3),
            tempoAtual(0.0f),
            Obstaculo(Especie::plataforma, false)
        {
            setAcelVertical(-1000.f);
            setTamanho(largura, altura);
        }

        ~Plataforma()
        {

        }

        void reagirAhColisao(Entidade *pE)
        {
            if(armadilha && (pE->getEspecie() == jogador || pE->getEspecie() == inimigo))
            {
                caindo = true;
            }
        }

        void executar(const float dT)
        {
            if(caindo)
            {
                /**
                 * Fazer cair a plataforma pela contagem do tempo
                 */
            }
        }
    };
}

#endif