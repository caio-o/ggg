#ifndef _ENTIDADE_HPP
#define _ENTIDADE_HPP

#include <SFML/System.hpp>
#include <time.h>
#include "Entidades/Ente.hpp"
#include "Coordenada.hpp"

#define GRAVIDADE 1.0f

// O mesmo que Coordenada<float>.
typedef Coordenada<float> vetor2f;

namespace Entidades
{
    // << CLASSE ABSTRATA >>
    class Entidade : public Ente
    {
    protected:
        vetor2f pos;
        //vetor2f tam;
        vetor2f vel;
        vetor2f modGravidade;
        //Coordenada<float> modGravidade;

    public:
        Entidade(Figura* const _pFigura = NULL);
        virtual ~Entidade();

        virtual void   executar () = 0;
        virtual void   moverse  (const float deltaT);
        //virtual void   acelerarse (const float acel, const float deltaT) { vel += acel*deltaT; };

        const vetor2f  getVel   () const   { return vel;   }
        const vetor2f  getPos   () const   { return pos;   }
        const float    getX     () const   { return pos.x; }
        const float    getY     () const   { return pos.y; }

        void  setVel   (const float _x, const float _y)  { vel.x = _x; vel.y = _y; }
        void  setPos   (const float _x, const float _y)  { pos.x = _x; pos.y = _y; }
        void  setX     (const float _x)                  { pos.x = _x;             }
        void  setY     (const float _y)                  { pos.y = _y;             }
        void  setVelX  (const float _x)                  { vel.x = _x;             }
        void  setVelY  (const float _y)                  { vel.y = _y;             }
    };
} 
#endif