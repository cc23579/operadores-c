#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

class String {
private:
    static const int MAX_LENGTH = 100; // tamanho máximo da string
    char data[MAX_LENGTH + 1];            // array de chars com \0 no final
    int size;                        // tamanho atual da string

public:
    // Construtor padrão
    String() : size(0) {
        data[0] = '\0';
    }

    // Lê do terminal e armazena na String
    void read() {
        std::cin.getline(data, MAX_LENGTH + 1);
        size = strlen(data);
    }

    // Retorna o tamanho da string
    int length() const {
        return size;
    }

    // Retorna o array de chars
    const char* getString() const {
        return data;
    }

    // Permite acessar os caracteres por índice
    char& operator[](size_t index) {
        return data[index];
    }

    const char& operator[](size_t index) const {
        return data[index];
    }
    
    void append(char c) {
    if (size < MAX_LENGTH) {     // verifica se não ultrapassa o tamanho máximo
        data[size++] = c;        // adiciona o caractere na posição atual
        data[size] = '\0';       // mantém o '\0' no final
    }
}
};

#endif
