#include "InfixaParaPosfixa.h"
#include "Pilha.h"
#include <cctype> 
#include <cstdlib>


int getPrecedencia(const Token& t) {
    if (t.type != OPERATOR) return 0;
    
    const String& op = t.op_str;

    if (op == "!") return 5;
    if (op == "^") return 4;
    if (op == "*" || op == "/") return 3;
    if (op == "+" || op == "-") return 2;
    if (op == ">" || op == "<" || op == ">=" || op == "<=") return 1;
    if (op == "==" || op == "!=") return 1;
    if (op == "&&") return 0;
    if (op == "||") return 0;
    
    return -1;
}


bool ehAssociativoDireita(const Token& t) {
    if (t.type != OPERATOR) return false;
    return t.op_str == "^" || t.op_str == "!";
}


Token criarTokenOperador(char c) {
    Token t;
    t.type = OPERATOR;
    char str[2] = {c, '\0'};
    t.op_str = String(str);
    return t;
}

Fila<Token> infixaParaPosfixa(const String& expressao) {
    Fila<Token> filaSaida;
    Pilha<Token> pilhaOps;

    for (int i = 0; i < expressao.length(); ++i) {
        char c = expressao[i];

        if (isspace(c)) {
            continue;
        }
        
        if (isdigit(c) || c == '.') {
            String numStr;
            while (i < expressao.length() && (isdigit(expressao[i]) || expressao[i] == '.')) {
                numStr.append(expressao[i]);
                i++;
            }
            i--;

            Token t;
            t.type = NUMBER;
            t.num_val = atof(numStr.c_str()); // atof converte const char* para double
            filaSaida.Enfileirar(t);
        }
        else if (c == '(') { //abre
            Token t; t.type = L_PAREN; t.op_str = "(";
            pilhaOps.Empilhar(t);
        }
        else if (c == ')') { //fecha
             while (!pilhaOps.Vazia() && !(pilhaOps.Topo().op_str == "(")) {
                filaSaida.Enfileirar(pilhaOps.Desempilhar());
            }
            if(!pilhaOps.Vazia()) pilhaOps.Desempilhar(); // Descarta o '('
        }
        else { // É um operador
            Token t_atual;
            t_atual.type = OPERATOR;

            // Trata operadores de 2 caracteres
            char c2 = (i + 1 < expressao.length()) ? expressao[i+1] : '\0';
            if ((c == '>' || c == '<' || c == '=' || c == '!') && c2 == '=') {
                char op_temp[3] = {c, c2, '\0'};
                t_atual.op_str = String(op_temp);
                i++;
            } else if ((c == '&' && c2 == '&') || (c == '|' && c2 == '|')) {
                char op_temp[3] = {c, c2, '\0'};
                t_atual.op_str = String(op_temp);
                i++;
            } else {
                char op_temp[2] = {c, '\0'};
                t_atual.op_str = String(op_temp);
            }
            
            while (!pilhaOps.Vazia() && pilhaOps.Topo().type == OPERATOR) {
                int prec1 = getPrecedencia(t_atual);
                int prec2 = getPrecedencia(pilhaOps.Topo());
                if (prec2 > prec1 || (prec2 == prec1 && !ehAssociativoDireita(t_atual))) {
                    filaSaida.Enfileirar(pilhaOps.Desempilhar());
                } else {
                    break;
                }
            }
            pilhaOps.Empilhar(t_atual);
        }
    }

    while (!pilhaOps.Vazia()) {
        filaSaida.Enfileirar(pilhaOps.Desempilhar());
    }

    return filaSaida;
}