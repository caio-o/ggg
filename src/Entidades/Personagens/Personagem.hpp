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
    Personagem(Figura* _pFigura = NULL, int maxVida = 10);
    virtual ~Personagem();

    virtual void executar () = 0;

    void        setMaxVida (int _max)   { maxVida = _max;   }
    void        setVida    (int _vida)  { vida = _vida;     }
    void        checarVida ()           { vivo = vida > 0;  }
    
    const int   getMaxVida () const     { return maxVida;   }
    const int   getVida    () const     { return vida;      }
    const bool  getVivo    () const     { return vivo;      }
};

#endif