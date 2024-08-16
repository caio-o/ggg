/*
 * AUTOR(A): Ana Julia Molinos Leite da Silva (ana-molinos)
 * DATA: 15/08/2024
 * Implementação da classe que permite o gerenciamento das ações do usuário via 
 * mouse e teclado usando recursos da biblioteca SFML.
 * */

#include "Gerenciadores/Evento.hpp"
#include "Erros.hpp"

#include <iostream>
using namespace std;

namespace Gerenciadores
{
    Evento* Evento::pEvento(NULL);

    /*Construtora privada que permite a execução do padrão de projeto Singleton.*/
    Evento::Evento():
    pGrafico(Grafico::getGrafico()),
    pForma(NULL)
    {
        
    }

    Evento::~Evento()
    {
        pGrafico = NULL;
        pForma = NULL;

        if(pEvento)
            delete pEvento;
        pEvento = NULL;
    }

    /* 
     * Se o ponteiro para o gerenciador for nulo, ele instancia um novo objeto do
     * tipo Gerenciador::Evento e o retorna. Caso contrário, retorna o endereço
     * do gerenciador já existente. Isso garante que exista apenas um gerenciador de
     * eventos instanciado no programa, característica do padrão de projeto
     * Singleton.
     */
    Evento* Evento::getEvento()
    {
        if(pEvento == NULL)
            pEvento = new Evento();

        return pEvento;
    }

    /*
     * Configura "quem" sofrerá a ação do evento gerenciado. Provisoriamente é
     * um ponteiro do tipo RectangleShape (i.e. uma forma), mas futuramente será um 
     * ponteiro do tipo Jogador e, se o padrão de projeto Observer for implementado, 
     * serão os observadores que serão acionados pelo evento.
     */
    void Evento::setForma(sf::RectangleShape* forma)
    {
        if(forma)
            pForma = forma;
        else
            cout << "Gerenciadores::Evento:" << ERRO_SET_NULLPTR << endl;
    }

    /*Função não implementada uma vez que ainda não se faz conveniente seu uso.*/
    void Evento::verificaTeclaSolta()
    {

    }

    /* 
     * Verifica qual tecla está sendo pressionada (Direita, Esquerda, Cima ou Baixo) e faz a forma se
     * movimentar 0.01 unidade na direção da tecla pressionada.
     */
    void Evento::verificaTeclaPressionada()
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            pForma->move(sf::Vector2f(0.1f, 0.f));
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            pForma->move(sf::Vector2f(-0.1f, 0.f));
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            pForma->move(sf::Vector2f(0.f, -0.1f));
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            pForma->move(sf::Vector2f(0.f, 0.1f));
    }

    /*
     * Declara uma variável evento e, em um loop, prenche essa variável com entradas vindas do 
     * teclado ou mouse, de modo a definir o que fazer com base no tipo da entrada. 
     */
    void Evento::executar()
    {
        sf::Event evento;

        /*
         * sf::Window::pollEvent(Event& event)

         * Returns: True if an event was returned, or false if the event queue was empty.

         * The sf::WindowBase class provides a simple interface for manipulating the window: move, 
         * resize, show/hide, control mouse cursor, etc. It also provides event handling through 
         * its pollEvent() and waitEvent() functions.
         * 
         * Em resumo: a função captura eventos da janela.
         */

        //Enquanto a janela "capturar" um evento... (i.e., clique ou movimento do mouse)
        while(pGrafico->getJanela()->pollEvent(evento))
        {
            //Se esse evento for do tipo "fechar"...
            if(evento.type == sf::Event::Closed)
                pGrafico->fecharJanela();
            /*else if (evento.type == sf::Event::KeyPressed)
                verificaTeclaPressionada();*/
            
        }

        verificaTeclaPressionada();
    }
} // namespace Gerenciadores
