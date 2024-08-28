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
    LP(),
    itInim(),
    itJoga(),
    itObst(),
    itProj(),
    zero(0.0F, 0.0F),
    interseccao(0.0F, 0.0F)
{ }

GerenciadorColisoes::~GerenciadorColisoes()
{
    cout << "DESTRUINDO GERENCIADOR DE COLISOES." << endl;
}

void GerenciadorColisoes::verificaInimigos()
{
    Inimigo *pI = NULL;
    Jogador *pJ = NULL;

    for(LI.inicializa(itInim); ! itInim.fim(); itInim++)
    {
        //cout << "GC::VERIFICA_INIMIGOS" << endl;

        pI = itInim.get();

        if(pI && pI->getVivo())
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
                        pJ->reagirAhColisao( static_cast<Entidade*> (pI));
                        pI->reagirAhColisao( static_cast<Entidade*> (pJ));
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
                        
                        pJ->reagirAhColisao(static_cast<Entidade*> (pO));
                        pO->reagirAhColisao(static_cast<Entidade*> (pJ));
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
                        
                        pI->reagirAhColisao(static_cast<Entidade*> (pO));
                        pO->reagirAhColisao(static_cast<Entidade*> (pI));
                    }
                }
                else
                {
                    // remover inimigo
                }
            }
        }
        else
        {
            // retirar ponteiro
        }
    }
}

void GerenciadorColisoes::verificaProjeteis()
{
    Inimigo *pI = NULL;
    Jogador *pJ = NULL;
    Projetil *pP = NULL;
    Obstaculo *pO = NULL;
    

    for(LP.inicializa(itProj); ! itProj.fim(); itProj++)
    {


        pP = itProj.get();

        if(pP && pP->getAtivo())
        {
            // VERIFICAR COLISOES PROJETIL-JOGADOR
            for(LJ.inicializa(itJoga); ! itJoga.fim(); itJoga++)
            { 
                pJ = itJoga.get();
                
                if(pJ)
                {
                    interseccao = calcularInterseccao (static_cast<Entidade*> (pP), static_cast<Entidade*> (pJ));

                    if (interseccao > zero)
                    {                
                        pJ->reagirAhColisao(static_cast<Entidade*> (pP));
                        pP->reagirAhColisao(static_cast<Entidade*> (pJ));
                        //LP.remove(&itProj);
                        //LP.removeElemento(itProj.getElem());
                    }
                }
                else
                {
                    // remover jogador
                }
            }

            // VERIFICAR COLISOES PROJETIL-INIMIGO
            /*for(LI.inicializa(itInim); ! itInim.fim(); itInim++)
            {
                pI = itInim.get();
                
                if(pI)
                {
                    interseccao = calcularInterseccao (static_cast<Entidade*> (pP), static_cast<Entidade*> (pI));

                    if (interseccao > zero)
                    {                        
                        pI->reagirAhColisao(static_cast<Entidade*> (pP));
                        pP->reagirAhColisao(static_cast<Entidade*> (pI));
                        LP.removeElemento(itProj.getElem());
                    }
                }
                else
                {
                    // remover inimigo
                }
            }*/

            // VERIFICAR COLISOES PROJETIL-OBSTACULO
            for(LO.inicializa(itObst); ! itObst.fim(); itObst++)
            {
                pO = itObst.get();
                
                if(pO)
                {
                    interseccao = calcularInterseccao (static_cast<Entidade*> (pP), static_cast<Entidade*> (pO));

                    if (interseccao > zero)
                    {                        
                        pO->reagirAhColisao(static_cast<Entidade*> (pP));
                        pP->reagirAhColisao(static_cast<Entidade*> (pO));
                        //LP.remove(&itProj);
                    }
                }
                else
                {
                    // remover obstaculo
                }
            }
        }
        else
        {
            //LP.removeElemento(itProj.getElem());
        }
    }
}


void GerenciadorColisoes::executar()
{
    //cout << "GC::EXECUTAR" << endl;

    verificaInimigos();
    verificaObstaculos();
    verificaProjeteis();
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
    if(interseccao.x < interseccao.y)
    {
        if (pRepelido->getX() < pRepulsor->getX())
        {
            pRepelido->setX(pRepelido->getX() - interseccao.x);
            if (pRepelido->getVel().x > 0.0f)
                pRepelido->setVelX(0.0f);
        }
        else
        {
            pRepelido->setX(pRepelido->getX() + interseccao.x);
            if (pRepelido->getVel().x < 0.0f)
                pRepelido->setVelX(0.0f);
        }
    }
    
    // REPELIR NO EIXO-Y SOMENTE.
    else
    {
        if (pRepelido->getY() < pRepulsor->getY())
        {
            pRepelido->setY(pRepelido->getY() - interseccao.y);
            if (pRepelido->getVel().y > 0.0f)
                pRepelido->setVelY(0.0f);
        }
        else
        {
            pRepelido->setY(pRepelido->getY() + interseccao.y);
            if (pRepelido->getVel().y < 0.0f)
                pRepelido->setVelY(0.0f);
        }
    }
}