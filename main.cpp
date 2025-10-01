#include <iostream>
#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "string.h"

using namespace std;

int main() {
  
    String s;
    std::cout << "Digite algo: ";
    s.read();

    std::cout << "Primeiro caractere: " << s[0] << std::endl;

    // Percorrendo todos os caracteres
    for (size_t i = 0; i < s.length(); i++) {
        std::cout << "s[" << i << "] = " << s[i] << std::endl;
    }

    // Modificando um caractere
    s[0] = 'X';
    std::cout << "String modificada: " << s.getString() << std::endl;
    
    std::cout << "tamamho da String: " <<s.length() << std::endl;

    return 0;
    
}
