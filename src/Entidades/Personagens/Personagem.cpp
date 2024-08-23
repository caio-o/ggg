#include "Entidades/Personagens/Personagem.hpp"
#include "Entidades/Ente.hpp"

using namespace Entidades;

Personagem::Personagem(int _maxVida):
    Entidade(),
    maxVida(_maxVida),
    vida(_maxVida),
    vivo(true)
{
    checarVida();
}

Personagem::~Personagem()
{  }