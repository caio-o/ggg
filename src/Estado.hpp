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
        desconhecido = 0, //opções: 1 jogador, 2 jogadores, ranking, carregar jogo salvo
        jogoSequencia, //execução do jogo com as duas fases em sequencia
        fase1, //execução da fase 1
        fase2,
        menuPrincipal, //execução da fase 2,
        menuPause, //opções: salvar o jogo e voltar ao menu principal, apenas voltar ao menu principal 
        menuFimJogo, //opções: registrar o nome no ranking
        ranking //exibe o ranking
    };

    class Estado
    {
        protected:
            idEstados idEstado;
            bool ativo;
            static Gerenciadores::GerenciadorEstados* pGEs;

        public:
            Estado(idEstados id = desconhecido);
            virtual ~Estado();
            
            virtual void executar(const float dT) = 0;
            virtual void desenhar() = 0;

            virtual void verificaTeclaPressionada(string tecla){};
            virtual void verificaTeclaSolta(string tecla){};

            const idEstados getIdEstado() const;

            void setAtivo(const bool a);
            const bool getAtivo();

            static void setGerenciadorEstados();
    };
