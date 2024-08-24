#include "Entidades/Entidade.hpp"

using namespace Entidades;

Entidade::Entidade():
    Ente          (/*_pForma*/),
    tam(50.f,50.f),
    pos           (10.0f, 10.0f),
    vel           (0.0f, 0.0f),
    modGravidade  (1.0f, 1.0f),
    forma()
{ 
    /*cout << "Entidade::Entidade:" << endl;
    cout << "    pForma = " << pForma << endl; */

    setForma(Forma(pos, tam, "../img/quadrado_vermelho.png"));
}

Entidade::Entidade(Forma _forma):
    Ente          (/*_pForma*/),
    tam(50.f,50.f),
    pos           (10.0f, 10.0f),
    vel           (0.0f, 0.0f),
    modGravidade  (1.0f, 1.0f),
    forma(_forma)
{ 
    /*cout << "Entidade::Entidade:" << endl;
    cout << "    pForma = " << pForma << endl; */
}

Entidade::~Entidade() 
{ }

void Entidade::desenhar ()
{
    cout << "DESENHAR 1" << endl;
    //cout << "Entidade::desenhar:" << endl;
    forma.atualizar(pos);

    cout << "DESENHAR 2" << endl;
    forma.renderizar();

    cout << "DESENHAR FIM" << endl;
    //Ente::desenhar();
}

void Entidade::moverse(const float n_segundos)
{
    /*if (pos.y > (float) (Ente::pGG->getJanela()->getSize().y) - 10) 
    { 
        //vel.y += GRAVIDADE;
    }
    else if (vel.y > 0.0f)
    {
        vel.y = 0.0f;
    }*/
    
    pos += vel * n_segundos;
}