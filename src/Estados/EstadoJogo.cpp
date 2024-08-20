/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe derivada EstadoJogo, responsável por executar métodos específicos
 *             a execução do jogo e fases.
 */

#include "Erros.hpp"

#include "EstadoJogo.hpp"

#include "iostream"
using namespace std;

namespace Estados
{
    
    EstadoJogo::EstadoJogo(idEstados):
    Estado(id),
    pFase(NULL)
    {

    }

    EstadoJogo::~EstadoJogo()
    {
        id = desconhecido;
        
        if(pFase)
            delete pFase;
        
        pFase = NULL;
    }

    void EstadoJogo::renderizar()
    {
        //Não sei se esse método faz sentido aqui, fiquei confusa
        
        /*
         * if(pFase)
         *  pFase->renderizar();
         * else
         *  cout << ... << endl;
         */
    }

    void EstadoJogo::criarFase()
    {
        /*
         * if(id == Fase1)
            pJogo = new Fase1()...
         */

        /*
         * Aqui deve haver um else if para testar qual ID foi passada por parametro na construtora
         * de modo a escolher qual fase vai ser criado.
         * Em cada caso, os passos são:
         * 1: realizar alocação dinamica de um ponteiro do tipo descrito na ID;
         * 2: chamar a função ->criarFase() (ou semelhante) desse ponteiro;
         * 3: setar o observador desse objeto como ativo por meio do método setObservador(true);
         * 4: fazer static cast para o tipo Fase* e atribuir esse ponteiro ao atributo pFase;
         */
    }

    Fase* EstadoJogo::getFase() const
    {
        if(pFase)
            return pFase;
        
        cout << "Erro em Estados::EstadoJogo: " << ERRO_RETURN_NULLPTR << endl;
        return pFase;
    }

    void EstadoJogo::passarFase()
    {
        /*
         * Gerenciadores::Estados* pGE = Gerenciadores::Estados::getEstado();
         * 
         * Analisar como o estado vai saber quando passa de fase
         * if(fase atual terminou && fase atual é a fase1)
         *  pGe->empilharEstado(fase2);
         */
    }

    void EstadoJogo::setObservador(const bool b)
    {
        /*
         * Algo como: pFase->getObservador()->setAtivo(b)
         * ou ainda: pFase->setObservador(b);
         * (cada ente que precisa ser notificado possui e conhece seu próprio observador)
         * 
         * Caso a fase possua um ponteiro para os jogadores, é necessário ativar seus observadores
         * também, pois a execução de uma fase implica na execução de jogadores.
         * pFase->getJogador()->getObservador->setAtivo(b);
         * pFase->getJogador()->setObservador(b);
         */
    }

    void EstadoJogo::executar()
    {
        /*
         * criarFase();
         * renderizar();
         */

        /*
         * ou ainda:
         * if(pFase)
         *  pFase->executar();
         * else
         *  ...
         * 
         * (acredito que essa seja a forma mais correta, respeitando os principios de coesão e 
         * desacoplamento)
         */
    }

} // namespace Estados
