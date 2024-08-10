/** 
 *  Arquivo que implementa os testes definidos em "testes.hpp".
 *  
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Elemento.hpp"
#include "testes.hpp"
//#include "Lista.hpp"

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
    Elemento<int> e1(NULL);
    Elemento<int> e2(NULL);

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