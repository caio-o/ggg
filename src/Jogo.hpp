#ifndef _JOGO_HPP
#define _JOGO_HPP

#include "Fases/Fase.hpp"
#include "Fases/Calabouco.hpp"
#include "Entidades/Personagens/Jogador.hpp"

#include "json.hpp"
using Fases::Fase;

class Jogo
{
private:
    static Jogador *pJog1;
    static Jogador *pJog2;

    Gerenciadores::GerenciadorGrafico *pGG;
    Gerenciadores::GerenciadorEventos *pGE;
    Gerenciadores::GerenciadorEstados *pGEs;
    //Fase* primeiraFase;
    //Fase* segundaFase;

    void carregarJogador1(nlohmann::ordered_json j);
    void carregarJogador2(nlohmann::ordered_json j);

public:
    static Jogador* getJogador1();
    static Jogador* getJogador2();
    static void     setJogador1(Jogador* jog);
    static void     setJogador2(Jogador* jog);
    Jogo();
    ~Jogo();

    void executar();
};




#endif