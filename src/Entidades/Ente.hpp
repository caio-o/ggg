#ifndef _ENTE_HPP
#define _ENTE_HPP

#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "SFML/Graphics.hpp"
#include "ElementosGraficos/Forma.hpp"

using namespace ElementosGraficos;

enum ID_Classe
{
    indefinido = 0,
    jogador,
    amigo,
    projetilAmigo
};

/// << CLASSE ABSTRATA >> Base para Entidade
class Ente
{
protected:
    static int      contEntes;
    //const ID_Classe id;
    const int id;
    static Gerenciadores::GerenciadorGrafico* pGG;
    Forma *pForma;

public:
    Ente(Forma* _pForma = NULL);
    virtual ~Ente();

    virtual void executar () = 0;
    virtual void desenhar ();
    
    Forma*       getForma   () const  { return pForma; }
    const int    getId      () const  { return id;      }

    // Permite-se pForma NULL em entes invisiveis. 
    // TODO: MUDAR ISSO
    void setForma (Forma* _pForma)        { pForma = _pForma; } 
    static void setGerenciadorGrafico ()  { pGG = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico(); }
}; 

#endif