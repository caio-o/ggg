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
 * SAIDA   :  As operações e seus resultados são impressos na tela.  
 */
void testeCoordenada();

/**
 * AUTOR   :  Ana Julia Molinos Leite da Silva (ana-molinos)
 * FUNCAO  :  Repete o testeJanela() (que utiliza comandos da biblioteca SFML)
 *            por meio do uso do gerenciador GerenciadorGrafico implementado.
 * SAIDA   :  Um retangulo estático na cor magenta representado no canto superior esquerdo da
 *            janela.
 */
void testeJanelaGerenciadorGrafico();

/**
 * AUTOR   :  Ana Julia Molinos Leite da Silva (ana-molinos)
 * FUNCAO  :  Repete o testeJanela() por meio do uso do gerenciador GerenciadorGrafico e do gerenciador 
 *            de GerenciadorEventoss implementados no projeto.
 * SAIDA   :  Um retangulo na cor ciano representado no canto superior esquerdo da
 *            janela que é capaz de se mover conforme uso das teclas Direita, Esquerda, Cima e
 *            baixo. Não há limites para o retangulo se mover.
 */
void testeJanelaGerenciadorGerenciadorEventos();

void testeVertexArray();

/*
 * AUTOR   :  Ana Julia Molinos Leite da Silva (ana-molinos)
 * FUNCAO  :  Testar o uso de um objeto da classe forma, em conjunto com os gerenciadores grafico e 
 *            de eventos.
 * SAIDA   :  Janela de título GGG contendo um ente com a textura de um círculo com rosto, que pode 
 *            ser controlado via teclas esquerda, direita, cima e baixo. Não há limites para o seu
 *            movimento com relação a janela.
 */
void testeForma();
void testeEntidade();
void testeColisoes();

/*
 * AUTOR   :  Ana Julia Molinos Leite da Silva (ana-molinos)
 * FUNCAO  :  Testar o inimigo Quadrado e sua interação com Jogador.
 * SAIDA   :  Um jogador controlável e um inimigo do tipo Quadrado no centro da janela. Se o jogador
 *            se aproximar do quadrado o comportamento esperado é que o quadrado o persiga e,
 *            conforme se aproximar, execute um dash contra o jogador.
 */
void testeQuadrado();

#endif