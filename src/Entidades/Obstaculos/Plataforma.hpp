#ifndef _PLATAFORMA_HPP
#define _PLATAFORMA_HPP

#include "Entidades/Obstaculos/Obstaculo.hpp"
#include <iostream>
#include <fstream>

namespace Entidades::Obstaculos
{
    class Plataforma : public Obstaculo
    {
    private:
        ElementosGraficos::Cores cor;

    public:
        Plataforma(float largura = 300.f, float altura = 50.f, Especie _especie = plataforma);

        ~Plataforma() { }

        void executar(const float dT) { }
        virtual void obstacular(Jogador* pJog) { }

        void salvar(std::ofstream &ofs);
        void carregar(nlohmann::ordered_json &j);

        void setCor(ElementosGraficos::Cores _cor) { cor = _cor; }
    };
}

#endif