#include "Estrela.hpp"
#define COOLDOWN_ESTRELA 3.0F 

Fases::Tuneis* Inimigos::Estrela::pFase = NULL;

Inimigos::Estrela::Estrela():
    Inimigo(Especie::inimigo, 30),
    arrependimento(false),
    nivelMaldade(5),
    nCapangas(20)
{
    setMaldade(153.f);
    setTextura("../img/estrela_raivosa.png", true);
    setTamanho(150.f, 150.f);
}

Inimigos::Estrela::~Estrela()
{
}

void Inimigos::Estrela::arrependerse()
{
    arrependimento = true;
    nivelMaldade = -15;
    setTextura("../img/estrela_triste.png", false);
}

const bool Inimigos::Estrela::chamaCapangas()
{
    //pFase->criarQuadrado(getX(), getY());
    momentoUltimaChamada = pGG->getTempo();
    pFase->criarQuadrado(getX() + (rand()%10), getY());
    nCapangas--;
    return true;
}

void Inimigos::Estrela::danificar(Personagem *pPers)
{
    if(!arrependimento) pPers->receberDano(nivelMaldade * (int) arrependimento, true);
}

void Inimigos::Estrela::reagirAhColisao(Entidade *pE)
{
    //if(pE->getEspecie() == jogador) danificar(static_cast<Personagem*>(pE));
}

void Inimigos::Estrela::atacar()
{
    chamaCapangas();
    pFase->criarProjetil(getX()+70.f, getY()-10.f);
    pFase->criarProjetil(getX()-70.f, getY()-10.f);
    pFase->criarProjetil(getX(),      getY()-75.f);
}

void Inimigos::Estrela::executar(const float deltaT)
{
    arrependimento = nCapangas <= 0;

    if(arrependimento)
    {
        nivelMaldade = -15;
        // MOSTRAR TEXTO NA TELA, DIZENDO PARA JOGADORES IREM EMBORA.
    }
    else if (! pFase->verificaGameOver() && pGG->getTempo() > momentoUltimaChamada+COOLDOWN_ESTRELA)
    {
        // MOSTRAR TEXTO NA TELA, AMEACANDO OS JOGADORES.
        atacar();
    }
}