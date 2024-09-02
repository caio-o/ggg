#ifndef _PLATAFORMA_GRUDENTA_HPP
#define _PLATAFORMA_GRUDENTA_HPP

#include "Entidades/Obstaculos/Plataforma.hpp"
#include "Entidades/Personagens/Jogador.hpp"

namespace Entidades::Obstaculos
{

    class PlataformaGrudenta: public Plataforma
    {
    private:
        float pegajosidade;

    public:
        PlataformaGrudenta(float tamX = 300.f, float tamY = 100.f);
        ~PlataformaGrudenta();

        // Mehtodo chamado na colisao com o jogador.
        // Divide a velocidade horizontal do jogador por pegajosidade, e não permite que ele pule.
        void obstacular(Jogador *pJog);
        void retardar(Jogador *pJog);
    };
}


#endif