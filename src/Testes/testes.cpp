/** 
 *   AUTORES : Caio Barbieri & Ana Julia Molinos
 *   DATA    : 9/08/2024
 *   Arquivo que implementa os testes definidos em "testes.hpp".
 * 
 *  Para descricaoes das funcoes e detalhes de autoria vide "testes.hpp".
*/
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include "../Listas/Lista.hpp"
#include "testes.hpp"
#include "Coordenada.hpp"

#include "Gerenciadores/GerenciadorGrafico.hpp"
#include "Gerenciadores/GerenciadorEventos.hpp"

#include "ElementosGraficos/Forma.hpp"

#include "Entidades/Entidade.hpp"
#include "Entidades/Personagens/Jogador.hpp"

using namespace std;
using namespace Listas;

//Obs.: arrumar caminho da textura desejada  (p/ mim só funcinou assim, preciso arrumar)
#define CAMINHO_TEXTURA "/home/ana/Documentos/BSI/P2/tec_prog/trabalho/jogo/ggg/img/emoji_com_faca.png"

void esperaEnter()
{
    cout <<                                         endl;
    cout << "----------------------------------" << endl;
    cout << " Pressione ENTER para prosseguir. " << endl;
    cout << "----------------------------------" << endl;
    cout <<                                         endl;

    cin.get();
}

void testeJanela()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}

void testeElemento()
{
    Lista<int>::Elemento e1(NULL);
    Lista<int>::Elemento e2(NULL);

    e1.setInfo(new int(123));
    e2.setInfo(new int(321));
    e1.setProx(&e2);

    cout << "Numero do elemento 1: " << *(e1.getInfo()) << "." << endl;
    cout << "Numero do elemento 2: " << *(e2.getInfo()) << "." << endl;

    cout << "Elemento 1 aponta para: " << *(e1.getProx()->getInfo()) << "." << endl;

    cout << endl << "TROCANDO ELEMENTOS..." << endl;
    
    e1.trocaAdiante();

    cout << "Numero do elemento 1: " << *(e1.getInfo()) << "." << endl;
    cout << "Numero do elemento 2: " << *(e2.getInfo()) << "." << endl;

    cout << "Elemento 1 aponta para: " << *(e1.getProx()->getInfo()) << "." << endl;

    esperaEnter();
}

void testeLista()
{
    srand(time(0));

    cout << endl;
    cout << "Crie uma lista.    ";
    Lista<int> umaLista;
    cout << "R: Criei." << endl << endl;
    
    cout << "A lista estah vazia?    R: " << (umaLista.vazia() ? "Sim." : "Nao.") << endl; 
    cout << "Adicione 4 , 2 com push_front e 2 com push_back.    ";

    umaLista.push_front (new int(rand()%100));  // Adiciona na frente...
    umaLista.push_front (new int(rand()%100));
    umaLista.push_back  (new int(rand()%100));  // ...adiciona no fim
    umaLista.push_back  (new int(rand()%100));

    cout << "R: Veja os numeros:    ";
    umaLista.imprimir();

    cout << "A lista estah vazia?    R: " << (umaLista.vazia() ? "Sim." : "Nao.") << endl << endl;

    cout << "Coloque o numero 100 nas posicoes 0 (inicio), 3 (meio) e 6 (final) (push_n).    ";
    umaLista.push_n (new int(100), 0); // Adiciona em uma posicao especifica.
    umaLista.push_n (new int(100), 3);
    umaLista.push_n (new int(100), 6);

    cout << "R: Coloquei! Veja a lista:" << endl;
    umaLista.imprimir();

    esperaEnter();
}

void testeCoordenada()
{
    Coordenada::Vetor2f coord1, coord2, coord3;

    coord1.x = 1.0;
    coord1.y = 1.0;

    coord2.x = 2.0;
    coord2.y = 2.0;

    cout << "coord1 = " << coord1.x << ", " << coord1.y << endl
         << "coord2 = " << coord2.x << ", " << coord2.y << endl;

    coord3 = coord1 + coord2;

    cout << "coord3 = coord1 + coord2 = " << coord3.x << ", " 
         << coord3.y << endl;

    coord3 = coord2 - coord1;

    cout << "coord3 = coord2 - coord1 = " << coord3.x << ", " 
         << coord3.y << endl;

    coord3 = coord1/2.0;

    cout << "coord3 = coord1/2.0 = " << coord3.x << ", " 
         << coord3.y << endl;

    coord3 = coord2*3.0;

    cout << "coord3 = coord2*3.0 = " << coord3.x << ", " 
         << coord3.y << endl;

    coord3 += coord1;

    cout << "coord3 += coord1 = " << coord3.x << ", " 
         << coord3.y << endl;

    coord3 -= coord2;

    cout << "coord3 -= coord2 = " << coord3.x << ", " 
         << coord3.y << endl;

    coord3 /= 5.0;

    cout << "coord3 /= 5.0 = " << coord3.x << ", " 
         << coord3.y << endl;

    coord3 *= 3.0;

    cout << "coord3 *= 3.0 = " << coord3.x << ", " 
         << coord3.y << endl;
}

void testeJanelaGerenciadorGrafico()
{
     /*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
     sf::CircleShape shape(100.f);
     shape.setFillColor(sf::Color::Green);*/

     //em razão do PP Singleton, é assim que se inicializa o gerenciador
     Gerenciadores::GerenciadorGrafico* gg = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
     sf::RectangleShape ret(sf::Vector2f(200.f, 200.f));
     ret.setFillColor(sf::Color::Magenta);

     //P.S: estudar em qual classe devem ser implementados os métodos que dizem respeito as formas...

     while (gg->janelaAberta())
     {
          sf::Event event;
          while (gg->getJanela()->pollEvent(event))
          {
               if (event.type == sf::Event::Closed)
                    gg->fecharJanela();
          }

          gg->limpar();
          gg->renderizar(&ret);
          gg->mostrar();
     }
}

void testeJanelaGerenciadorGerenciadorEventos()
{
     //Instancia o gerenciador GerenciadorGrafico
     Gerenciadores::GerenciadorGrafico* gg = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();

     //Instancia o gerenciador de GerenciadorEventoss
     Gerenciadores::GerenciadorEventos* ge = Gerenciadores::GerenciadorEventos::getGerenciadorEventos();

     //Instancia um quadrado ciano
     sf::RectangleShape ret(sf::Vector2f(100.f, 100.f));
     ret.setFillColor(sf::Color::Cyan);

     //Associa o quadrado ao ge
     //ge->setForma(&ret);

     while (gg->janelaAberta())
     {
          /* 
           * Substitui o loop mais interno do teste anterior, assim permite realizar o teste de maneira
           * completamente desacoplada da biblioteca gráfica.
           */
          ge->executar();

          gg->limpar();
          gg->renderizar(&ret);
          gg->mostrar();
     }
}

void testeVertexArray()
{
     //Instancia o gerenciador GerenciadorGrafico
     sf::RenderWindow window(sf::VideoMode(50, 23), "HEYHEYHEY!");

     sf::VertexArray lines(sf::LineStrip, 4);
     lines[0].position = sf::Vector2f(10,  5);
     lines[1].position = sf::Vector2f(20, 10);
     lines[2].position = sf::Vector2f(30, 10);
     lines[3].position = sf::Vector2f(10,  5);

     window.clear();
     window.draw(lines);
     window.display();

     while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

          window.clear();
          window.draw(lines);
          window.display();
    }
}

void testeJogador()
{
     sf::Time tempo;

     float t0 = tempo.asMilliseconds();
     float t1 = t0;

     Gerenciadores::GerenciadorGrafico* gg = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();

     Jogador jog (new sf::CircleShape(50), 10);

     while (gg->janelaAberta())
     {
          gg->limpar();

          t0 = t1;
          t1 = tempo.asMilliseconds();

          jog.executar();
          jog.moverse(t1-t0);
          jog.desenhar();
          
          gg->mostrar();
     }
}

void testeForma()
{
     //Instancia o gerenciador GerenciadorGrafico
     Gerenciadores::GerenciadorGrafico* gg = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();

     //Instancia o gerenciador de GerenciadorEventoss
     Gerenciadores::GerenciadorEventos* ge = Gerenciadores::GerenciadorEventos::getGerenciadorEventos();

     /*//Instancia um quadrado ciano
     sf::RectangleShape ret(sf::Vector2f(100.f, 100.f));
     ret.setFillColor(sf::Color::Cyan);*/

     //Instancia uma forma
     ElementosGraficos::Forma* pForma = new ElementosGraficos::Forma(CAMINHO_TEXTURA,//obs.: arrumar caminho
                                                                     Coordenada::Vetor2f(10.0,10.0), //posição
                                                                     Coordenada::Vetor2f(50.7,48.1), //tamanho
                                                                     3.0); //escala

     /*//Associa o quadrado ao ge
     ge->setForma(&ret);*/

     //Associa a forma ao ge
     ge->setForma(pForma);

     while (gg->janelaAberta())
     {
          /* 
           * Substitui o loop mais interno do teste anterior, assim permite realizar o teste de maneira
           * completamente desacoplada da biblioteca gráfica.
           */
          ge->executar();

          gg->limpar();
          //gg->renderizar(&ret);
          pForma->renderizar();
          gg->mostrar();
     }
}