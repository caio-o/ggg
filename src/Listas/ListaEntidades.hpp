#ifndef _LISTA_ENTIDADES_HPP
#define _LISTA_ENTIDADES_HPP

//#include "Ente.hpp"
#include "Entidades/Entidade.hpp"
#include "Lista.hpp"
using namespace Entidades;
using namespace Listas;

class ListaEntidades
{
protected:
    Lista<Entidade> LE; // Lista indireta de entidades

public:
    /*class Iterator
    {
        
    };*/

    ListaEntidades();
    ~ListaEntidades();

    void percorrer();
    void incluir(Entidade* pE) { LE.push_front(pE); }

    //void operator++(int); // iterator++
    //void operator++();    // ++iterator
};

#endif