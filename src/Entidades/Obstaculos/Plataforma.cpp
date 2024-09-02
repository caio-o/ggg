#include "Entidades/Obstaculos/Plataforma.hpp"

namespace Entidades::Obstaculos
{
    // Este ultimo parametro eh usado pela contrutora da PlataformaGrudenta
    Plataforma::Plataforma(float largura, float altura, Especie _especie): 
        Obstaculo(_especie, false),
        cor(cinza)
    {
        setAcelVertical(-1000.f);
        setTamanho(largura, altura);
    }

    void Plataforma::salvar(std::ofstream &ofs)
    {
        nlohmann::ordered_json j;
        j ["especie"]    = getEspecie();
        j ["pos"]        = { {"x", getX()    }, {"y", getY()    } };
        j ["tam"]        = { {"x", getTam().x}, {"y", getTam().y} };

        ofs   << j << "\n";
    }

    void Plataforma::carregar(nlohmann::ordered_json &j)
    {
        setX(j["pos"]["x"]);
        setY(j["pos"]["y"]);

        setTamanho( j["tam"]["x"], j["tam"]["y"]);
    }
}