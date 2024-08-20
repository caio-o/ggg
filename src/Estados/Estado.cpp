/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe abstrata Estado, que viabiliza o comportamento específico de um 
 *             objeto conforme o momento (i.e, o estado) em que ele se encontra, realizando o padrão
 *             de projeto State.
 */

#include "Estado.hpp"

namespace Estados
{
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

} // namespace Estados
