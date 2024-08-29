#include "Entidades/Obstaculos/Obstaculo.hpp"
#include "Entidades/Personagens/Jogador.hpp"

namespace Entidades::Obstaculos
{
    Obstaculo::Obstaculo(Especie _especie, const bool _permeavel):
        Entidade(_especie),
        permeavel(_permeavel)
    {
        getForma()->getpCorpo()->setTexture(NULL);
        setTamanho(100.f, 100.f);
        getForma()->getpCorpo()->setFillColor (sf::Color((sf::Uint8)128, (sf::Uint8)128, (sf::Uint8)128));
        setAcelVertical(1000.f);
    }

    void Obstaculo::reagirAhColisao(Entidade *pE)
    {
        if(pE->getEspecie() == Especie::jogador) obstacular(static_cast<Jogador*> (pE));
    }
    
} // namespace Entidades::Obstaculos
