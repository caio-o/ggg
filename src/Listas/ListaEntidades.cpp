#include "Listas/ListaEntidades.hpp"
#include <SFML/System.hpp>
#include "Gerenciadores/GerenciadorColisoes.hpp"

using namespace Listas;

ListaEntidades::ListaEntidades():
    LE(),
    gravidade(1000.f)
{
        
}

ListaEntidades::~ListaEntidades()
{
    LE.destroiObjetos();
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

void ListaEntidades::percorrer(float deltaT)
{
    irAoInicio();
    Entidade *p;
    while(! it.fim())
    {
        p = it.get();
        if(p)
        {
            if(p->getAtivo())
            {
                // if(it.get()->estahAtiva()) { ... }
                p->executar(deltaT);

                p->moverse(deltaT);
                p->aceleraY( deltaT * (gravidade + (p->getAcelVertical())) );

                p->desenhar();
            }
            
            (*this)++;
        }
        else
        {
            cout << "Em funcao ListaEntidades::percorrer: " << ERRO_NULLPTR_LISTA << endl;
            enterFechar(); 
        }
    }
}