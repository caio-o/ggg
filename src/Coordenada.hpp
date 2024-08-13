
/*
 * AUTOR(A): Ana Julia Molinos Leite da Silva (ana-molinos)
 * DATA: 12/08/2024
 * Classe template para manipular variáveis do tipo Coordenada
 * (i.e, que possuem duas medidas do mesmo tipo).
 * */
#pragma once

#include <iostream>
using namespace std;

template <typename TIPO>
class Coordenada
{
    public:
        TIPO x;
        TIPO y;

        Coordenada(TIPO xx=0, TIPO yy=0):
        x(xx),
        y(yy)
        {

        }

        ~Coordenada()
        {

        }

        Coordenada<TIPO> operator+(Coordenada<TIPO> soma)
        {             
            return Coordenada(x+soma.x, y+soma.y);
        }

        Coordenada<TIPO> operator-(Coordenada<TIPO> subtracao)
        {
            return Coordenada(x-subtracao.x, y-subtracao.y)
        }

        Coordenada<TIPO> operator*(TIPO fatorEscalar)
        {
            return Coordenada(x*fatorEscalar, y*fatorEscalar);
        }

        Coordenada<TIPO> operator/(TIPO divisorEscalar)
        {
            if(divisorEscalar!=0)
                return Coordenada(x/divisorEscalar, y/divisorEscalar);
            
            cout << "Impossivel dividir por zero!" << endl;
            exit(1);
        }

        void operator+=(Coordenada<TIPO> soma)
        {
            x += soma.x;
            y += soma.y;
        }

        void operator-=(Coordenada<TIPO> subtracao)
        {
            x -= subtracao.x;
            y -= subtracao.y;
        }

        void operator*=(TIPO fatorEscalar)
        {
            x *= fatorEscalar;
            y *= fatorEscalar;
        }

        void operator/=(TIPO divisorEscalar)
        {
            if(divisorEscalar!=0)
            {
                x /= divisorEscalar;
                y /= divisorEscalar;
            }
            else
                cout << "Impossivel dividir por 0!" << endl;
        }

        void operator=(Coordenada<TIPO> outro)
        {
            x = outro.x;
            y = outro.y;
        }
};