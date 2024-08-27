#include "Gerenciadores/GerenciadorColisoes.hpp"
#include "Coordenada.hpp"
#include <iostream>

using namespace Coordenadas;
using namespace Gerenciadores;
using namespace Entidades;
using namespace Entidades::Obstaculos;
using namespace Listas;
using std::cout;
using std::endl;

GerenciadorColisoes* GerenciadorColisoes::pInstancia = NULL;

GerenciadorColisoes* GerenciadorColisoes::getInstancia()
{
    if(pInstancia == NULL)
            pInstancia = new GerenciadorColisoes();
            
        if (pInstancia)
        {
            return pInstancia;
        }
        else
        {
            cout << "Em GerenciadorColisoes::getInstancia: " << ERRO_ALOCACAO << endl;
            enterFechar(); // contem exit(1)
        }
}

GerenciadorColisoes::GerenciadorColisoes():
    LI(),
    LJ(),
    LO(),
    itInim(),
    itJoga(),
    itObst(),
    zero(0.0F, 0.0F),
    interseccao(0.0F, 0.0F)
{ }

GerenciadorColisoes::~GerenciadorColisoes()
{ }

void GerenciadorColisoes::verificaInimigos()
{
    Inimigo *pI = NULL;
    Jogador *pJ = NULL;

    for(LI.inicializa(itInim); ! itInim.fim(); itInim++)
    {
        //cout << "GC::VERIFICA_INIMIGOS" << endl;

        pI = itInim.get();

        if(pI)
        {
            for(LJ.inicializa(itJoga); ! itJoga.fim(); itJoga++)
            {
                pJ = itJoga.get();
                //cout << "Encontrei jogador!" << endl;
                if(pJ)
                {
                    interseccao = calcularInterseccao (static_cast<Entidade*> (pJ), static_cast<Entidade*> (pI));

                    if (interseccao > zero)
                    {
                        repelir(static_cast<Entidade*> (pJ), static_cast<Entidade*> (pI), interseccao);
                        pJ->reagirAhColisao(pI);
                        pI->reagirAhColisao(pJ);
                    }
                }
                else
                {
                    // remover jogador
                }
            }
        }
        else
        {
            // retirar ponteiro
        }
    }
}



void GerenciadorColisoes::verificaObstaculos()
{
    Inimigo *pI = NULL;
    Jogador *pJ = NULL;
    Obstaculo *pO = NULL;

    for(LO.inicializa(itObst); ! itObst.fim(); itObst++)
    {


        pO = itObst.get();

        if(pO)
        {
            for(LJ.inicializa(itJoga); ! itJoga.fim(); itJoga++)
            {
                pJ = itJoga.get();
                
                if(pJ)
                {
                    interseccao = calcularInterseccao (static_cast<Entidade*> (pO), static_cast<Entidade*> (pJ));

                    if (interseccao > zero)
                    {
                        if (pO->getPermeavel() == false) 
                            repelir(static_cast<Entidade*> (pJ), static_cast<Entidade*> (pO), interseccao);
                        
                        pJ->reagirAhColisao(pO);
                        pO->reagirAhColisao(pJ);
                    }
                }
                else
                {
                    // remover jogador
                }
            }

            for(LI.inicializa(itInim); ! itInim.fim(); itInim++)
            {
                pI = itInim.get();
                
                if(pI)
                {
                    interseccao = calcularInterseccao (static_cast<Entidade*> (pO), static_cast<Entidade*> (pI));

                    if (interseccao > zero)
                    {
                        if (pO->getPermeavel() == false) 
                            repelir(static_cast<Entidade*> (pI), static_cast<Entidade*> (pO), interseccao);
                        
                        pI->reagirAhColisao(pO);
                        pO->reagirAhColisao(pI);
                    }
                }
                else
                {
                    // remover jogador
                }
            }
        }
        else
        {
            // retirar ponteiro
        }
    }
}


void GerenciadorColisoes::executar()
{
    //cout << "GC::EXECUTAR" << endl;

    verificaInimigos();
    verificaObstaculos();
}

const Vetor2f GerenciadorColisoes::calcularInterseccao(Entidade* pE1, Entidade* pE2) const
{
    // ret recebe a distancia entre os vetores posicoes
    Vetor2f ret = pE1->getPos();
    ret -= pE2->getPos();
    ret.x = abs(ret.x);
    ret.y = abs(ret.y); 
    
    // ret eh decrescido da distancia minima esperada.
    ret -= pE1->getTam()/2.F + pE2->getTam()/2.F;

    // ret tem o sinal trocado para significar a interseccao:
    ret *= -1;

    return ret;
}

void GerenciadorColisoes::repelir (Entidade* pRepelido, Entidade* pRepulsor, Vetor2f interseccao)
{
    //std::cout << "REPELINDO ENTIDADES" << endl;

    // REPELIR NO EIXO-X SOMENTE
    if(interseccao.x < interseccao.y && interseccao.x > 0.f)
    {
        if (pRepelido->getX() < pRepulsor->getX())
        {
            pRepelido->setX(pRepelido->getX() - interseccao.x);
            if (pRepelido->getVel().x < 0.0f)
                pRepelido->setX(0.0f);
        }
        else
        {
            pRepelido->setX(pRepelido->getX() + interseccao.x);
            if (pRepelido->getVel().x > 0.0f)
                pRepelido->setX(0.0f);
        }
        
        pRepelido->setVelX(0.0f);
    }
    else if (interseccao.y > 0.F)// REPELIR NO EIXO-Y SOMENTE.
    {
        if (pRepelido->getY() < pRepulsor->getY())
        {
            pRepelido->setY(pRepelido->getY() - interseccao.y);
            if (pRepelido->getVel().y < 0.0f)
                pRepelido->setY(0.0f);
        }
        else
        {
            pRepelido->setY(pRepelido->getY() + interseccao.y);
            if (pRepelido->getVel().y > 0.0f)
                pRepelido->setY(0.0f);
        }

        pRepelido->setVelY(0.0f);
    }
    else 
    {
        cout << "AVISO: COLISAO FALSA!" << endl;
    }
}