#include "Personagem.hpp"
#include "Ente.hpp"

using namespace Entidades;

Personagem::Personagem(Especie _especie, int _maxVida):
    Entidade(_especie),
    maxVida(_maxVida),
    vida(_maxVida),
    vivo(true)
{
    checarVida();
}

Personagem::~Personagem()
{  }