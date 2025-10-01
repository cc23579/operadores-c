#include "lista.h"
#include <iostream>
#include <cstdlib>   // malloc, free
#include <cstring>   // strlen, strcpy, strcat
#include <sstream>   // std::stringstream (melhor que itoa)

char Lista::Erro = 0;

// Construtor
Lista::Lista() {
    this->Inicio = NULL;
    this->Valida = 1;
}

// Destrutor
Lista::~Lista() {
    DescarteTudo();
}

// Marca erro
char Lista::DeuErro() {
    return Erro;
}

// Verifica validade
char Lista::eValida() const {
    return Valida;
}

// Remove todos os nós
void Lista::DescarteTudo() {
    pNo P = Inicio;
    while (P != NULL) {
        pNo Temp = P->Prox;
        free(P);
        P = Temp;
    }
    Inicio = NULL;
}

// Verifica se lista está vazia
bool Lista::Vazia() const {
    return (Inicio == NULL);
}

// Insere ordenado (sem repetição)
void Lista::Insira(int I) {
    pNo A = NULL, P = Inicio;

    while (P != NULL && P->Info < I) {
        A = P;
        P = P->Prox;
    }

    if (P != NULL && P->Info == I) {
        return; // já existe
    }

    pNo N = (pNo) malloc(sizeof(sNo));
    if (N == NULL) {
        Erro = 1;
        return;
    }
    N->Info = I;
    N->Prox = P;

    if (A == NULL) {
        Inicio = N; // insere no início
    } else {
        A->Prox = N;
    }
}

// Verifica se contém
int Lista::Contem(int I) const {
    for (pNo P = Inicio; P != NULL; P = P->Prox) {
        if (P->Info == I)
            return 1;
    }
    return 0;
}

// Remove elemento
void Lista::Descarte(int I) {
    pNo A = NULL, P = Inicio;

    while (P != NULL && P->Info != I) {
        A = P;
        P = P->Prox;
    }

    if (P == NULL) return; // não achou

    if (A == NULL) {
        Inicio = P->Prox; // remove no início
    } else {
        A->Prox = P->Prox;
    }
    free(P);
}

// Converte para string
char* Lista::NaFormaDeString() const {
    std::stringstream ss;
    for (pNo P = Inicio; P != NULL; P = P->Prox) {
        ss << P->Info;
        if (P->Prox != NULL) ss << " -> ";
    }

    std::string temp = ss.str();
    char* resultado = (char*) malloc(temp.size() + 1);
    strcpy(resultado, temp.c_str());
    return resultado;
}
