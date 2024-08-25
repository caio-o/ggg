#ifndef _ITERADOR_ABSTRATO_HPP
#define _ITERADOR_ABSTRATO_HPP


// << ABSTRACT ITERATOR >>
// Usa-se template para garantir a existencia de get, set e conteudo. Nao sei se isso eh necessario, e devo checar no livro se tiver tempo.
template<class TI>
class IteradorAbstrato
{
private:
    TI conteudo;

public:
    IteradorAbstrato();
    virtual ~IteradorAbstrato();

    virtual TI get() const = 0;
    virtual void set() = 0;
    virtual void       proximo() = 0;
    const virtual bool temProximo() const = 0;
    //const virtual      proximo();
};

template<class TI>
IteradorAbstrato<TI>::IteradorAbstrato(/* args */)
{
}

template<class TI>
IteradorAbstrato<TI>::~IteradorAbstrato()
{
}


#endif