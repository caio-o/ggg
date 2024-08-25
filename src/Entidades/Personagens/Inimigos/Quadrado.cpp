#define TEXTURA "../img/quadrado_vermelho.png"

#define RANGE_ATAQUE 100.0
#define RANGE_PERSEGUE 300.0
#define VELOCIDADE 250.0
#define VELOCIDADE_DASH 1000.0

#include "Gerenciadores/GerenciadorGrafico.hpp"

#include "math.h"
#include "Quadrado.hpp"

namespace Inimigos
{
    Quadrado::Quadrado(Especie _especie, int maxVida, int dano):
    Inimigo(_especie, maxVida, dano)
    {
        forma.setTextura(TEXTURA, true);
        
        //PROVISÓRIO: Seta a posição do quadrado no centro da janela
        //Gambiarra?
        Gerenciadores::GerenciadorGrafico* pgg = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();

        pos.x = (pgg->getTamanhoJanela().x)/2;
        pos.y = (pgg->getTamanhoJanela().y/2);
    }

    Quadrado::~Quadrado()
    {
        dano = -1;
        maxVida = -1;
        vida = -1;
        vivo = false;        
    }

    void Quadrado::salvar()
    {
        
    }

    void Quadrado::executar()
    {
        //Se o jogador estiver dentro do range de perseguição...
        if(rangePerseguir() && vel.x == 0.0)
        {
            //... o inimigo passa a se mover a uma velocidade pré-definida em sua direção
            vel.x = VELOCIDADE;

            if(jogadorAesquerda())
                vira();

                cout << "Quadrado persegue" << endl;
        }
        //Se o jogador estiver dentro do range de ataque, chama a função atacar
        else if (rangeAtacar())
        {
            atacar();
            cout << "Quadrado ataca" << endl;
        }
        //Caso contrário, o quadrado fica parado "camuflado" no cenário
        else
        {
            vel.x = 0.0;
            cout << "Quadrado parado" << endl;
        }
        
        //moverse();

    }

    void Quadrado::mover()
    {

    }

    //PROVISÓRIO: aumenta a velocidade em diração ao jogador, executando um "dash"
    void Quadrado::atacar()
    {
        vel.x = VELOCIDADE_DASH;

        if(jogadorAesquerda())
            vira();
    }

    //Muda o sinal da velocidade no eixo x
    void Quadrado::vira()
    {
        vel.x *= -1.0;
    }

    //Retorna true se algum jogador estiver no range de perseguição do quadrado
    bool Quadrado::rangePerseguir()
    {
        if(pJogador2)
            return (bool)(abs(pJogador1->getPos().x - pos.x) < RANGE_PERSEGUE ||
                          abs(pJogador2->getPos().x - pos.x) < RANGE_PERSEGUE);

        return (bool)(abs(pJogador1->getPos().x - pos.x) < RANGE_PERSEGUE);
    }

    //Retorna true se algum jogador estiver no range de ataque do quadrado
    bool Quadrado::rangeAtacar()
    {
        if(pJogador2)
            return (bool)(abs(pJogador1->getPos().x - pos.x) < RANGE_ATAQUE ||
                          abs(pJogador2->getPos().x - pos.x) < RANGE_ATAQUE);

        return (bool)(abs(pJogador1->getPos().x - pos.x) < RANGE_ATAQUE);
    }

    //Retorna true se o jogador estiver a esquerda do inimigo
    bool Quadrado::jogadorAesquerda()
    {
        if(pJogador2)
            return (bool)(pJogador2->getPos().x < pos.x ||
                          pJogador1->getPos().x < pos.x);

        return (bool)(pJogador1->getPos().x < pos.x);
    }

} // namespace Inimigos
