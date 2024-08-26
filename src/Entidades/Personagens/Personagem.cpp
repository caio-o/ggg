#include "Personagem.hpp"
#include "Ente.hpp"

using namespace Entidades;

float Personagem::hitDelay = 0.5F;

Personagem::Personagem(Especie _especie, int _maxVida):
    Entidade(_especie),
    maxVida(_maxVida),
    vida(_maxVida),
    vivo(true),
    momentoUltimoDano(-1000.f),
    imunidade(false)
{
    checarVida();
}

Personagem::~Personagem()
{  }

void Personagem::receberDano(int dano, const bool delay)
{
    cout << "RECEBENDO DANO..."<< endl;

    if (delay)
    {
        cout << "    ...COM DELAY..." << endl;
        atualizarImunidade();
        if(!imunidade)
        {
            cout << "        ...DANO RECEBIDO." << endl;
            momentoUltimoDano = pGG->getTempo();
            vida -= dano;
            aceleraY(-200.F);
        }

        imunidade = true; 
    }
    else
    {
        vida -= dano;
    }

    if(vida < 0)
        vida = 0;
}

void Personagem::atualizarImunidade()
{
    imunidade = (bool)(pGG->getTempo() - momentoUltimoDano < hitDelay);
}