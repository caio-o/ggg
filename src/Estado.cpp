/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe abstrata Estado, que viabiliza o comportamento específico de um 
 *             objeto conforme o momento (i.e, o estado) em que ele se encontra, realizando o padrão
 *             de projeto State.
 */

#include "Estado.hpp"
#include "Erros.hpp"

    Gerenciadores::GerenciadorEstados* Estado::pGEs(NULL);

    Estado::Estado(idEstados id):
    id(id)
    {

    }

    Estado::~Estado()
    {
        id = desconhecido;
    }

    const idEstados Estado::getId() const
    {
        return id;
    }

    void Estado::setAtivo(const bool a)
    {
        ativo = a;
    }

    const bool Estado::getAtivo()
    {
        return ativo;
    }

    void Estado::setpGEs(Gerenciadores::GerenciadorEstados* pG)
    {
        pGEs = pG;

        if(pGEs == NULL)
            cout << "Erro em Estados::Estado::setpGEs(): " << ERRO_NULLPTR << endl;
    }
