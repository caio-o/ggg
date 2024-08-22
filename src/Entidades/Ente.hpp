#ifndef _ENTE_HPP
#define _ENTE_HPP

#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "SFML/Graphics.hpp"

/**
 *  Nao temos ainda o desacoplamento da classe sf::Shape e similares
 * Seria bom substituir RectangleShape por Shape nesta e nas outras classes,
 * visto que poderiamos usar outras formas (circulos, triangulos, etc.)
 */
typedef sf::Shape Figura;

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
    Figura* pFigura;
    // ...

public:
    Ente(Figura* const _pFigura = NULL);
    virtual ~Ente();

    virtual void executar () = 0;
    void         desenhar ();
    
    Figura*      getFigura  () const  { return pFigura; }
    const int    getId      () const  { return id;      }

    // Permite-se pFigura NULL em entes invisiveis.
    void setFigura (Figura* _pFigura) { pFigura = _pFigura; } 
    
    static void setGerenciadorGrafico () { pGG = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico(); }
}; 
//Gerenciadores::GerenciadorGrafico*  Ente::pGG        = NULL;
//int                      Ente::contEntes  = 0;

#endif