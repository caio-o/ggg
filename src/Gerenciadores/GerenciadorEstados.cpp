/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe GerenciadorEstados, cujo objeto é o único responsável por 
 *             manipular os estados de jogo (como menu e execução do próprio jogo).
 */

//dar créditos ao geovane

#include "GerenciadorEstados.hpp"
#include "Fases/FaseTeste.hpp"

#include <iostream>
using namespace std;

namespace Gerenciadores
{
    GerenciadorEstados* GerenciadorEstados::pEstados(NULL);

    GerenciadorEstados::GerenciadorEstados():
    mapaEstados()
    {
        mapaEstados.clear();

        /*
         * Aqui podem ser instanciados todos os estados (com loop? Da pra usar o enum no loop?)
         */

        Estado* pEstado = NULL;

        pEstado = static_cast<Estado*>(new Fases::FaseTeste());

        if(pEstado)
        {
            mapaEstados.insert(std::pair<idEstados, Estado*>(faseTeste, pEstado));
        }
        else
            cout << "Erro em Gerenciadores::GerenciadorEstados::GerenciadorEstados(): " << ERRO_ALOCACAO << endl;

        pEstado = NULL;
    }

    GerenciadorEstados::~GerenciadorEstados()
    {
        //Desaloca os estados      
        if(!mapaEstados.empty())
        {
            map<idEstados, Estado*>::iterator it;

            for(it = mapaEstados.begin(); it != mapaEstados.end(); it++)
            {
                if(it->second)
                    delete (it->second);
            }
        }
        
        mapaEstados.clear();

        //Desaloca o gerenciador.
        if(pEstados)
            delete pEstados;

        pEstados = NULL;
    }

    /*
     * Retorna um ponteiro para o objeto já instanciado GerenciadorEstados. Caso o objeto ainda não
     * tenha sido instanciado, o método o instancia e, só então, o retorna, conforme padrão de 
     * projeto Singleton.
     */
    GerenciadorEstados* GerenciadorEstados::getGerenciadorEstados()
    {
        if(pEstados == NULL)
            pEstados = new GerenciadorEstados();

        return pEstados;
    }

    /*
     * Atualiza o id do estado executando atualmente e chama seu método de execução.
     */
    void GerenciadorEstados::mudarEstado(idEstados id)
    {
        idEstadoAtual = id;

        mapaEstados[idEstadoAtual]->executar(0.0);
    }

    //Retorna o id (tipo Estados::idEstados) do estado que está sendo executado atualmente.
    idEstados GerenciadorEstados::getEstadoAtual() const
    {
        return idEstadoAtual;
    }

    void GerenciadorEstados::setObservadores()
    {

    }

} // namespace Gerenciadores
