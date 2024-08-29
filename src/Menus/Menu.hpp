#pragma once

#include "SFML/Graphics.hpp"
#include <vector>

#include "ElementosGraficos/Forma.hpp"

using namespace std;

namespace Menus
{
    class Menu
    {
        protected:
            //provisorio: posteriormente usar elemento gráfico Texto proprio
            sf::Text titulo; 
            //provisorio: posteriormente usar elemento gráfico Botao proprio
            vector<ElementosGraficos::Forma*> colecaoBotoes;

        public:
            Menu(){}
            virtual ~Menu(){}

            virtual void executar(const float dT) = 0;
            virtual void desenhar() = 0;
    };
} // namespace Menus
