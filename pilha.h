#ifndef PILHA_H
#define PILHA_H

#include "Lista.h"
#include <iostream>

template <typename T>
class Pilha : public Lista<T> {
    using typename Lista<T>::pNo;
    using Lista<T>::Inicio;

public:
    Pilha();
    ~Pilha();

    void Empilhar(const T& valor);
    T Desempilhar();
    T Topo() const;
};

#include "Pilha.cpp"  // 👈 Importante para templates funcionarem

#endif
