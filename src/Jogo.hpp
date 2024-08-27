#ifndef _JOGO_HPP
#define _JOGO_HPP

#include "Fases/Fase.hpp"
#include "Fases/FaseTeste.hpp"
using Fases::Fase;

class Jogo
{
private:
    Gerenciadores::GerenciadorGrafico *pGG;
    Gerenciadores::GerenciadorEventos *pGE;
    Fase* primeiraFase;

public:
Jogo();
~Jogo();

void executar();
};




#endif