#include "Entidades/Obstaculos/PlataformaGrudenta.hpp"
#include "PlataformaGrudenta.hpp"

#define PEGAJOSIDADE 3.5F

Entidades::Obstaculos::
PlataformaGrudenta::PlataformaGrudenta(float tamX, float tamY):
    Plataforma(tamX, tamY, Especie::plataformaGrudenta),
    pegajosidade(PEGAJOSIDADE)
{
    getForma()->getpCorpo()->setFillColor(sf::Color::White);
}

Entidades::Obstaculos
::PlataformaGrudenta::~PlataformaGrudenta()
{
}

void Entidades::Obstaculos::
PlataformaGrudenta::obstacular(Jogador *pJog)
{
    pJog->setLentidao(pegajosidade);
}