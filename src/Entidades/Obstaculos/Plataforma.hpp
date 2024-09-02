#ifndef _PLATAFORMA_HPP
#define _PLATAFORMA_HPP

#include "Entidades/Obstaculos/Obstaculo.hpp"
#include <iostream>
#include <fstream>

namespace Entidades::Obstaculos
{
    class Plataforma : public Obstaculo
    {
    private:
        const bool armadilha;
        bool caindo;
        float tempoDuracao;
        float tempoAtual;

    public:
        Plataforma(float largura = 300.f, float altura = 50.f, Especie _especie = plataforma):
            armadilha(false),
            caindo(false),
            tempoDuracao(3),
            tempoAtual(0.0f),
            Obstaculo(_especie, false)
        {
            setAcelVertical(-1000.f);
            setTamanho(largura, altura);
        }

        ~Plataforma()
        {

        }

        void executar(const float dT)
        { }

        virtual void obstacular(Jogador* pJog) 
        { }

        void salvar(std::ofstream &os) 
        {
            nlohmann::ordered_json j;
            j ["especie"]    = getEspecie();
            j ["pos"]        = { {"x", getX()    }, {"y", getY()    } };
            j ["tam"]        = { {"x", getTam().x}, {"y", getTam().y} };

            os   << j << "\n";
        }
        
        virtual void carregar(nlohmann::ordered_json &j) 
        {
            setX(j["pos"]["x"]);
            setY(j["pos"]["y"]);

            setTamanho( j["tam"]["x"], j["tam"]["y"]);
        }
    };
}

#endif