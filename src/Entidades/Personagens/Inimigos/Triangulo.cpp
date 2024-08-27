#include "Triangulo.hpp"

#define CAMINHO_TEXTURA "../../img/triangulo_amarelo.png"

#define COOLDOWN 3.0 //segundos

namespace Inimigos
{
    Triangulo::Triangulo(Especie _especie, int maxVida, int dano):
    Inimigo(_especie, maxVida),
    cooldown(COOLDOWN),
    tempoUltimoAtaque(0.0)
    {
        forma.setTextura(CAMINHO_TEXTURA, true);
    }

    Triangulo::~Triangulo()
    {
        cooldown = -1.0;
    }

    void Triangulo::salvar()
    {

    }

    void Triangulo::executar(const float dT)
    {
        vel.x = 0.0;

        tempoUltimoAtaque += dT;

        if(tempoUltimoAtaque > cooldown)
        {
            atacar();

            tempoUltimoAtaque = 0.0;
        }
    }

    void Triangulo::atacar()
    {
        //pFase->criarProjetil(pos.x, pos.y);
        //a ideia seria q o triangulo chamasse esse método da fase pra ela alocar o projétil e add
        //ele na sua propria lista (as posições do triangulo seriam a origem do projetil)
    }

    void Triangulo::reagirAhColisao(Entidade* pE)
    {
        //não faz nada?
    }

} // namespace Inimigos
