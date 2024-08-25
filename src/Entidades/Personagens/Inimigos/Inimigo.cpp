#include "Inimigo.hpp"
#include "Erros.hpp"

#include <iostream>
using namespace std;

namespace Inimigos
{
    Jogador* Inimigo::pJogador1(NULL); //Jogador* Inimigo::pJogador1(Fase::pJogador1);
    Jogador* Inimigo::pJogador2(NULL); //Jogador* Inimigo::pJogador2(Fase::pJogador2);

    Inimigo::Inimigo(int maxVida, int dano):
    Personagem(maxVida),
    dano(dano)
    {
        
        /*if(pJogador1 == NULL)
            cout << "'Erro em Entidades::Personagens::Inimigos::Inimigo::Inimigo() em pJogador1: "
                 << ERRO_NULLPTR << endl;*/
    }

    Inimigo::~Inimigo()
    {
        dano = -1;
        maxVida = -1;
        vida = -1;
        vivo = false;
    }

    void Inimigo::setDano(const int d)
    {
        dano = d;
    }
    const int Inimigo::getDano() const
    {
        return dano;
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
