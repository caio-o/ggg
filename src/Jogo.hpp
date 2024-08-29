#ifndef _JOGO_HPP
#define _JOGO_HPP

#include "Fases/Fase.hpp"
#include "Fases/Calabouco.hpp"
#include "Entidades/Personagens/Jogador.hpp"
using Fases::Fase;

class Jogo
{
private:
    

    Gerenciadores::GerenciadorGrafico *pGG;
    Gerenciadores::GerenciadorEventos *pGE;
    Gerenciadores::GerenciadorEstados *pGEs;
    Fase* primeiraFase;

public:
Jogo();
~Jogo();

void executar();
};




#endif