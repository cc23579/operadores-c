#ifndef CALCULADORA_H
#define CALCULADORA_H

#include "Structures.h"
#include "Fila.h"

class Calculadora {
public:
    Token calcular(Fila<Token>& expressaoPosFixa);
};

#endif 