#include "Fases/Fase.hpp"

Fase::Fase():
    Ente(new Forma("../img/quadrado_vermelho.png")),
    entidades()
{
    criarObstaculos();
}

Fase::~Fase()
{ }

void Fase::executar()
{
    entidades.percorrer();
}

void Fase::salvar() 
{ }