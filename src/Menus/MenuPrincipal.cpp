/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe derivada EstadoMenu, responsável por executar métodos específicos
 *             aos menus do jogo.
 */

#include "Erros.hpp"
#include "Gerenciadores/GerenciadorEstados.hpp"
#include "MenuPrincipal.hpp"
#include "Gerenciadores/GerenciadorEventos.hpp"

#include "iostream"
using namespace std;

namespace Menus
{
    MenuPrincipal::MenuPrincipal(idEstados id):
    Estado(id),
    Menu()
    {

    }

    MenuPrincipal::~MenuPrincipal()
    {

    }
    
    void MenuPrincipal::executar(const float dT)
    {
        bool doisJogadores = false;
        
        cout << "Escolha uma das opções abaixo: " << endl
             << "0 - Jogar fase teste;"           << endl
             << "1 - Jogar com um jogador;"       << endl
             << "2 - Jogar com dois jogadores;"   << endl
             << "3 - Recuperar jogo salvo;"       << endl
             << "4 - Ver ranking;"                << endl
             << "5 - Encerrar jogo;"              << endl;

        int op = -1;

        cin >> op;

        //Obs.: só o caso 0 está corretamente implementado até o momento...
        switch (op)
        {
            case 0:
                pGEs->mudarEstado(faseTeste);
            
            //Selecionar jogar com um ou dois jogadores leva ao menu de seleção das fases...
            case 1:
                pGEs->mudarEstado(menuFase);
                break;
            
            case 2:
                doisJogadores = true; //isso funciona?? dois comandos no bloco sem chave?
                pGEs->mudarEstado(menuFase);
                break;
            
            case 5:
                Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico()->fecharJanela();

            default:
                break;
        }
        
    }
    
    void MenuPrincipal::desenhar()
    {

    }

} // namespace Menus
