/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Declaração da classe abstrata Estado, que viabiliza o comportamento específico de um 
 *             objeto conforme o momento (i.e, o estado) em que ele se encontra, realizando o padrão
 *             de projeto State.
 */

#pragma once

namespace Estados
{
    //Possíveis estados do jogo
    enum idEstados
    {
        desconhecido = -1,
        menuPrincipal = 0, //opções: 1 jogador, 2 jogadores, ranking, carregar jogo salvo
        menuFase, //opções: fase 1, fase 2
        jogo, //execução do jogo (na dúvida se esse estado é necessário)
        fase1, //execução da fase 1
        fase2, //execução da fase 2
        menuPause, //opções: salvar e voltar ao menu principal, apenas voltar ao menu principal
        menuSalvamento, //opções: registrar nome?
        menuFimJogo, //opções: registrar nome
        ranking //exibe o ranking
    };

    class Estado
    {
        protected:
            idEstados id;

        public:
            Estado(idEstados id = desconhecido);
            virtual ~Estado();
            const idEstados getId() const;
            virtual void executar() = 0;
            virtual void renderizar() = 0;
    };
} // namespace Estados
