#ifndef _PERSONAGEM_HPP
#define _PERSONAGEM_HPP

#include "Entidades/Ente.hpp"
#include "Entidades/Entidade.hpp"
using namespace Entidades;

class Personagem: public Entidade
{
protected:
    int maxVida;
    int vida;
    bool vivo;

public:
    Personagem(int maxVida = 10);
    virtual ~Personagem();

    //ADIÇÃO ana-molinos
    virtual void salvar() = 0;
    virtual void executar () = 0;
    virtual void mover() = 0;
    virtual void atacar() = 0;

    void        setMaxVida (int _max)   { maxVida = _max;   }
    void        setVida    (int _vida)  { vida = _vida;     }
    void        checarVida ()           { vivo = (vida>0);  }
    
    const int   getMaxVida () const     { return maxVida;   }
    const int   getVida    () const     { return vida;      }
    const bool  getVivo    () const     { return vivo;      }
};

#endif