#include "Listas/ListaEntidades.hpp"
#include <SFML/System.hpp>
#include "Gerenciadores/GerenciadorColisoes.hpp"
#include "ListaEntidades.hpp"
#include <string>
#include <iostream>
#include <fstream>

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

void ListaEntidades::salvar(ofstream &ofs)
{
    irAoInicio();
    Entidade *p;
    while(! it.fim())
    {
        p = it.get();
        if(p)
        {
            if(p->getAtivo())
                p->salvar(ofs); 
            // talvez seja necessario fazer isto:
            // p->salvar(ofs, it.temProximo());
        }
        else
        {
            cout << "Em funcao ListaEntidades::salvar: " << ERRO_NULLPTR_LISTA << endl;
            enterFechar(); 
        }

        (*this)++;
    }
    ofs << "{\"especie\":-1}" << endl;
}

/*void Listas::ListaEntidades::carregar(ifstream &ifs)
{
    nlohmann::ordered_json j;
    string linha;
    std::getline(ifs, linha);
    j = linha;

    if(! j.is_null())
    {
        while(j["especie"] != -1)
        {
            linha = "";
            std::getline(ifs, linha);
            j = linha;

            if(j["especie"] == jogador)
            {
                
            }
        }
    }
}*/

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