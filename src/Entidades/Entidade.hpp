#ifndef _ENTIDADE_HPP
#define _ENTIDADE_HPP

#include <SFML/System.hpp>
#include <time.h>
#include "Entidades/Ente.hpp"
#include "Coordenada.hpp"

#include "ElementosGraficos/Forma.hpp"

#define GRAVIDADE 1.0f

using namespace Coordenadas;
using namespace ElementosGraficos;

namespace Entidades
{
    // << CLASSE ABSTRATA >>
    class Entidade : public Ente
    {
    protected:
        Vetor2f pos;
        Coordenadas::Vetor2f tam;
        Vetor2f vel;
        Vetor2f modGravidade;
        //Coordenada<float> modGravidade;

        Forma forma;

    public:
        Entidade();
        Entidade(Forma _forma);
        virtual ~Entidade();

        void setForma  (Forma _forma)        { forma = _forma; } 
        Forma*         getForma () const  { return (Forma*)(&forma); }
        // Diferencia-se do Ente::desenhar porque precisa atualizar a posicao da forma.
        void           desenhar (); 
        virtual void   executar () = 0;
        void   moverse  (const float n_segundos);
        //virtual void   acelerarse (const float acel, const float deltaT) { vel += acel*deltaT; };

        const Vetor2f  getVel   () const   { return vel;   }
        const Vetor2f  getPos   () const   { return pos;   }
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