#include "Fases/Tuneis.hpp"
#include "Entidades/Obstaculos/Lapis.hpp"
#include "Tuneis.hpp"

namespace Fases{

}
void Fases::Tuneis::criarLapis(float posX, float posY, int dano)
{
    Obstaculos::Lapis *pLap = new Obstaculos::Lapis();
    
    if(pLap)
    {
        pLap->setPos(posX, posY);
        colecao.incluir(static_cast<Entidade*> (pLap));
        pGC->inserirObstaculo(static_cast<Obstaculo*> (pLap));
    }
}

void Fases::Tuneis::criarObstaculos()
{
}

void Fases::Tuneis::criarInimigos()
{
}
