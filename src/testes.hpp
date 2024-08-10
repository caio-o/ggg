#ifndef _TESTES_HPP
#define _TESTES_HPP

/**
 *    Arquivo que define funcoes para testar as funcionalidades
 *  da SFML e as nossas proprias classes e funcoes.
 */

// Espera input do usuario antes de prosseguir. Apenas para testes de console.
// Considere se pausar o tempo nao afetarah o teste em questao.
void esperaEnter();

/**
 * AUTOR:  Equipe do SFML
 * FUNCAO: Cria uma janela com um circulo, e espera que o usuario a feche.
 */
void testeJanela();

/**
 * AUTOR:  Caio Barbieri (caio-o)
 * FUNCAO: Cria objetos Elemento<int>, faz um apontar para o outro, e imprime seu conteudo na tela.
 */
void testeElemento();

#endif