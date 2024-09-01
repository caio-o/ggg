#ifndef _OBSTACULO_HPP
#define _OBSTACULO_HPP

#include "Entidades/Entidade.hpp"

namespace Entidades
{
    class Jogador;

    namespace Obstaculos
    {
        class Obstaculo : public Entidade
        {
        private:
            const bool permeavel; // A ser definida na construtora de cada obstaculo.

        public:
            Obstaculo(Especie _especie = indefinido, const bool _permeavel = false);

            virtual ~Obstaculo(){ }

            virtual void salvar(std::ofstream &os) = 0;
            virtual void carregar(nlohmann::ordered_json &j) = 0;
            virtual void obstacular (Jogador* pJ) = 0;
            virtual void executar (const float dT) = 0;
            virtual void reagirAhColisao(Entidade *pE);
            const bool getPermeavel() const { return permeavel; }
        };
    }
}

#endif