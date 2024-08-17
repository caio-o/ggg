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

        void operator++(int); // obj ++
        void operator++();    // ++ obj

    public:
        Lista<Entidade>::Elemento* atual; 
        //class iterator; // Iterador para percorrer a lista e acessar as entidades.

        ListaEntidades();
        ~ListaEntidades();

        void percorrer();

        void incluir(Entidade* pE);
    };

    ListaEntidades::ListaEntidades():
        LE(),
        atual(NULL)
    {
        
    }

    ListaEntidades::~ListaEntidades()
    {
        
    }

    void ListaEntidades::incluir(Entidade* pE) 
    { 
        if (pE)
        {
            LE.push_front(pE);     
        }
        else
        {
            cout << "Em funcao ListaEntidades::incluir: " << ERRO_INCLUI_NULLPTR << endl;
            fechaPrograma();
        }
    }

    void ListaEntidades::operator++() 
    {
        if(atual)
        {
            atual = atual->getProx();
        }
        else
        {
            cout << "Este eh o fim da lista!" << endl;
        }
    }

    void ListaEntidades::operator++(int) 
    {
        if(atual)
        {
            atual = atual->getProx();
        }
        else
        {
            cout << "Este eh o fim da lista!" << endl;
        }
    }

    void ListaEntidades::percorrer()
    {
        atual = LE.getPrimeiro();
        
        while(atual != NULL)
        {
            if(atual->getInfo())
            {
                atual->getInfo()->desenhar();
                atual->getInfo()->executar();
                (*this)++;
            }
            else
            {
                cout << "Em funcao ListaEntidades::percorrer: " << ERRO_NULLPTR_LISTA << endl;
                fechaPrograma(); 
            }
        }
    }
}

#endif