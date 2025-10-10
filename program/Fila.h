#ifndef FILA_H
#define FILA_H

#include "Lista.h"
#include <stdexcept>

template <typename T>
class Fila : public Lista<T> {
    using typename Lista<T>::pNo;
    using Lista<T>::Inicio;

public:
    Fila() : Lista<T>() {}
    ~Fila() {}

    // Insere no final da fila
    void Enfileirar(const T& valor) {
        pNo novo = new typename Lista<T>::sNo;
        novo->Info = valor;
        novo->Prox = nullptr;

        if (this->Vazia()) {
            Inicio = novo;
        } else {
            pNo atual = Inicio;
            while (atual->Prox != nullptr) {
                atual = atual->Prox;
            }
            atual->Prox = novo;
        }
    }

   
    T Desenfileirar() {
        if (this->Vazia()) {
            throw std::runtime_error("Erro: Fila vazia!");
        }
        pNo temp = Inicio;
        T valor = temp->Info;
        Inicio = Inicio->Prox;
        delete temp;
        return valor;
    }
};

#endif 