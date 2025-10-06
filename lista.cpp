#include "Lista.h"

template <typename T>
char Lista<T>::Erro = 0;

template <typename T>
Lista<T>::Lista() : Valida(1), Inicio(nullptr) {}

template <typename T>
Lista<T>::~Lista() { DescarteTudoInterno(); }

template <typename T>
void Lista<T>::DescarteTudoInterno() {
    while (Inicio != nullptr) {
        pNo temp = Inicio;
        Inicio = Inicio->Prox;
        delete temp;
    }
}

template <typename T>
char Lista<T>::DeuErro() { return Erro; }

template <typename T>
char Lista<T>::eValida() const { return Valida; }

template <typename T>
bool Lista<T>::Vazia() const { return Inicio == nullptr; }

template <typename T>
void Lista<T>::Insira(const T& I) {
    pNo novo = new sNo;
    novo->Info = I;
    novo->Prox = Inicio;
    Inicio = novo;
}

template <typename T>
int Lista<T>::Contem(const T& I) const {
    pNo aux = Inicio;
    while (aux != nullptr) {
        if (aux->Info == I)
            return 1;
        aux = aux->Prox;
    }
    return 0;
}

template <typename T>
void Lista<T>::Descarte(const T& I) {
    if (Vazia()) return;

    if (Inicio->Info == I) {
        pNo temp = Inicio;
        Inicio = Inicio->Prox;
        delete temp;
        return;
    }

    pNo atual = Inicio;
    while (atual->Prox != nullptr && atual->Prox->Info != I)
        atual = atual->Prox;

    if (atual->Prox != nullptr) {
        pNo temp = atual->Prox;
        atual->Prox = temp->Prox;
        delete temp;
    }
}

template <typename T>
void Lista<T>::DescarteTudo() {
    DescarteTudoInterno();
}

template <typename T>
std::string Lista<T>::NaFormaDeString() const {
    std::ostringstream oss;
    pNo aux = Inicio;
    while (aux != nullptr) {
        oss << aux->Info;
        if (aux->Prox != nullptr) oss << " -> ";
        aux = aux->Prox;
    }
    return oss.str();
}
