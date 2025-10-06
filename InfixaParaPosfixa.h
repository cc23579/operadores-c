#ifndef INFIXA_PARA_POSFIXA_H
#define INFIXA_PARA_POSFIXA_H

#include <string>
#include "Pilha.h"

int precedencia(char op);
bool ehOperador(char c);
std::string infixaParaPosfixa(const std::string& infixa);

#endif
