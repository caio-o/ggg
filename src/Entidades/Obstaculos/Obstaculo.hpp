#ifndef _OBSTACULO_HPP
#define _OBSTACULO_HPP

#include "Entidades/Entidade.hpp"

namespace Entidades
{
namespace Obstaculos
{
    class Obstaculo : public Entidade
    {
    private:
        const bool permeavel; // A ser definida na construtora de cada obstaculo.
    
    public:
        Obstaculo(Especie _especie = indefinido, const bool _permeavel = false):
            Entidade(_especie),
            permeavel(_permeavel)
        {
            getForma()->getpCorpo()->setTexture(NULL);
            setTamanho(100.f, 100.f);
            getForma()->getpCorpo()->setFillColor (sf::Color((sf::Uint8)200, (sf::Uint8)200, (sf::Uint8)200));
            setAcelVertical(1000.f);
        }

        virtual ~Obstaculo()
        { }

        virtual void executar (const float dT) = 0;

        virtual void reagirAhColisao(Entidade *pE) = 0;

        const bool getPermeavel() const { return permeavel; }
    };
}
}

#endif