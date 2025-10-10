#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <sstream>
#include <stdexcept>

template <typename T>
class Lista {
protected:
    struct sNo {
        T Info;
        sNo* Prox;
    };
    using pNo = sNo*;

    pNo Inicio;

    void DescarteTudoInterno() {
        while (Inicio != nullptr) {
            pNo temp = Inicio;
            Inicio = Inicio->Prox;
            delete temp;
        }
    }

public:
    // Construtor
    Lista() : Inicio(nullptr) {}

    // Destrutor virtual
    virtual ~Lista() {
        DescarteTudoInterno();
    }

   
    bool Vazia() const {
        return Inicio == nullptr;
    }

   
    void InsiraNoInicio(const T& I) {
        pNo novo = new sNo;
        novo->Info = I;
        novo->Prox = Inicio;
        Inicio = novo;
    }

  
    void DescarteTudo() {
        DescarteTudoInterno();
    }
};

#endif 