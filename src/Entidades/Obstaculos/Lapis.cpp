/*
 * AUTORA    : Ana Julia Molinos Leite da Silva
 * DESCRIÇÃO : Implementação da classe responsável por definir o comportamento do obstáculo tipo Lapis
 *             que dá dano ao contato com o jogador.
 */

#include "Lapis.hpp"
#include "Erros.hpp"
#include <iostream>
#include <fstream>

#define CAMINHO_TEXTURA "../img/lapis.png" //textura provisória

namespace Entidades
{
    namespace Obstaculos
    {
        Lapis::Lapis(const bool _permeavel, const int dano):
        Obstaculo(obstaculo, _permeavel),
        dano(dano)
        {
            setAcelVertical(-1000.f);
            forma.setTextura(CAMINHO_TEXTURA, true);
            vel.x = 0.0;
            setTamanho(80.f, 80.f);
        }

        Lapis::~Lapis()
        {
            especie = indefinido;
            dano = -1;
        }

        void Lapis::salvar(std::ofstream &os)
        {
            nlohmann::ordered_json j;
            j ["especie"]    = lapis;
            j ["pos"]        = { {"x", getX()    }, {"y", getY()    } };
            j ["tam"]        = { {"x", getTam().x}, {"y", getTam().y} };
            j ["dano"]       = dano;

            os   << j << "\n";
        }

        void Lapis::carregar(nlohmann::ordered_json &j)
        {
            setPos     (j["pos"]["x"], j["pos"]["y"]);
            setTamanho (j["tam"]["x"], j["tam"]["y"]);
            setDano    (j["dano"]);

        }

        void Lapis::executar(const float dT)
        {
            vel.x = 0.0;
        }

        //Dá dano ao jogador que colide com o objeto em questão
        void Lapis::obstacular(Jogador *pJog)
        {
            pJog->receberDano(dano, true);
        }

        //Seta o dano do obstáculo Lapis
        void Lapis::setDano(const int d)
        {
            dano = d;
        }

        //Retorna o dano do obstáculo Lapis
        const int Lapis::getDano() const
        {
            return dano;
        }
    } // namespace Obstaculos
    
} // namespace Entidades
