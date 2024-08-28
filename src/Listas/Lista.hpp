/**
 *   AUTOR: Caio e Silva Barbieri (caio-o).
 *   Arquivo com definicao da classe Listas::Lista.
 * A implementacao tambem se encontra aqui, devido
 * ao uso de gabaritos (template<class TL>).
 *   DATA: 27/08/2024
 *   OBS: A funcao "imprimir" nao pode ser usada com todos os tipos, e foi incluida para fins de testes.
 */

#ifndef _LISTA_HPP
#define _LISTA_HPP
#include <iostream>
#include "Erros.hpp"
//#include "IteradorAbstrato.hpp"
using std::cout;
using std::endl;

namespace Listas
{
    /**
     *    LISTA TEMPLATE, alla stl::List. Contem classes aninhadas ELEMENTO e ITERADOR.
     *  LISTA: Lista INDIRETA duplamente encadeada, comfuncoes de adicionar, remover e buscar elementos,
     *  alem de um metodo imrimir (QUE SO FUNCIONA SE ESTIVER DEFINIDO cout << TL).
     */
    template<class TL>
    class Lista 
    {

    public: 
        /**      MODO DE INSTANCIAR ou REFERENCIAR: Lista<TIPO>::Elemento.
         *    ELEMENTO: Nodo duplamente encadeado, usado na estrutura interna da lista.
         */
        class Elemento
        {
        private:
            TL*         pInfo; // A lista eh indireta (armazena como ptr. TL*). 
            Elemento*   pProx; // Ptr. para proximo nodo.
            Elemento*   pAnt;  // Ptr. para proximo nodo.

        public:
            Elemento(TL* _pInfo = NULL);
            ~Elemento(); // Destrutora desaloca pInfo, mas nao pProx.

            TL*            getInfo () const          { return pInfo;   }
            void           setInfo (TL* _pInfo)      { pInfo = _pInfo; } 
            // Talvez seja bom sobrecarregar para setInfo(TL info) (sem ponteiro).

            Elemento*      getProx () const          { return pProx;   }
            void           setProx (Elemento* p)     { pProx = p;      }

            Elemento*      getAnt  () const          { return pAnt;    }
            void           setAnt  (Elemento* p)     { pAnt = p;       }

            // Funcao ateh agora nao utilizada.
            void  trocaAdiante();        // Troca o elemento de lugar com o da frente 
        };




         
        /**
         * << ITERATOR >> Classe para percorrer a lista e acessar seus elementos. Não é ainda desacoplado por classe abstrata.
         *     Classe Lista<TL>::Iterador herda de IteradorAbstrato.
         */
        class Iterador /*: public IteradorAbstrato<Elemento>*/
        {
        private:
            // Referencia para o elemento. Foi usada na Lista Entidades para remover elementos, 
            // se bem que possamos fazer uma sobrecarga de metodo remover( iterador ) e eliminar o acesso ao elemento.
            Elemento* elem; 

        public:
            Iterador();
            ~Iterador();
            
            TL*  get     () const; // Retorna a informacao apontada do elemento da lista.
            void set     (TL* p);  // Escolhe a informacao apontada do elemento da lista.
            Elemento* getElem () const;
            void setElem (Elemento* _elem) { elem = _elem; }

            // Retorna true se o proximo elemento nao eh NULL,
            // senao retorna false.
            const bool temProximo() const;

            // Retorna true se o iterador chegou ao fim da lista (a saber, se o seu elemento eh NULL),
            // senao retorna false.
            const bool fim();  

            Iterador& operator++();    // Passa a apontar para o proximo nodo.
            Iterador& operator++(int); // idem.
        };






        // Aqui comeca a classe Lista propriamente dita
    private:
        Elemento* pPrimeiro; // head
        Elemento* pUltimo;   // tail

    public:
        Lista();
        ~Lista();

        bool  vazia       ( )   { return pPrimeiro == NULL; } // Ignorar o warning. NAO FAZER TYPECAST (bool)pPrimeiro 

        void  anulaPtrs   ( );                 // Anula pPrimeiro e pUltimo

        void  push_front  (TL* dados);         // Adicionar na pos. 0 (primeira).
        void  push_back   (TL* dados);         // Adicionar na pos. ultima.
        void  push_n      (TL* dados, int n);  // Adicionar na pos. N, ou no limite, caso N o ultrapasse. 

        void  pop_front   ();                  // Remove da pos. 0 (primeira)

        Elemento*   getPrimeiro () const  { return pPrimeiro; }
        Elemento*   getUltimo   () const  { return pUltimo; }
        //void      getN        (const int n);
        //void      setN        (const int n);

        void inicializa(Iterador &it) { it.setElem(pPrimeiro); }

        void        setPrimeiro (TL* p);       // Incongruente com os gets. Com maior tempo poderia ajustar, mas por enquanto deixe assim. 
        void        setUltimo   (TL* p);


        Elemento*   buscaElemento  (TL *dados);
        //void      removeDados    (TL* dados);
        void removeElemento      (Elemento* elem);
        void remove(Iterador *it);

        // ATENCAO: NAO FUNCIONA COM TODOS OS TIPOS. Eh preciso que esteja definido o operador "<<" para o tipo TL.
        void  imprimir(); 
    };
} using namespace Listas;







//-------------------------------------//
// Implementacoes da classe Elemento   //
template<class TL> 
Lista<TL>::Elemento::Elemento (TL* _pInfo):
    pInfo (_pInfo),
    pAnt  (NULL),
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

    pInfo = NULL;
    pProx = NULL;
    pAnt  = NULL;
}

template<class TL> 
void Lista<TL>:: Elemento::trocaAdiante()
{
    TL* aux = pProx->getInfo();
    pProx->setInfo(pInfo);
    pInfo = aux;
}






//-------------------------------------//
// Implementacoes da classe Iterador   //
template<class TL>
const bool Lista<TL>::Iterador::fim()
{
    return (elem == NULL);
}

template<class TL>
TL* Lista<TL>::Iterador::get() const
{ 
    //cout << "Lista<TL>::Iterador::GET"<< endl;
    if(elem) { return elem->getInfo(); }
    else
    {
        cout << "Em Lista<TL>::Iterador::get: " << ERRO_NULLPTR << endl;
        return NULL;
    } 
}

template<class TL>
Lista<TL>::Iterador::Iterador():
    elem(NULL)
{ }

template<class TL>
Lista<TL>::Iterador::~Iterador()
{ }

template<class TL>
const bool Lista<TL>::Iterador::temProximo() const
{
    return (bool)(elem && elem->getProx());
}

template<class TL>
void Lista<TL>::Iterador::set(TL* p) 
{ 
    if (elem) { elem->setInfo(p); }
}

template<class TL>
typename Lista<TL>::Iterador& Lista<TL>::Iterador::operator++()
{
    if (!fim())
    {
        elem = elem->getProx();
        return *this;
    }
    else 
    {
        elem = NULL;
        return *this;
    }
}

template<class TL>
typename Lista<TL>::Iterador& Lista<TL>::Iterador::operator++(int)
{
    return ++(*this);
}

template<class TL>
typename Lista<TL>::Elemento* Lista<TL>::Iterador::getElem () const 
{ 
    if(elem) return elem;
    else
    {
        cout << "ERRO em Lista<TL>::Iterador::getElem: " << ERRO_RETURN_NULLPTR << endl;
        return NULL;
    }
}
/*
template<class TL>
void Lista<TL>::Iterador::remover()
{
    if(elem->getAnt())
    {
        elem->getAnt()->setProx(elem->getProx());
        elem->getProx()->setAnt(elem->getAnt());
        delete(elem);
    }
    else if(elem->getProx())
    {
        
    }
    else
    {
        delete
    }
}*/







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

/**
 * TODO: Considerar se devemos checar sucesso de alocacao antes de
 *      incluir elementos na lista (como o Simão faz). Vou perguntar
 *      aos monitores no curso.
 */
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
            aux->setAnt(pPrimeiro);
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
            push_front(dados);
        }
        else
        { 
            Elemento* aux = pUltimo;

            pUltimo = new Elemento(dados);
            aux->setProx(pUltimo);
            pUltimo->setAnt(aux);
        }
    }

    else
    {
        cout << "Em funcao Lista<TL>::push_back: " << ERRO_INCLUI_NULLPTR << endl << endl;
    }
}

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
                aux->setAnt    (atual->getProx());
                novoElemento->setAnt(atual);
            }
            else // Entao atual == pUltimo
            {
                atual->setProx(novoElemento);
                novoElemento->setAnt(atual);
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
void Lista<TL>::setPrimeiro(TL* p)
{
    if (pPrimeiro) { pPrimeiro->setInfo(p); }
    else           { push_front(p); }
}

template<class TL>
void Lista<TL>::setUltimo(TL* p)
{
    if (pUltimo)  { pUltimo->setInfo(p); }
    else          { push_back(p); }
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

template<class TL>
typename Lista<TL>::Elemento* Lista<TL>::buscaElemento(TL* dados)
{
    Iterador it;
    inicializa(it);

    while(! it.fim() )
    {
        if(it.get() ==  dados)
        {
            return it.getElem();
        }

        it++;
    }

    return NULL;
}
/*
template<class TL>
void Lista<TL>::removeDados(TL* dados)
{
    Elemento* aux = buscaElemento(dados);
    if(aux)
    {

    }
}*/

template<class TL>
void Lista<TL>::pop_front()
{
    if(!vazia())
    {
        Elemento* aux = pPrimeiro;
        pPrimeiro = pPrimeiro->getProx();
        
        if(pPrimeiro)
            pPrimeiro->setAnt(NULL);
        
        if(pUltimo == aux) { pUltimo = pPrimeiro; }
        
        delete aux;
    }
}

template<class TL>
void Lista<TL>::removeElemento(Elemento* elem)
{
    if(elem->getAnt())
    {
        elem->getAnt()->setProx(elem->getProx());
    }
    if(elem->getProx())
    {
        elem->getProx()->setAnt(elem->getAnt());
    }
    
    if(elem == pPrimeiro)
    {
        pPrimeiro = elem->getProx();
    }
    if(elem == pUltimo)
    {
        pUltimo = elem->getAnt();
    }

    delete elem;
}

template<class TL>
void Lista<TL>::remove(Iterador *it)
{
    Elemento* elem = it->getElem();
    (*it)++;

    removeElemento(elem);

    it->setElem(it->getElem()->getAnt());

    delete elem;
    // TODO: FAZER OPERATOR--()
}

#endif /// _LISTA_HPP
