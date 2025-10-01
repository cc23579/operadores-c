#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

class String {
private:
    static const size_t MAX_LENGTH = 100; // tamanho máximo da string
    char data[MAX_LENGTH + 1];            // array de chars com \0 no final
    size_t length;                        // tamanho atual da string

public:
    // Construtor padrão
    String() : length(0) {
        data[0] = '\0';
    }

    // Lê do terminal e armazena na String
    void read() {
        std::cin.getline(data, MAX_LENGTH + 1);
        length = strlen(data);
    }

    // Retorna o tamanho da string
    size_t size() const {
        return length;
    }

    // Retorna o array de chars
    const char* c_str() const {
        return data;
    }

    // Permite acessar os caracteres por índice
    char& operator[](size_t index) {
        return data[index];
    }

    const char& operator[](size_t index) const {
        return data[index];
    }
};

#endif
