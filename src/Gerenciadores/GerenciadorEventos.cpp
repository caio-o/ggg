/*
 * AUTOR(A): Ana Julia Molinos Leite da Silva (ana-molinos)
 * DATA: 15/08/2024
 * Implementação da classe que permite o gerenciamento das ações do usuário via 
 * mouse e teclado usando recursos da biblioteca SFML.
 * */

#include "Gerenciadores/GerenciadorEventos.hpp"
#include "Erros.hpp"

#include <iostream>
using namespace std;

namespace Gerenciadores
{
    GerenciadorEventos* GerenciadorEventos::pGerenciadorEventos(NULL);

    /*Construtora privada que permite a execução do padrão de projeto Singleton.*/
    GerenciadorEventos::GerenciadorEventos():
    pGerenciadorGrafico(GerenciadorGrafico::getGerenciadorGrafico()),
    pForma(NULL)
    {
        
    }

    GerenciadorEventos::~GerenciadorEventos()
    {
        pGerenciadorGrafico = NULL;
        pForma = NULL;

        if(pGerenciadorEventos)
            delete pGerenciadorEventos;
        pGerenciadorEventos = NULL;
    }

    /* 
     * Se o ponteiro para o gerenciador for nulo, ele instancia um novo objeto do
     * tipo Gerenciador::GerenciadorEventos e o retorna. Caso contrário, retorna o endereço
     * do gerenciador já existente. Isso garante que exista apenas um gerenciador de
     * GerenciadorEventoss instanciado no programa, característica do padrão de projeto
     * Singleton.
     */
    GerenciadorEventos* GerenciadorEventos::getGerenciadorEventos()
    {
        if(pGerenciadorEventos == NULL)
            pGerenciadorEventos = new GerenciadorEventos();

        return pGerenciadorEventos;
    }

    /*
     * Configura "quem" sofrerá a ação do GerenciadorEventos gerenciado. Provisoriamente é
     * um ponteiro do tipo RectangleShape (i.e. uma forma), mas futuramente será um 
     * ponteiro do tipo Jogador e, se o padrão de projeto Observer for implementado, 
     * serão os observadores que serão acionados pelo GerenciadorEventos.
     */
    void GerenciadorEventos::setForma(ElementosGraficos::Forma* forma)
    {
        if(forma)
            pForma = forma;
        else
            cout << "Gerenciadores::GerenciadorEventos:" << ERRO_SET_NULLPTR << endl;
    }

    /*Função não implementada uma vez que ainda não se faz conveniente seu uso.*/
    void GerenciadorEventos::verificaTeclaSolta()
    {

    }

    /* 
     * Verifica qual tecla está sendo pressionada (Direita, Esquerda, Cima ou Baixo) e faz a forma se
     * movimentar 0.01 unidade na direção da tecla pressionada.
     */
    void GerenciadorEventos::verificaTeclaPressionada()
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            pForma->getpCorpo()->move(sf::Vector2f(0.1f, 0.f));
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            pForma->getpCorpo()->move(sf::Vector2f(-0.1f, 0.f));
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            pForma->getpCorpo()->move(sf::Vector2f(0.f, -0.1f));
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            pForma->getpCorpo()->move(sf::Vector2f(0.f, 0.1f));

        //Obs.: método Forma::atualizar() ainda não está sendo utilizado
    }

    /*
     * Declara uma variável GerenciadorEventos e, em um loop, prenche essa variável com entradas vindas do 
     * teclado ou mouse, de modo a definir o que fazer com base no tipo da entrada. 
     */
    void GerenciadorEventos::executar()
    {
        sf::Event GerenciadorEventos;

        /*
         * sf::Window::pollEvent(Event& event)

         * Returns: True if an event was returned, or false if the event queue was empty.

         * The sf::WindowBase class provides a simple interface for manipulating the window: move, 
         * resize, show/hide, control mouse cursor, etc. It also provides event handling through 
         * its pollEvent() and waitEvent() functions.
         * 
         * Em resumo: a função captura GerenciadorEventoss da janela.
         */

        //Enquanto a janela "capturar" um GerenciadorEventos... (i.e., clique ou movimento do mouse)
        while(pGerenciadorGrafico->getJanela()->pollEvent(GerenciadorEventos))
        {
            //Se esse GerenciadorEventos for do tipo "fechar"...
            if(GerenciadorEventos.type == sf::Event::Closed)
                pGerenciadorGrafico->fecharJanela();
            /*else if (GerenciadorEventos.type == sf::Event::KeyPressed)
                verificaTeclaPressionada();*/
            
        }

        verificaTeclaPressionada();
    }
} // namespace Gerenciadores
