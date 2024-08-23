#ifndef _FASE_HPP
#define _FASE_HPP

#include "Listas/ListaEntidades.hpp"

class Fase : public Ente
{
private:
    ListaEntidades entidades;
    //ERRO DE COMPILAÇÃO: FALTA A IMPLEMENTAÇÃO DESSA FUNÇÃO
    //virtual void criarObstaculos() = 0;

public:
    Fase();
    virtual ~Fase();
    
    virtual void executar();
    virtual void salvar  ();
};

#endif