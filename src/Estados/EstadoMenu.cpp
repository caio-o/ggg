/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe derivada EstadoMenu, responsável por executar métodos específicos
 *             aos menus do jogo.
 */

#include "Erros.hpp"

#include "EstadoMenu.hpp"

#include "iostream"
using namespace std;

namespace Estados
{
    EstadoMenu::EstadoMenu(idEstados):
    Estado(id),
    pMenu(NULL)
    {

    }

    EstadoMenu::~EstadoMenu()
    {
        id = desconhecido;
        
        if(pMenu)
            delete pMenu;
        
        pMenu = NULL;
    }

    void EstadoMenu::renderizar()
    {
        //Não sei se esse método faz sentido aqui, fiquei confusa
        
        /*
         * if(pMenu)
         *  pMenu->renderizar();
         * else
         *  cout << ... << endl;
         */
    }

    void EstadoMenu::criarMenu()
    {
        /*
         * if(id == menuPause)
            pMenu = new menuPause()...
         */

        /*
         * Aqui deve haver um switch case para testar qual ID foi passada por parametro na construtora
         * de modo a escolher qual menu vai ser criado.
         * Em cada caso, os passos são:
         * 1: realizar alocação dinamica de um ponteiro do tipo descrito na ID;
         * 2: chamar a função ->criarMenu() (ou semelhante) desse ponteiro;
         * 3: setar o observador desse objeto como ativo por meio do método setObservador(true);
         * 4: fazer static cast para o tipo Menu* e atribuir esse ponteiro ao atributo pMenu;
         */
    }

    Menu* EstadoMenu::getMenu() const
    {
        if(pMenu)
            return pMenu;
        
        cout << "Erro em Estados::EstadoMenu: " << ERRO_RETURN_NULLPTR << endl;
        return pMenu;
    }

    void EstadoMenu::setObservador(const bool b)
    {
        /*
         * Algo como: pMenu->getObservador()->setAtivo(b);
         * (cada ente que precisa ser notificado possui e conhece seu próprio observador)
         */
    }

    void EstadoMenu::executar()
    {
        /*
         * criarMenu();
         * renderizar();
         */

        /*
         * ou ainda:
         * if(pMenu)
         *  pMenu->executar();
         * else
         *  ...
         * 
         * (acredito que essa seja a forma mais correta, respeitando os principios de coesão e 
         * desacoplamento)
         */
    }

} // namespace Estados
