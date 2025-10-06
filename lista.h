#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <sstream>

template <typename T>
class Lista {
protected:
    struct sNo {
        T Info;
        sNo* Prox;
    };
    using pNo = sNo*;

    static char Erro;
    char Valida;
    pNo Inicio;

    void DescarteTudoInterno();

public:
    static char DeuErro();
    char eValida() const;

    Lista();
    virtual ~Lista();

    bool Vazia() const;
    virtual void Insira(const T& I);
    int Contem(const T& I) const;
    void Descarte(const T& I);
    void DescarteTudo();
    std::string NaFormaDeString() const;
};

#include "Lista.cpp"  

#endif
