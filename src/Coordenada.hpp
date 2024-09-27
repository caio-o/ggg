/*
 * AUTOR(A)  : Ana Julia Molinos Leite da Silva
 * ALTERAÇÕES: Caio e Silva Barbieri
 * DESCRIÇÃO : Classe template para manipular variáveis do tipo Coordenada (i.e, que possuem duas 
 *             medidas do mesmo tipo).
 * CRÉDITOS  : Código baseado na implementação do aluno Matheus Augusto Burda. Repositório disponível
 *             em https://github.com/MatheusBurda/Desert, tutorial disponível em: 
 *             https://youtu.be/xD3A4CDlwpI?si=guwaJHT4CpmGvv2b
 * */

#pragma once

#ifndef _COORDENADA_HPP
#define _COORDENADA_HPP

#include <iostream>
using namespace std;

namespace Coordenadas
{
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

            //Realiza a soma em ambos os valores x e y
            Coordenada<TIPO> operator+(const Coordenada<TIPO> soma) const
            {             
                return Coordenada(x+soma.x, y+soma.y);
            }

            //Realiza a subtração em ambos os valores x e y
            Coordenada<TIPO> operator-(const Coordenada<TIPO> subtracao) const
            {
                return Coordenada(x-subtracao.x, y-subtracao.y);
            }

            //Realiza a multiplicação em ambos os valores x e y pelo fator escalar
            Coordenada<TIPO> operator*(const TIPO fatorEscalar) const
            {
                return Coordenada(x*fatorEscalar, y*fatorEscalar);
            }

             //Realiza a divisão em ambos os valores x e y pelo divisor escalar
            Coordenada<TIPO> operator/(const TIPO divisorEscalar) const
            {
                if(divisorEscalar!=0)
                    return Coordenada(x/divisorEscalar, y/divisorEscalar);
                
                cout << "Impossivel dividir por zero!" << endl;
                exit(1);
            }

           //Ambos os valores x e y são incremetados pelos valores x e y de soma 
            void operator+=(const Coordenada<TIPO> soma)
            {
                x += soma.x;
                y += soma.y;
            }

            //Ambos os valores x e y são decrementados pelos valores x e y de subtracao
            void operator-=(const Coordenada<TIPO> subtracao)
            {
                x -= subtracao.x;
                y -= subtracao.y;
            }

            //Ambos os valores x e y são multiplicados pelos valores x e y do fator escalar
            void operator*=(const TIPO fatorEscalar)
            {
                x *= fatorEscalar;
                y *= fatorEscalar;
            }

            //Ambos os valores x e y são divididos pelos valores x e y do fator escalar
            void operator/=(const TIPO divisorEscalar)
            {
                if(divisorEscalar!=0)
                {
                    x /= divisorEscalar;
                    y /= divisorEscalar;
                }
                else
                    cout << "Impossivel dividir por 0!" << endl;
            }

            //Ambos os valores x e y são substituidos pelos valores x e y de outro
            void operator=(const Coordenada<TIPO> outro)
            {
                x = outro.x;
                y = outro.y;
            }

            //Retorna true se a comparação for verdadeira entre ambos os valores de x e y com outroVetor
            const bool operator<(Coordenada<TIPO> outroVetor) const
            {
                return (bool) (x < outroVetor.x && 
                               y < outroVetor.y    );
            }

            //Retorna true se a comparação for verdadeira entre ambos os valores de x e y com outroVetor
            const bool operator>(Coordenada<TIPO> outroVetor) const
            {
                return (bool) (x > outroVetor.x && 
                               y > outroVetor.y    );
            }
    };

    typedef Coordenada<float> Vetor2f;
} // namespace Coordenada


#endif