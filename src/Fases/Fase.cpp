#include "Fases/Fase.hpp"

Fase::Fase():
    Ente(),
    entidades()
{
    //ERRO DE COMPILAÇÃO
    //criarObstaculos();
}

Fase::~Fase()
{ }

void Fase::executar()
{
    entidades.percorrer();
}

void Fase::salvar() 
{ }