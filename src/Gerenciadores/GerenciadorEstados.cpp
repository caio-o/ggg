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
#include "Menus/MenuPause.hpp"
#include "Menus/MenuFinal.hpp"
#include "Menus/Ranking.hpp"

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

        // //Aloca fase 1
        // Estado* pEstado = NULL;

        // pEstado = static_cast<Estado*>(new Fases::Calabouco());

        // if(pEstado)
        // {
        //     mapaEstados.insert(std::pair<idEstados, Estado*>(fase1, pEstado));
        //     pEstado->setAtivo(false); //Para posterior desalocação
        // }
        // else
        //     cout << "Erro em Gerenciadores::GerenciadorEstados::GerenciadorEstados()::pEstado: " << ERRO_ALOCACAO << endl;
        // pEstado = NULL;

        // //Aloca fase 2
        // pEstado = static_cast<Estado*>(new Fases::Tuneis());

        // if(pEstado)
        // {
        //     mapaEstados.insert(std::pair<idEstados, Estado*>(fase2, pEstado));
        //     pEstado->setAtivo(false); //Para posterior desalocação
        // }
        // else
        //     cout << "Erro em Gerenciadores::GerenciadorEstados::GerenciadorEstados()::pEstado: " << ERRO_ALOCACAO << endl;
        // pEstado = NULL;

        //Aloca Menu Principal
        Estado* pEstado = static_cast<Estado*>(new Menus::MenuPrincipal(menuPrincipal));

        if(pEstado)
            mapaEstados.insert(std::pair<idEstados, Estado*>(menuPrincipal, pEstado));
        else
            cout << "Erro em Gerenciadores::GerenciadorEstados::GerenciadorEstados()pEstado: " << ERRO_ALOCACAO << endl;

        pEstado = NULL;

        //Aloca Menu de Pause
        pEstado = static_cast<Estado*>(new Menus::MenuPause(menuPause));

        if(pEstado)
            mapaEstados.insert(std::pair<idEstados, Estado*>(menuPause, pEstado));
        else
            cout << "Erro em Gerenciadores::GerenciadorEstados::GerenciadorEstados()pEstado: " << ERRO_ALOCACAO << endl;

        pEstado = NULL;

        //Aloca Menu de Finalização
        pEstado = static_cast<Estado*>(new Menus::MenuFinal(menuFimJogo));

        if(pEstado)
            mapaEstados.insert(std::pair<idEstados, Estado*>(menuFimJogo, pEstado));
        else
            cout << "Erro em Gerenciadores::GerenciadorEstados::GerenciadorEstados()pEstado: " << ERRO_ALOCACAO << endl;

        pEstado = NULL;

        //Aloca Ranking
        pEstado = static_cast<Estado*>(new Menus::Ranking(ranking));

        if(pEstado)
            mapaEstados.insert(std::pair<idEstados, Estado*>(ranking, pEstado));
        else
            cout << "Erro em Gerenciadores::GerenciadorEstados::GerenciadorEstados()pEstado: " << ERRO_ALOCACAO << endl;

        pEstado = NULL;
    }

    GerenciadorEstados::~GerenciadorEstados()
    {
        cout << "ENTROU NA DESTRUTORA DO GE" << endl;
        
        //Desaloca os estados      
        if(!mapaEstados.empty())
        {
            map<idEstados, Estado*>::iterator it;

            for(it = mapaEstados.begin(); it != mapaEstados.end(); it++)
            {
                cout << "Deletando " << it->first << endl;
                
                if(it->second != NULL)
                    delete (it->second);

                cout << "Deletou " << it->first << endl;
            }
        }
        
        mapaEstados.clear();

        //Desaloca o gerenciador.
        pGEs = NULL;

        cout <<"saiu da destrutora do ges" << endl;
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

        //Se o estado a ser executado é uma fase...
        if(id == fase1 || id == fase2)
        {
            bool achouFase1 = false;
            bool achouFase2 = false;
            Estado* pEstado1 = NULL;
            Estado* pEstado2 = NULL;

            map<idEstados, Estado*>::iterator it = mapaEstados.begin();
            
            //Checa se já tem fases no mapa...
            while(it!=mapaEstados.end() && (!achouFase1 || !achouFase2))
            {
                if(it->first == fase1)
                {
                    if(it->second!=NULL)
                    {
                        pEstado1 = it->second; //armazena o ponteiro da fase1
                    
                        if(!pEstado1->getAtivo())
                            it->second = NULL; //deixa a chave nula no mapa
                    }

                    achouFase1 = true; //achou a chave da fase no mapa
                }
                else if(it->first == fase2)
                {
                    if(it->second!=NULL)
                    {
                        pEstado2 = it->second;
                    
                        if(!pEstado2->getAtivo())
                            it->second = NULL;
                    }
                    
                    achouFase2 = true;
                }
                
                it++;
            }

            /* ---------- REMOÇÃO DE FASES DO MAPA ---------- */

            //Se o mapa já tiver fase1 e for inativa...
            if(achouFase1 && pEstado1!=NULL && !pEstado1->getAtivo())
            {
                cout << "Removendo fase1" <<endl;
                //...desaloca...
                delete pEstado1;

                pEstado1 = NULL;

                cout << "Removeu fase1" << endl;
            }

            //Se o mapa já tiver fase2 e for inativa...
            if(achouFase2 && pEstado2!=NULL && !pEstado2->getAtivo())
            {
                cout << "Removendo fase2" << endl;
                //...desaloca...
                delete pEstado2;

                pEstado2 = NULL;
                cout << "Removeu fase2" << endl;
            }
        
            /* ---------- ALOCAÇÃO DE NOVA FASE ---------- */
            
            if(id == fase1 && pEstado1 == NULL)
            {
                cout << "Alocando fase 1" << endl;
                pEstado1 = static_cast<Estado*>(new Fases::Calabouco());
                cout << "Alocou fase1" << endl;

                if(pEstado1)
                {
                    if(achouFase1)
                        mapaEstados[fase1] = pEstado1;
                    else
                        mapaEstados.insert(std::pair<idEstados, Estado*>(fase1, pEstado1));
                }
                else
                    cout << "Erro em Gerenciadores::GerenciadorEstados::executarEstado()::pEstado: " << ERRO_ALOCACAO << endl;
            }
            else if(id == fase2 && pEstado2 == NULL)
            {
                cout << "Alocando fase2" << endl;
                pEstado2 = static_cast<Estado*>(new Fases::Tuneis());
                cout << "Alocou fase2" << endl;

                if(pEstado2)
                {
                    if(achouFase2)
                        mapaEstados[fase2] = pEstado2;
                    else
                        mapaEstados.insert(std::pair<idEstados, Estado*>(fase2, pEstado2));
                }
                else
                    cout << "Erro em Gerenciadores::GerenciadorEstados::executarEstado()::pEstado: " << ERRO_ALOCACAO << endl;
            }
        }
        
        //if(pEstado)
        if(mapaEstados[idEstadoAtual])
            //pEstado->executar();
            {/*cout << "Executou estado" << id << endl*/; mapaEstados[idEstadoAtual]->executar(0.0); }
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
