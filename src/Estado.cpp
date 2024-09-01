/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe abstrata Estado, que viabiliza o comportamento específico de um 
 *             objeto conforme o momento (i.e, o estado) em que ele se encontra, realizando o padrão
 *             de projeto State.
 */
#include "Gerenciadores/GerenciadorEstados.hpp"
#include "Estado.hpp"
#include "Erros.hpp"

    Gerenciadores::GerenciadorEstados* Estado::pGEs(NULL);

    Estado::Estado(idEstados id):
    idEstado(id),
    ativo(true)
    {

    }

    Estado::~Estado()
    {
        idEstado = desconhecido;
    }

    const idEstados Estado::getIdEstado() const
    {
        return idEstado;
    }

    void Estado::setAtivo(const bool a)
    {
        ativo = a;
    }

    const bool Estado::getAtivo()
    {
        return ativo;
    }

    void Estado::setGerenciadorEstados()
    {
        pGEs = Gerenciadores::GerenciadorEstados::getGerenciadorEstados();

        if(pGEs == NULL)
            cout << "Erro em Estados::Estado::setpGEs(): " << ERRO_NULLPTR << endl;
    }
