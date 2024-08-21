#include "Entidades/Personagens/Personagem.hpp"
#include "Entidades/Ente.hpp"

using namespace Entidades;

Personagem::Personagem(Figura* _pFigura, int _maxVida):
    Entidade(_pFigura),
    maxVida(_maxVida),
    vida(_maxVida),
    vivo(true)
{
    checarVida();
}

Personagem::~Personagem()
{  }