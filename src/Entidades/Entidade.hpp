#ifndef _ENTIDADE_HPP
#define _ENTIDADE_HPP

#include <SFML/System.hpp>
#include <time.h>
#include "Ente.hpp"
#include "Coordenada.hpp"

#include "ElementosGraficos/Forma.hpp"
#include "json.hpp"

using namespace Coordenadas;
using namespace ElementosGraficos;

namespace Entidades
{
    enum Especie
    {
        indefinido = 0,
        jogador,
        inimigo,
        quadrado,
        triangulo,
        estrela,
        obstaculo,
        plataformaGrudenta,
        plataforma,
        lapis,
        projetil
    };

    // << CLASSE ABSTRATA >>
    class Entidade : public Ente
    {
    protected:
        Vetor2f pos;
        Vetor2f vel;
        float acelVertical;
        Especie especie;
        Forma forma;

        bool ativo;

    public:
        Entidade(Especie _especie = indefinido);
        virtual ~Entidade();

        void setTextura  (const char *caminho, const bool resetarTamanho = false);
        Forma*         getForma () const  { return (Forma*)(&forma); }
        // Diferencia-se do Ente::desenhar porque precisa atualizar a posicao da forma.
        void           desenhar (); 
        virtual void   executar (const float dT) = 0;
        virtual void   reagirAhColisao(Entidade* pE) { };
        void           moverse  (const float n_segundos);
        //virtual void   acelerarse (const float acel, const float deltaT) { vel += acel*deltaT; };

        const Vetor2f  getVel   () const   { return vel;   }
        const Vetor2f  getPos   () const   { return pos;   }
        const Vetor2f  getTam   () const;
        const float getAcelVertical() const{ return acelVertical; }
        const float    getX     () const   { return pos.x; }
        const float    getY     () const   { return pos.y; }
        const Especie  getEspecie() const  { return especie; }
        const bool     getAtivo () const   { return ativo; }
        
        void  setVel   (const float _x, const float _y)  { vel.x = _x; vel.y = _y; }
        void  setPos   (const float _x, const float _y)  { pos.x = _x; pos.y = _y; forma.atualizar(pos); }
        void  setPos   (const Vetor2f _pos            )  { pos = _pos;             forma.atualizar(pos); }
        void setAcelVertical(const float AV)             { acelVertical = AV; }

        void  setX     (const float _x)                  { pos.x = _x;             }
        void  setY     (const float _y)                  { pos.y = _y;             }
        void  setVelX  (const float _x)                  { vel.x = _x;             }
        void  setVelY  (const float _y)                  { vel.y = _y;             }
        void  setTamanho(const float x, const float y)   { forma.setTamanho(x, y); }
        void  setAtivo (const bool _ativo) { ativo = _ativo; }

        void aceleraX  (const float _x) { vel.x += _x; }
        void aceleraY  (const float _y) { vel.y += _y; }
        void acelera   (const float _x, const float _y) { aceleraX(_x); aceleraY(_y); }
        virtual void salvar(ofstream &ofs) = 0;
        virtual void carregar(nlohmann::ordered_json &j) = 0;
    };
} 

#endif