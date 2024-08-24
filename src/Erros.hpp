/**
 *   AUTOR  : Caio e Silva Barbieri (caio-o) (ateh agora).
 *   DATA   : 09/08/2024 19:38
 *   Arquivo com definicoes de mensagens-padrao para cada tipo 
 *   de erro de execucao.
 */

#ifndef _ERROS_HPP
#define _ERROS_HPP
    
    #include <iostream>

    #define ERRO_DELETE_NULLPTR "Nao se pode deletar ponteiro NULL."
    #define ERRO_INCLUI_NULLPTR "Ponteiro NULL nao incluido na lista."
    #define ERRO_SET_NULLPTR "Não é possível configurar ponteiro NULL."
    #define ERRO_NULLPTR_LISTA "Elemento NULL encontrado na lista!"
    #define ERRO_RETURN_NULLPTR "Ponteiro nulo retornado."
    #define ERRO_NULLPTR "Ponteiro nulo."
    #define ERRO_ALOCACAO "Nao foi possivel alocar objeto."

    void enterFechar ();

#endif