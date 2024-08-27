#ifndef _LISTA_ENTIDADES_HPP
#define _LISTA_ENTIDADES_HPP

//#include "Ente.hpp"
#include <iostream>
#include "Entidades/Entidade.hpp"
#include "Listas/Lista.hpp"
#include "Erros.hpp"

using namespace std;
using namespace Entidades;
using namespace Listas;

namespace Listas
{

    class ListaEntidades
    {
    private:
        Lista<Entidade> LE; // Lista indireta de entidades

        Lista<Entidade>::Iterador it;
        float gravidade;

        void operator++(int)  { it++; };
        void operator++()     { it++; };    

    public:

        ListaEntidades();
        ~ListaEntidades();

        void setGravidade(const float grav){ gravidade = grav; }

        void percorrer(float deltaT);
        void irAoInicio() { LE.inicializa(it); }

        void incluir(Entidade* pE);
        void remover(Entidade* pE) { LE.removeElemento( LE.buscaElemento(pE) ); }
    };
}

#endif