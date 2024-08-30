#pragma once

#include "SFML/Graphics.hpp"
#include <vector>

#include "ElementosGraficos/Forma.hpp"
#include "ElementosGraficos/Texto.hpp"

#include "Ente.hpp"

using namespace std;

namespace Menus
{
    class Menu: public Ente
    {
        protected:
            ElementosGraficos::Texto titulo;
            ElementosGraficos::Forma fundo;

            //provisorio: posteriormente usar elemento gráfico Botao proprio
            vector<ElementosGraficos::Texto*> opcoes;
            

        public:
            Menu(){}
            virtual ~Menu(){}

            virtual void executar(const float dT) = 0;
            virtual void desenhar() = 0;
    };
} // namespace Menus
