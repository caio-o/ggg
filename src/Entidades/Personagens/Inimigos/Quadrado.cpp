#define TEXTURA "../img/quadrado_vermelho.png"

#define RANGE_ATAQUE 100.0
#define RANGE_PERSEGUE 300.0
#define VELOCIDADE 250.0
#define VELOCIDADE_DASH 1000.0
#define COOLDOWN 3.0 //(segundos)
#define DURACAO_ATAQUE 2.0F

#include "Gerenciadores/GerenciadorGrafico.hpp"

#include "math.h"
#include "Quadrado.hpp"

namespace Inimigos
{
    Quadrado::Quadrado(Especie _especie, int maxVida, int dano):
    Inimigo(_especie, maxVida, dano),
    esquerda(false),
    atacando(false),
    tempoUltimoAtaque(0.0),
    cooldown(COOLDOWN)
    {
        forma.setTextura(TEXTURA, true);
    }

    Quadrado::~Quadrado()
    {
        dano = -1;
        maxVida = -1;
        vida = -1;
        vivo = false;       
        tempoUltimoAtaque - -1.0;
        cooldown = -1; 
    }

    void Quadrado::salvar()
    {
        
    }

    void Quadrado::executar(const float dT)
    {
        tempoUltimoAtaque += dT;
        //cout << tempoUltimoAtaque << endl;

        // MUDANÇA (Caio): Em vez de "atacando" receber false em toda iteração, recebe só quando passou o tempo de ataque.
        //     Fiz isso para que o quadrado possa dar dano no jogador.
        if (tempoUltimoAtaque >= DURACAO_ATAQUE) atacando = false;
        
        //Se o jogador estiver dentro do range de perseguição...
        if(rangePerseguir() && vel.x == 0.0 && tempoUltimoAtaque>cooldown/2)
        {
            //... o inimigo passa a se mover a uma velocidade pré-definida em sua direção
            vel.x = VELOCIDADE;

            if(jogadorAesquerda())
                vira();

        //cout << "Quadrado persegue" << endl;
        }
        //Se o jogador estiver dentro do range de ataque e o último ataque superou o cooldown, 
        //chama a função atacar
        else if (rangeAtacar() && tempoUltimoAtaque>cooldown)
        {
            atacar();
            cout << "Quadrado ataca" << endl;
        }
        //Caso contrário, o quadrado fica parado "camuflado" no cenário
        else if(!rangeAtacar() && !rangePerseguir() && tempoUltimoAtaque>cooldown/2)
        {
            vel.x = 0.0;
            //cout << "Quadrado parado" << endl;
        }
        
        moverse(dT);

    }

    /*
     * Executa um dash na direção do jogador, seta a flag atacando como true e reinicia a contagem
     * de tempo do último ataque.
     */
    void Quadrado::atacar()
    {   
        vel.x = VELOCIDADE_DASH;

        if(jogadorAesquerda())
            vira();
        
        atacando = true;

        tempoUltimoAtaque = 0.0;
    }

    //Muda o sinal da velocidade no eixo x
    void Quadrado::vira()
    {
        vel.x *= -1.0;
    }

    /*
     * Se o ente se tratar de um jogador, verifica se o próprio quadrado está em estado de ataque.
     * Em caso afirmativo, danifica o jogador, como reação a colisão.
     */
    void Quadrado::reagirAhColisao(Entidade* pE)
    {
        if(pE->getEspecie() == jogador && atacando)
            static_cast<Jogador*>(pE)->receberDano(dano, true);
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
