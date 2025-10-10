#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring> // Para strlen, strcpy, strcat, strcmp

class String {
private:
    char* data;      
    int current_size;    // Tamanho atual da string (número de caracteres)
    int capacity;  
    // Função auxiliar para redimensionar o array quando necessário
    void resize(int new_capacity) {
        char* new_data = new char[new_capacity];
       
        if (data != nullptr) {
            strcpy(new_data, data);
            delete[] data;
        } else {
            new_data[0] = '\0';
        }
        data = new_data;
        capacity = new_capacity;
    }

public:
    // Construtor padrão
    String() : current_size(0), capacity(16) {
        data = new char[capacity];
        data[0] = '\0';
    }

    // Construtor a partir de um C-string (const char*)
    String(const char* s) {
        current_size = strlen(s);
        capacity = current_size + 1;
        data = new char[capacity];
        strcpy(data, s);
    }

    // Construtor de cópia (Regra dos Três - 1)
    String(const String& other) {
        current_size = other.current_size;
        capacity = other.capacity;
        data = new char[capacity];
        strcpy(data, other.data);
    }

   
    String& operator=(const String& other) {
        if (this == &other) { 
            return *this;
        }
        delete[] data; 
        current_size = other.current_size;
        capacity = other.capacity;
        data = new char[capacity];
        strcpy(data, other.data);
        return *this;
    }

    // Destrutor (Regra dos Três - 3)
    ~String() {
        delete[] data;
    }


    const char* c_str() const {
        return data;
    }

   
    int length() const {
        return current_size;
    }

    
    void append(char c) {
        if (current_size + 1 >= capacity) {
            resize(capacity * 2); 
        }
        data[current_size] = c;
        current_size++;
        data[current_size] = '\0';
    }
    
    
    void clear() {
        current_size = 0;
        data[0] = '\0';
    }

    
    char& operator[](int index) {
        return data[index];
    }

    const char& operator[](int index) const {
        return data[index];
    }
    
    
    bool operator==(const char* other) const {
        return strcmp(this->data, other) == 0;
    }
};

// Sobrecarga do operador << para imprimir a String com std::cout
inline std::ostream& operator<<(std::ostream& os, const String& s) {
    os << s.c_str();
    return os;
}


#endif 