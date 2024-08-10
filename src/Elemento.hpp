/**
 *   AUTOR  : Caio e Silva Barbieri (caio-o).
 *   DATA   : 10/08/2024 10:43
 *   Arquivo com definicao e implementacao da classe Listas::Elemento.
 */

#ifndef _ELEMENTO_HPP
#define _ELEMENTO_HPP

#include <iostream>
#include "Erros.hpp"
using std::cout;
using std::endl;

namespace Listas 
{

    /*template<class TE>
    class Elemento;*/

    template<class TE>
    class Elemento
    {
    private:
        TE*             pInfo;
        Elemento<TE>*   pProx;

    public:
        Elemento(TE* _pInfo = NULL);
        
        ~Elemento(); // Destrutora desaloca pInfo, mas nao pProx.

        TE*            getInfo () const          { return pInfo;   }
        void           setInfo (TE* _pInfo)      { pInfo = _pInfo; } 

        Elemento<TE>*  getProx () const          { return pProx; }
        void           setProx (Elemento<TE>* p) { pProx = p;    }

        void  trocaAdiante();        
    };
}

/// IMPLEMENTACOES ("template classes" e "template functions" so podem ser implementados no .hpp)

template<class TE> 
Listas::Elemento<TE>::Elemento (TE* _pInfo):
    pInfo (_pInfo),
    pProx (NULL)
{ }

template<class TE> 
Listas::Elemento<TE>::~Elemento()
{
    if (pInfo) 
    { 
        delete pInfo; 
    }
    else 
    {
        cout << "Em funcao Elemento::~Elemento: " << ERRO_DELETE_NULLPTR << endl;
    }
}

template<class TE>
void Listas::Elemento<TE>::trocaAdiante()
{
    TE* aux = pProx->getInfo();
    pProx->setInfo(pInfo);
    pInfo = aux;
}
#endif