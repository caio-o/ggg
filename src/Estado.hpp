/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Declaração da classe abstrata Estado, que viabiliza o comportamento específico de um 
 *             objeto conforme o momento (i.e, o estado) em que ele se encontra, realizando o padrão
 *             de projeto State.
 */

#pragma once

#include <string>

using namespace std;

//#include "Gerenciadores/GerenciadorEstados.hpp"
namespace Gerenciadores { class GerenciadorEstados; } //Include recursivo
    
    //Possíveis estados do jogo
    enum idEstados
    {
        desconhecido = 0,
        menuPrincipal, //opções: 1 jogador, 2 jogadores, ranking, carregar jogo salvo
        menuFase, //opções: fase 1, fase 2
        jogo, //execução do jogo (na dúvida se esse estado é necessário)
        fase1, //execução da fase 1
        fase2, //execução da fase 2
        faseTeste,
        menuPause, //opções: salvar e voltar ao menu principal, apenas voltar ao menu principal
        menuSalvamento, //opções: registrar nome?
        menuFimJogo, //opções: registrar nome
        ranking //exibe o ranking
    };

    class Estado
    {
        protected:
            idEstados id;
            bool ativo;
            static Gerenciadores::GerenciadorEstados* pGEs;

        public:
            Estado(idEstados id = desconhecido);
            virtual ~Estado();
            
            virtual void executar(const float dT) = 0;
            virtual void desenhar() = 0;

            virtual void verificaTeclaPressionada(string tecla) = 0;
            virtual void verificaTeclaSolta(string tecla) = 0;

            const idEstados getId() const;

            void setAtivo(const bool a);
            const bool getAtivo();

            static void setGerenciadorEstados();
    };
