/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe GerenciadorEstados, cujo objeto é o único responsável por 
 *             manipular os estados de jogo (como menu e execução do próprio jogo).
 */

//dar créditos ao geovane

#include "GerenciadorEstados.hpp"

#include "Fases/Calabouco.hpp"
#include "Fases/Tuneis.hpp"

#include "Menus/MenuPrincipal.hpp"

#include <iostream>
using namespace std;

namespace Gerenciadores
{
    GerenciadorEstados* GerenciadorEstados::pGEs(NULL);

    GerenciadorEstados::GerenciadorEstados():
    mapaEstados()
    {
        mapaEstados.clear();

        /*
         * Aqui podem ser instanciados todos os estados (com loop? Da pra usar o enum no loop?)
         */

        //Aloca fase 1
        Estado* pEstado = NULL;

        pEstado = static_cast<Estado*>(new Fases::Calabouco());

        if(pEstado)
        {
            mapaEstados.insert(std::pair<idEstados, Estado*>(fase1, pEstado));
            pEstado->setAtivo(false); //Para posterior desalocação
        }
        else
            cout << "Erro em Gerenciadores::GerenciadorEstados::GerenciadorEstados()::pEstado: " << ERRO_ALOCACAO << endl;
        pEstado = NULL;

        //Aloca fase 2
        pEstado = static_cast<Estado*>(new Fases::Tuneis());

        if(pEstado)
        {
            mapaEstados.insert(std::pair<idEstados, Estado*>(fase2, pEstado));
            pEstado->setAtivo(false); //Para posterior desalocação
        }
        else
            cout << "Erro em Gerenciadores::GerenciadorEstados::GerenciadorEstados()::pEstado: " << ERRO_ALOCACAO << endl;
        pEstado = NULL;

        //Aloca Menu Principal
        pEstado = static_cast<Estado*>(new Menus::MenuPrincipal(menuPrincipal));

        if(pEstado)
            mapaEstados.insert(std::pair<idEstados, Estado*>(menuPrincipal, pEstado));
        else
            cout << "Erro em Gerenciadores::GerenciadorEstados::GerenciadorEstados()pEstado: " << ERRO_ALOCACAO << endl;

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

        //Se o estado a ser executado é uma fase e está inativa
        if((id == fase1 || id == fase2) && !getEstado(id)->getAtivo())
        {
            //Desaloca a fase1 no mapa se houver
            if(mapaEstados[fase1])
            {
                delete mapaEstados[fase1];
                mapaEstados[fase1] = NULL;
                cout << "Desalocou fase1" << endl;
            }

            //Desaloca a fase2 no mapa se houver
            if(mapaEstados[fase1])
            {
                delete mapaEstados[fase1];
                mapaEstados[fase1] = NULL;
                cout << "Desalocou fase2" << endl;
            }

            cout << "Chegou na alocação fase1" << endl;
            //Se o estado for fase1...
            if(id == fase1)
            {
                Estado* pEstado = NULL;

                //...aloca uma nova fase1...
                pEstado = static_cast<Estado*>(new Fases::Calabouco());

                //...e adiciona mapa de estados no id correspondente
                if(pEstado)
                    {mapaEstados[id] = pEstado; cout << "Inseriu no mapa de estados fase1" << endl;}
                else
                    cout << "Erro em Gerenciadores::GerenciadorEstados::executarEstado()::pEstado: " << ERRO_ALOCACAO << endl;
            }
            cout << "Chegou na alocação fase2" << endl;

            //Se o estado for fase2...
            if(id == fase2)
            {
                Estado* pEstado = NULL;

                //...aloca uma nova fase2...
                pEstado = static_cast<Estado*>(new Fases::Tuneis());

                //...e adiciona mapa de estados no id correspondente
                if(pEstado)
                    {mapaEstados[id] = pEstado; cout << "Inseriu no mapa de estados fase1" << endl;}
                else
                    cout << "Erro em Gerenciadores::GerenciadorEstados::executarEstado()::pEstado: " << ERRO_ALOCACAO << endl;
            }

            cout << "Saiu alocação fase2" << endl;

        }
        
        //if(pEstado)
        if(mapaEstados[idEstadoAtual])
            //pEstado->executar();
            {cout << "Executou estado" << endl; mapaEstados[idEstadoAtual]->executar(0.0); }
        else
            cout << "Erro em Gerenciadores::GerenciadorEstados::executarEstado()::pEstado: " << ERRO_NULLPTR << endl;

    }

    //Retorna o id (tipo Estados::idEstados) do estado que está sendo executado atualmente.
    const idEstados GerenciadorEstados::getIdEstadoAtual() const
    {
        return idEstadoAtual;
    }

    //Retorna um ponteiro para o estado que está sendo executado atualmente
    Estado* GerenciadorEstados::getEstadoAtual()
    {
        if(mapaEstados[idEstadoAtual] == NULL)
            cout << "Atenção em Gerenciadores::GerenciadorEstados::getEstadoAtual(): " << ERRO_RETURN_NULLPTR << endl;
        
        return mapaEstados[idEstadoAtual];
    }

    //Retorna um ponteiro para o estado que corresponde ao id passado por parâmetro
    Estado* GerenciadorEstados::getEstado(const idEstados id)
    {
        if(mapaEstados[id] == NULL)
            cout << "Atenção em Gerenciadores::GerenciadorEstados::getEstado(): " << ERRO_RETURN_NULLPTR << endl;
        
        return mapaEstados[id];
    }

} // namespace Gerenciadores
