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
    GerenciadorEstados* GerenciadorEventos::pGEs(NULL);
    GerenciadorGrafico* GerenciadorEventos::pGG(NULL);

    /*Construtora privada que permite a execução do padrão de projeto Singleton.*/
    GerenciadorEventos::GerenciadorEventos()
    {
        
    }

    GerenciadorEventos::~GerenciadorEventos()
    {
        //só desaloca a ele mesmo
        if(pGerenciadorEventos)
            delete pGerenciadorEventos;
        
        pGerenciadorEventos = NULL;

        pGEs = NULL;
        pGG = NULL;
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
            pGerenciadorEventos = new Gerenciadores::GerenciadorEventos();
            
        if (pGerenciadorEventos)
        {
            return pGerenciadorEventos;
        }
        else
        {
            cout << "Em GerenciadorEventos::getGerenciadorEventos: " << ERRO_ALOCACAO << endl;
            return NULL;
        }
    }

    void GerenciadorEventos::setGerenciadorGrafico()
    {
        pGG = GerenciadorGrafico::getGerenciadorGrafico();
    }

    void GerenciadorEventos::setGerenciadorEstados()
    {
        pGEs = GerenciadorEstados::getGerenciadorEstados();
    }

    /*Função não implementada uma vez que ainda não se faz conveniente seu uso.*/
    void GerenciadorEventos::verificaTeclaSolta(sf::Keyboard::Key tecla)
    {

    }

    /* 
     * Verifica qual tecla está sendo pressionada (Direita, Esquerda, Cima ou Baixo) e faz a forma se
     * movimentar 0.01 unidade na direção da tecla pressionada.
     */
    void GerenciadorEventos::verificaTeclaPressionada(sf::Keyboard::Key tecla)
    {
        if(pGEs)
        {
            if(pGEs->getIdEstadoAtual() == menuSalvamento)
            {

            }
            // else
            // {
            //     pGEs->getEstadoAtual()->
            // }
        }
        else
            cout << "Erro em Gerenciadores::GerenciadorEventos::verificaTeclaPressionada()::pGG: " << ERRO_NULLPTR << endl;
    }


    /*
     * Declara uma variável GerenciadorEventos e, em um loop, prenche essa variável com entradas vindas do 
     * teclado ou mouse, de modo a definir o que fazer com base no tipo da entrada. 
     */
    void GerenciadorEventos::executar()
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
        if(pGG)
        {
            while(pGG->getJanela()->pollEvent(evento))
            {
                //Se esse evento for do tipo "fechar"...
                if(evento.type == sf::Event::Closed)
                    pGG->fecharJanela();
                else if (evento.type == sf::Event::KeyPressed)
                    verificaTeclaPressionada(evento.key.code);
            }
        }
        else
            cout << "Erro em Gerenciadores::GerenciadorEventos::executar()::pGG: " << ERRO_NULLPTR << endl;
    }
} // namespace Gerenciadores
