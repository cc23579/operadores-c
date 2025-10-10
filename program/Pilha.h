#ifndef PILHA_H
#define PILHA_H

#include "Lista.h"
#include <stdexcept>

template <typename T>
class Pilha : public Lista<T> {
    
    using typename Lista<T>::pNo;
    using Lista<T>::Inicio;

public:
    // Construtor
    Pilha() : Lista<T>() {}

    // Destrutor
    ~Pilha() {}

   
    void Empilhar(const T& valor) {
        this->InsiraNoInicio(valor);
    }

   
    T Desempilhar() {
        if (this->Vazia()) {
            
            throw std::runtime_error("Erro: Pilha vazia ao tentar desempilhar!");
        }
        pNo temp = Inicio;
        T valor = temp->Info;
        Inicio = Inicio->Prox;
        delete temp;
        return valor;
    }

    
    T Topo() const {
        if (this->Vazia()) {
            throw std::runtime_error("Erro: Pilha vazia ao tentar ver o topo!");
        }
        return Inicio->Info;
    }
};

#endif