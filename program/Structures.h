#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "String.h" 

enum TokenType {
    NUMBER,
    OPERATOR,
    L_PAREN,
    R_PAREN,
    BOOLEAN,
    UNKNOWN
};

struct Token {
    TokenType type;
    String op_str;       
    double num_val = 0.0;
    bool bool_val = false;

    Token() : type(UNKNOWN) {}
};

#endif 