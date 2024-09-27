/*
 * AUTOR(A)  : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Classe que permite o gerenciamento das ações do usuário via mouse e teclado usando
 *             recursos da biblioteca SFML.
 * CRÉDITOS  : Código baseado nas implementações dos alunos Matheus Augusto Burda (repositório 
 *             disponível em https://github.com/MatheusBurda/Desert, tutorial disponível em: 
 *             https://youtu.be/bacO-m3-HnA?si=bSiWxTsi90R5eNJH)ce Geovane Lima Salvi (repositório 
 *             disponível em https://github.com/Giovanenero/JogoPlataforma2D-Jungle, tutorial 
 *             disponível em: https://youtu.be/FYlLKwSUrW0?si=qOwhLSCrHhIM6gzM)
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
    GerenciadorEventos::GerenciadorEventos():
    mapaTeclas()
    {
        mapaTeclas.clear();

        mapaTeclas[sf::Keyboard::A] = "A";
        mapaTeclas[sf::Keyboard::B] = "B";
        mapaTeclas[sf::Keyboard::C] = "C";
        mapaTeclas[sf::Keyboard::D] = "D";
        mapaTeclas[sf::Keyboard::E] = "E";
        mapaTeclas[sf::Keyboard::F] = "F";
        mapaTeclas[sf::Keyboard::G] = "G";
        mapaTeclas[sf::Keyboard::H] = "H";
        mapaTeclas[sf::Keyboard::I] = "I";
        mapaTeclas[sf::Keyboard::J] = "J";
        mapaTeclas[sf::Keyboard::K] = "K";
        mapaTeclas[sf::Keyboard::L] = "L";
        mapaTeclas[sf::Keyboard::M] = "M";
        mapaTeclas[sf::Keyboard::N] = "N";
        mapaTeclas[sf::Keyboard::O] = "O";
        mapaTeclas[sf::Keyboard::P] = "P";
        mapaTeclas[sf::Keyboard::Q] = "Q";
        mapaTeclas[sf::Keyboard::R] = "R";
        mapaTeclas[sf::Keyboard::S] = "S";
        mapaTeclas[sf::Keyboard::T] = "T";
        mapaTeclas[sf::Keyboard::U] = "U";
        mapaTeclas[sf::Keyboard::V] = "V";
        mapaTeclas[sf::Keyboard::W] = "W";
        mapaTeclas[sf::Keyboard::X] = "X";
        mapaTeclas[sf::Keyboard::Y] = "Y";
        mapaTeclas[sf::Keyboard::Z] = "Z";
        mapaTeclas[sf::Keyboard::Num1] = "1";
        mapaTeclas[sf::Keyboard::Num2] = "2";
        mapaTeclas[sf::Keyboard::Num3] = "3";
        mapaTeclas[sf::Keyboard::Num4] = "4";
        mapaTeclas[sf::Keyboard::Num5] = "5";
        mapaTeclas[sf::Keyboard::Num6] = "6";
        mapaTeclas[sf::Keyboard::Num7] = "7";
        mapaTeclas[sf::Keyboard::Num8] = "8";
        mapaTeclas[sf::Keyboard::Num9] = "9";
        mapaTeclas[sf::Keyboard::Num0] = "0";
        mapaTeclas[sf::Keyboard::Numpad0] = "0";
        mapaTeclas[sf::Keyboard::Numpad1] = "1";
        mapaTeclas[sf::Keyboard::Numpad2] = "2";
        mapaTeclas[sf::Keyboard::Numpad3] = "3";
        mapaTeclas[sf::Keyboard::Numpad4] = "4";
        mapaTeclas[sf::Keyboard::Numpad5] = "5";
        mapaTeclas[sf::Keyboard::Numpad6] = "6";
        mapaTeclas[sf::Keyboard::Numpad7] = "7";
        mapaTeclas[sf::Keyboard::Numpad8] = "8";
        mapaTeclas[sf::Keyboard::Numpad9] = "9";
        mapaTeclas[sf::Keyboard::Space] = "Espaço";
        mapaTeclas[sf::Keyboard::Enter] = "Enter";
        mapaTeclas[sf::Keyboard::Escape] = "Escape";
        mapaTeclas[sf::Keyboard::BackSpace] = "Apagar";
        mapaTeclas[sf::Keyboard::Right] = "Direita";
        mapaTeclas[sf::Keyboard::Left] = "Esquerda";
        mapaTeclas[sf::Keyboard::Up] = "Cima";
        mapaTeclas[sf::Keyboard::Down] = "Baixo";
        mapaTeclas[sf::Keyboard::LControl] = "Ctrl";
        mapaTeclas[sf::Keyboard::LShift] = "Shift";
        mapaTeclas[sf::Keyboard::RControl] = "Ctrl";
        mapaTeclas[sf::Keyboard::RShift] = "Shift";
        mapaTeclas[sf::Keyboard::Hyphen] = "-";
        mapaTeclas[sf::Keyboard::Tab] = "Tab";
    }

    GerenciadorEventos::~GerenciadorEventos()
    {        
        pGerenciadorEventos = NULL;

        pGEs = NULL;
        pGG = NULL;

        mapaTeclas.clear();
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

    //Informa ao estado em execução qual tecla foi solta
    void GerenciadorEventos::verificaTeclaSolta(sf::Keyboard::Key tecla)
    {
        if(pGEs)
        {
            pGEs->getEstadoAtual()->verificaTeclaSolta(mapaTeclas[tecla]);
        }
        else
            cout << "Erro em Gerenciadores::GerenciadorEventos::verificaTeclaSolta()::pGEs: " << ERRO_NULLPTR << endl;
    }

    //Informa ao estado em execução qual tecla foi pressionada
    void GerenciadorEventos::verificaTeclaPressionada(sf::Keyboard::Key tecla)
    {
        if(pGEs)
        {
            pGEs->getEstadoAtual()->verificaTeclaPressionada(mapaTeclas[tecla]);
        }
        else
            cout << "Erro em Gerenciadores::GerenciadorEventos::verificaTeclaPressionada()::pGEs: " << ERRO_NULLPTR << endl;
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
                    pGG->fecharJanela(); //Finaliza a janela
                //Se for do tipo "tecla pressionada"
                else if (evento.type == sf::Event::KeyPressed)
                    verificaTeclaPressionada(evento.key.code); //Chama a função pertinente
                //Se for do tipo "tecla solta"
                else if (evento.type == sf::Event::KeyReleased)
                    verificaTeclaSolta(evento.key.code); //Chama a função pertinente
            }
        }
        else
            cout << "Erro em Gerenciadores::GerenciadorEventos::executar()::pGG: " << ERRO_NULLPTR << endl;
    }
} // namespace Gerenciadores
