#include "Fases/Fase.hpp"

Fase::Fase():
    Ente(new Forma("../img/quadrado_vermelho.png")),
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