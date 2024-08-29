#define TEXTURA "../img/quadrado_raivoso.png"

#define RANGE_ATAQUE 100.0
#define RANGE_PERSEGUE 300.0
#define VELOCIDADE 250.0
#define VELOCIDADE_DASH 750.0
#define COOLDOWN 3.0 //(segundos)
#define DURACAO_ATAQUE 2.0

#include "Gerenciadores/GerenciadorGrafico.hpp"

#include "math.h"
#include "Quadrado.hpp"

namespace Inimigos
{
    Quadrado::Quadrado(Especie _especie, int maxVida):
    Inimigo(_especie, maxVida),
    pJogadorPerseguido(pJogador1),
    atacando(false),
    dano(1.0)
    {
        forma.setTextura(TEXTURA, true);
        setTamanho(70.f, 70.f);
    }

    Quadrado::~Quadrado()
    {
        cout << "Quadrado desalocado" << endl;
        
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
        //cout << "QUADRADO EXECUTANDO!" << endl;

        tempoUltimoAtaque += dT;
        //cout << tempoUltimoAtaque << endl;

        // MUDANÇA (Caio): Em vez de "atacando" receber false em toda iteração, recebe só quando passou o tempo de ataque.
        //     Fiz isso para que o quadrado possa dar dano no jogador.
        if (tempoUltimoAtaque >= DURACAO_ATAQUE) atacando = false;
        
        //Se algum jogador estiver dentro do range de perseguição...
        if(rangePerseguir() && !atacando)
        {
            definirPerseguido();
            
            //... o inimigo passa a se mover a uma velocidade pré-definida em sua direção
            vel.x = VELOCIDADE;

            if(jogadorAesquerda())
                vira();

            //cout << "Quadrado persegue" << endl;
        }
        
        //Se o jogador estiver dentro do range de ataque e o último ataque superou o cooldown, 
        //chama a função atacar
        if (rangeAtacar() || atacando)
        {
            vel.x = VELOCIDADE_DASH;

            if(jogadorAesquerda())
                vira();

            if(tempoUltimoAtaque>cooldown)    
            {
                atacar();
                cout << "Quadrado ataca" << endl;
            }
        }
        
        //Caso contrário, o quadrado fica parado "camuflado" no cenário
        if(!rangeAtacar() && !rangePerseguir() && !atacando)
        {
            vel.x = 0.0;
            //cout << "Quadrado parado" << endl;
        }
        
        //moverse(dT);

    }

    /*
     * Executa um dash na direção do jogador, seta a flag atacando como true e reinicia a contagem
     * de tempo do último ataque.
     */
    void Quadrado::atacar()
    {        
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
        
        if(pE->getEspecie() == jogador && atacando/* && pE->getY() >= getY() - getTam().y/2.3*/)
        {
            //static_cast<Jogador*>(pE)->receberDano(dano, true);
            danificar(static_cast<Personagem*>(pE));
            cout << "ReagirAhColisao::dano: " << dano << endl;
        }
    }

    //Define quem será o jogador perseguido com base na menor distância
    void Quadrado::definirPerseguido()
    {
        if(pJogador2 && abs(pJogador1->getPos().x - pos.x) > abs(pJogador2->getPos().x - pos.x))
            pJogadorPerseguido = pJogador2;
        else
            pJogadorPerseguido = pJogador1;
    }

    //Retorna true se algum jogador estiver no range de perseguição do quadrado
    //Range no eixo x: delimitado por constante;
    //Range no eixo y: a soma das metades do tamanho Quadrado e do Jogador.
    bool Quadrado::rangePerseguir()
    {
        if(pJogador2)
            return (bool)((abs(pJogador1->getPos().x - pos.x) < RANGE_PERSEGUE &&
                          (abs(pJogador1->getPos().y - pos.y) < ((pJogador1->getTam().y/2) + (getTam().y/2)))) ||
                          (abs(pJogador2->getPos().x - pos.x) < RANGE_PERSEGUE) &&
                          (abs(pJogador2->getPos().y - pos.y) < ((pJogador2->getTam().y/2) + (getTam().y/2))));

        return (bool)((abs(pJogador1->getPos().x - pos.x) < RANGE_PERSEGUE) && 
                      (abs(pJogador1->getPos().y - pos.y) < ((pJogador1->getTam().y/2) + (getTam().y/2))));
    }

    //Retorna true se algum jogador estiver no range de ataque do quadrado
    //Range no eixo x: delimitado por constante;
    //Range no eixo y: a soma das metades do tamanho Quadrado e do Jogador.
    bool Quadrado::rangeAtacar()
    {        
        if(pJogador2)
            return (bool)(((abs(pJogador1->getPos().x - pos.x) < RANGE_ATAQUE) &&
                           (abs(pJogador1->getPos().y - pos.y) < ((pJogador1->getTam().y/2) + (getTam().y/2)))) ||
                          ((abs(pJogador2->getPos().x - pos.x) < RANGE_ATAQUE)) &&
                           (abs(pJogador2->getPos().y - pos.y) < ((pJogador2->getTam().y/2) + (getTam().y/2))));

        return (bool)((abs(pJogador1->getPos().x - pos.x) <  RANGE_ATAQUE) && 
                      (abs(pJogador1->getPos().y - pos.y) < ((pJogador1->getTam().y/2) + (getTam().y/2))));
    }

    //Retorna true se o jogador perseguido estiver a esquerda do inimigo
    bool Quadrado::jogadorAesquerda()
    {
        return (bool)(pJogadorPerseguido->getPos().x < pos.x);
    }

    void Quadrado::setDano(const int d)
    {
        dano = d;
    }
    
    const int Quadrado::getDano() const
    {
        return dano;
    }

} // namespace Inimigos
