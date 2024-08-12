/**
 *   AUTOR: Caio e Silva Barbieri (caio-o).
 *   Arquivo com definicao da classe Listas::Lista.
 * A implementacao tambem se encontra aqui, devido
 * ao uso de gabaritos (template<class TL>).
 * 
 *   OBS: A funcao "imprimir" nao pode ser usada com todos os tipos. e foi incluida para fins de testes.
 */

#ifndef _LISTA_HPP
#define _LISTA_HPP

#include <iostream>
#include "Erros.hpp"
using std::cout;
using std::endl;

namespace Listas
{
    template<class TL>
    class Lista // A lista eh indireta. Posto que o parametro seja "TL", ela armazena "TL*".
    {
    public: class Elemento
        {
        private:
            TL*         pInfo;
            Elemento*   pProx;

        public:
            Elemento(TL* _pInfo = NULL);
        
            ~Elemento(); // Destrutora desaloca pInfo, mas nao pProx.

            TL*            getInfo () const          { return pInfo;   }
            void           setInfo (TL* _pInfo)      { pInfo = _pInfo; } 

            Elemento*      getProx () const          { return pProx; }
            void           setProx (Elemento* p)     { pProx = p;    }

            void  trocaAdiante();        
        };





        /// Aqui comeca a classe Lista propriamente dita
    private:
        Elemento* pPrimeiro;
        Elemento* pUltimo;

    public:
        Lista();
        ~Lista();

        bool  vazia       ( )   { return pPrimeiro == NULL; }

        void  anulaPtrs   ( );

        void  push_front  (TL* dados);         // Adicionar na pos. 0
        void  push_back   (TL* dados);         // Adicionar na pos. ultima
        void  push_n      (TL* dados, int n);  // Adicionar na pos. N

        Elemento*   getPrimeiro () const  { return pPrimeiro; }
        void        setPrimeiro (TL* p);
        
        Elemento*   getUltimo   () const  { return pUltimo; }
        void        setUltimo   (TL* p);

        //void  getN        (const int n);
        //void  setN        (const int n);

        void  imprimir();
    };
} using namespace Listas;







//-------------------------------------//
// Implementacoes da classe Elemento   //
template<class TL> 
Lista<TL>::Elemento::Elemento (TL* _pInfo):
    pInfo (_pInfo),
    pProx (NULL)
{ }

template<class TL> 
Lista<TL>::Elemento::~Elemento()
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

template<class TL> 
void Lista<TL>:: Elemento::trocaAdiante()
{
    TL* aux = pProx->getInfo();
    pProx->setInfo(pInfo);
    pInfo = aux;
}


//-------------------------------------//
// Implementacoes da classe Lista      //

template<class TL>
Lista<TL>::Lista():
    pPrimeiro (NULL),
    pUltimo   (NULL)
{ }

template<class TL>
Lista<TL>::~Lista()
{
    Elemento* atual = pPrimeiro;
    Elemento* aux;

    while(atual != NULL)
    {
        aux   = atual;
        atual = atual->getProx();
        
        delete aux; // se houver problema na delecao, ~Elemento() avisarah
    }
}

template<class TL>
void Lista<TL>::anulaPtrs()
{
    pPrimeiro = NULL;
    pUltimo   = NULL;
}

template<class TL>
void Lista<TL>::push_front(TL* dados)
{
    if(dados)
    {
        if(!vazia())
        {
            Elemento* aux = pPrimeiro;
            pPrimeiro     = new Elemento(dados);

            pPrimeiro->setProx(aux);
        }
        else
        {
            pPrimeiro = new Elemento(dados); // OBS.: pProx = NULL
            pUltimo = pPrimeiro;
        }
    }

    else
    {
        cout << "Em funcao Lista<TL>::push_back: " << ERRO_INCLUI_NULLPTR << endl << endl;
    }
}

template<class TL>
void Lista<TL>::push_back(TL* dados)
{
    if(dados)
    {
        if(vazia())
        { // Por simplicidade, talvez devamos apenas dar "push_front"
            pPrimeiro = new Elemento(dados); // OBS.: pProx = NULL
            pUltimo   = pPrimeiro;
        }
        else
        {
            Elemento* aux = pUltimo;

            pUltimo = new Elemento(dados);
            aux->setProx(pUltimo);
        }
    }

    else
    {
        cout << "Em funcao Lista<TL>::push_back: " << ERRO_INCLUI_NULLPTR << endl << endl;
    }
}

/** 
 * 
 * 
*/
template<class TL>
void Lista<TL>::push_n(TL* dados, int n)
{
    if (dados)
    {
        if(!vazia() && n != 0)
        {
            int i;
            Elemento* novoElemento = new Elemento(dados);
            Elemento* atual  = pPrimeiro;
            Elemento* aux    = NULL;

            // Se for encontrado um nullptr, assumir-se-ah que chegou-se ao fim da lista.
            for (i = 0; i < n-1 && atual; i++)  
            {
                atual = atual->getProx();
            }

            if(atual->getProx())
            {
                aux = atual->getProx();
                atual->setProx (novoElemento);
                atual->getProx ()->setProx(aux);
            }
            else // Entao atual == pUltimo
            {
                atual->setProx(novoElemento);
                pUltimo = novoElemento;
            }
        }
        else
        {
            push_front(dados);
        }
    }
    else
    {
        cout << "Em funcao Lista<TL>::push_n: " << ERRO_INCLUI_NULLPTR << endl << endl;
    }
}

template<class TL>
void Lista<TL>::imprimir()
{
    Elemento* atual = pPrimeiro;
    Elemento* aux;

    cout << "{ ";
    while(atual != NULL)
    {
        cout << *(atual->getInfo()) << " ";
        atual = atual->getProx();
    }
    cout << "} " << endl;
}

#endif /// _LISTA_HPP