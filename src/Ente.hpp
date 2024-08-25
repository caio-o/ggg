#ifndef _ENTE_HPP
#define _ENTE_HPP

#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "SFML/Graphics.hpp"
#include "ElementosGraficos/Forma.hpp"

using namespace ElementosGraficos;

/// << CLASSE ABSTRATA >> Base para Entidade
class Ente
{
protected:
    static int      contEntes;
    const int id;
    static Gerenciadores::GerenciadorGrafico* pGG;
    //Forma *pForma; não precisa de forma em ente, só em entidade

public:
    Ente(/*Forma* _pForma = NULL*/);
    virtual ~Ente();

    virtual void executar (const float dT) = 0;
    virtual void desenhar ();
    
    //Forma*       getForma   () const  { return pForma; }
    const int    getId      () const  { return id;      }

    // Permite-se pForma NULL em entes invisiveis. 
    // TODO: MUDAR ISSO
    //void setForma (Forma* _pForma)        { pForma = _pForma; } 
    static void setGerenciadorGrafico ()  { pGG = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico(); }
}; 

#endif