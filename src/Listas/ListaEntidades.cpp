#include "Listas/ListaEntidades.hpp"
using namespace Listas;

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
        enterFechar();
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
            //atual->getInfo()->executar();
            (*this)++;
        }
        else
        {
            cout << "Em funcao ListaEntidades::percorrer: " << ERRO_NULLPTR_LISTA << endl;
            enterFechar(); 
        }
    }
}