#include "Inimigo.hpp"
#include "Erros.hpp"

#include <iostream>
using namespace std;

namespace Inimigos
{       
    Inimigo::Inimigo(int maxVida, int dano, Jogador* pJ):
    Personagem(maxVida),
    dano(dano),
    pJogador(pJ)
    {
        if(pJogador == NULL)
            cout << "Erro em Entidades::Personagens::Inimigos::Inimigo::Inimigo() em pJogador: "
                 << ERRO_NULLPTR << endl;
    }

    Inimigo::~Inimigo()
    {
        dano = -1;
        pJogador = NULL;
    }

    void Inimigo::setDano(const int d)
    {
        dano = d;
    }
    const int Inimigo::getDano() const
    {
        return dano;
    }

    void Inimigo::setpJogador(Jogador* pJ)
    {
        pJogador = pJ;
        
        if(pJogador == NULL)
            cout << "Erro em Entidades::Personagens::Inimigos::Inimigo::setpJogador() :"
                 << ERRO_NULLPTR << endl;
    }

    Jogador* Inimigo::getpJogador() const
    {
        if(pJogador == NULL)
            cout << "Erro em Entidades::Personagens::Inimigos::Inimigo::getpJogador() :"
                 << ERRO_RETURN_NULLPTR << endl;

        return pJogador;
    }
} // namespace Inimigos
