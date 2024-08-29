/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe GerenciadorEstados, cujo objeto é o único responsável por 
 *             manipular os estados de jogo (como menu e execução do próprio jogo).
 */

//dar créditos ao geovane

#include "GerenciadorEstados.hpp"
#include "Fases/Calabouco.hpp"
#include "Menus/MenuPrincipal.hpp"

#include <iostream>
using namespace std;

namespace Gerenciadores
{
    GerenciadorEstados* GerenciadorEstados::pGEs(NULL);

    GerenciadorEstados::GerenciadorEstados():
    mapaEstados()
    {
        cout << "Inicio alocação pges!" << endl;
        mapaEstados.clear();

        /*
         * Aqui podem ser instanciados todos os estados (com loop? Da pra usar o enum no loop?)
         */

        //Aloca fase 1
        Estado* pEstado = NULL;

        pEstado = static_cast<Estado*>(new Fases::Calabouco());

        if(pEstado)
        {
            mapaEstados.insert(std::pair<idEstados, Estado*>(faseTeste, pEstado));
        }
        else
            cout << "Erro em Gerenciadores::GerenciadorEstados::GerenciadorEstados(): " << ERRO_ALOCACAO << endl;
        pEstado = NULL;

        cout << "Alocou fase" << endl;

        //Aloca Menu Principal
        pEstado = static_cast<Estado*>(new Menus::MenuPrincipal(menuPrincipal));
        cout << "Alocou menu principal" << endl;

        if(pEstado)
            mapaEstados.insert(std::pair<idEstados, Estado*>(menuPrincipal, pEstado));
        else
            cout << "Erro em Gerenciadores::GerenciadorEstados::GerenciadorEstados(): " << ERRO_ALOCACAO << endl;

        cout << "1 - Solicitação de alocação do Menu Principal concluída!" << endl;
        pEstado = NULL;

        cout << "Passou alocação pGEs!" << endl;
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
        if(pGEs)
            delete pGEs;

        pGEs = NULL;
    }

    /*
     * Retorna um ponteiro para o objeto já instanciado GerenciadorEstados. Caso o objeto ainda não
     * tenha sido instanciado, o método o instancia e, só então, o retorna, conforme padrão de 
     * projeto Singleton.
     */
    GerenciadorEstados* GerenciadorEstados::getGerenciadorEstados()
    {
        cout << "getGerenciadorEstados()" << endl;
        
        if(pGEs == NULL)
            pGEs = new GerenciadorEstados();

        return pGEs;
    }

    /*
     * Atualiza o id do estado executando atualmente e chama seu método de execução.
     */
    void GerenciadorEstados::executarEstado(idEstados id)
    {
        
        
        idEstadoAtual = id;

        mapaEstados[idEstadoAtual]->executar(0.0);

        cout << " 3 - Solicitação de execução do estado " << id  << " concluida!" << endl;
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
