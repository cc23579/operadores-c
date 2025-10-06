#include "Pilha.h"
#include <iostream>

template <typename T>
Pilha<T>::Pilha() : Lista<T>() {}

template <typename T>
Pilha<T>::~Pilha() {
    this->DescarteTudo();
}

template <typename T>
void Pilha<T>::Empilhar(const T& valor) {
    this->Insira(valor);
}

template <typename T>
T Pilha<T>::Desempilhar() {
    if (this->Vazia()) {
        std::cerr << "Erro: Pilha vazia!\n";
        return T();
    }

    T valor = Inicio->Info;
    pNo temp = Inicio;
    Inicio = Inicio->Prox;
    delete temp;
    return valor;
}

template <typename T>
T Pilha<T>::Topo() const {
    if (this->Vazia()) {
        std::cerr << "Erro: Pilha vazia!\n";
        return T();
    }
    return Inicio->Info;
}
