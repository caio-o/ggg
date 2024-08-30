#include "Inimigo.hpp"
#include "Erros.hpp"

#include <iostream>
using namespace std;

namespace Inimigos
{
    Jogador* Inimigo::pJogador1(NULL); //Jogador* Inimigo::pJogador1(Fase::pJogador1);
    Jogador* Inimigo::pJogador2(NULL); //Jogador* Inimigo::pJogador2(Fase::pJogador2);

    Inimigo::Inimigo(Especie _especie, int const maxVida):
    Personagem(_especie, maxVida),
    cooldown(3.0),
    tempoUltimoAtaque(0.0)
    {
        
        /*if(pJogador1 == NULL)
            cout << "'Erro em Entidades::Personagens::Inimigos::Inimigo::Inimigo() em pJogador1: "
                 << ERRO_NULLPTR << endl;*/
    }

    Inimigo::~Inimigo()
    {
        cooldown = -1;
        tempoUltimoAtaque = -1;
        maxVida = -1;
        vida = -1;
        vivo = false;
    }

    void Inimigo::setMaldade(const int mal)
    {
        nivelMaldade = mal;
    }

    const int   Inimigo::getMaldade() const
    {
        return nivelMaldade;
    }

    void Inimigo::setCooldown(const float c)
    {
        cooldown = c;
    }

    const float Inimigo::getCooldown() const
    {
        return cooldown;
    }

    const float Inimigo::getTempoUltimoAtaque() const
    {
        return tempoUltimoAtaque;
    }

    void Inimigo::setpJogador1(Jogador* pJ)
    {
        pJogador1 = pJ;
        
        if(pJogador1 == NULL)
            cout << "Erro em Entidades::Personagens::Inimigos::Inimigo::setpJogador1() :"
                 << ERRO_NULLPTR << endl;
    }

    void Inimigo::setpJogador2(Jogador* pJ)
    {
        pJogador2 = pJ;
        
        if(pJogador2 == NULL)
            cout << "Erro em Entidades::Personagens::Inimigos::Inimigo::setpJogador1() :"
                 << ERRO_NULLPTR << endl;
    }

} // namespace Inimigos
