/** 
 *   AUTORES : Caio Barbieri & 
 *   DATA    : 9/08/2024
 *   Arquivo que implementa os testes definidos em "testes.hpp".
 * 
 *  Para descricaoes das funcoes e detalhes de autoria vide "testes.hpp".
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include "Lista.hpp"
#include "testes.hpp"

using namespace std;
using namespace Listas;

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