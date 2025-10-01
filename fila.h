#ifndef FILA_H
#define FILA_H

#include <cstdlib>   // malloc, free
#include <cstddef>   // NULL
#include "lista.h"

class Fila : public Lista {
public:
    Fila() : Lista() {}

    // Insere no final da fila
    void Enfileire(int valor) {
        pNo N = (pNo) malloc(sizeof(sNo));
        if (!N) { Erro = 1; return; }
        N->Info = valor;
        N->Prox = NULL;

        if (Inicio == NULL) {
            Inicio = N;
        } else {
            pNo P = Inicio;
            while (P->Prox != NULL) P = P->Prox;
            P->Prox = N;
        }
    }

    // Remove do início da fila
    int Desenfileire() {
        if (Inicio == NULL) {
            Erro = 1;
            return -1; // fila vazia
        }
        pNo N = Inicio;
        int valor = N->Info;
        Inicio = Inicio->Prox;
        free(N);
        return valor;
    }
};

#endif
