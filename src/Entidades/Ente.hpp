#ifndef _ENTE_HPP
#define _ENTE_HPP

#include "Gerenciadores/Grafico.hpp"
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
    //const int       idObj;
    const ID_Classe id;
    static Gerenciadores::Grafico* pGG;
    Figura* pFigura;
    // ...

public:
    Ente(const ID_Classe _id = ID_Classe::indefinido, Figura* const _pFigura = NULL);
    virtual ~Ente();

    virtual void executar () = 0;
    void         desenhar ();
    
    Figura*          getFigura  () const  { return pFigura; }
    const ID_Classe  getId      () const  { return id;      }

    // Permite-se pFigura NULL em entes invisiveis.
    void setFigura (Figura* _pFigura) { pFigura = _pFigura; } 
    //sem setID --> ID constante escolhido na construtora de cada classe.
    
    static void setGerenciadorGrafico () { pGG = Gerenciadores::Grafico::getGrafico(); }
}; 
Gerenciadores::Grafico*  Ente::pGG        = NULL;
int                      Ente::contEntes  = 0;

#endif