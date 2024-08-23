#include "Entidades/Personagens/Personagem.hpp"
#include "Entidades/Ente.hpp"

using namespace Entidades;

Personagem::Personagem(/*Forma* _pForma, */int _maxVida):
    Entidade(/*_pForma*/),
    maxVida(_maxVida),
    vida(_maxVida),
    vivo(true)
{
    checarVida();
}

Personagem::~Personagem()
{  }