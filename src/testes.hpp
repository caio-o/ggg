/**
 *    Arquivo que define funcoes para testar as funcionalidades
 *  da SFML e as nossas proprias classes e funcoes. Comente-se aqui
 *  brevemente o resultado esperado de cada teste.
 */

#ifndef _TESTES_HPP
#define _TESTES_HPP

// Espera input do usuario antes de prosseguir. Apenas para testes de console.
// Considere se pausar o tempo nao afetarah o teste em questao.
void esperaEnter();

/**
 * AUTOR   :  Equipe do SFML
 * FUNCAO  : Cria uma janela com um circulo, e espera que o usuario a feche.
 */
void testeJanela();

/**
 * AUTOR   :  Caio e Silva Barbieri (caio-o)
 * FUNCAO  :  Cria 2 objetos Elemento<int>, faz um apontar para o outro, e imprime seu conteudo na tela,
 *           depois troca os dois de lugar, e imprime de novo.
 */
void testeElemento();

/**
 * AUTOR   :  Caio e Silva Barbieri (caio-o)
 * FUNCAO  :  Cria uma Lista<int>, e adiciona dois elementos no início (push_front), 
 *           dois no final (push_back), e três em posições várias (push_n).  
 */
void testeLista();

/**
 * AUTOR   :  Ana Julia Molinos Leite da Silva (ana-molinos)
 * FUNCAO  :  Cria variáveis do tipo Coordenada e realiza operações por meio dos
 *            operadores sobrecarregados.  
 */
void testeCoordenada();

/**
 * AUTOR   :  Ana Julia Molinos Leite da Silva (ana-molinos)
 * FUNCAO  :  Repete o testeJanela() (que utiliza comandos da biblioteca SFML)
 *            por meio do uso do gerenciador Grafico implementado.  
 */
void testeJanelaGerenciadorGrafico();

#endif