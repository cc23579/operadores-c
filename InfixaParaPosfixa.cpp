#include "InfixaParaPosfixa.h"
#include <iostream>
#include "String.h"
#include "Pilha.h"

int precedencia(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

bool ehOperador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool ehNumero(char c) {
    if(c >= '0' && c <= '9'){

        return true;
    }
    else if(c == 'T' || c == 'F'){

        return true;
    }
    else{
        
        return false;
    }
    
}

String infixaParaPosfixa(String infixa){
    Pilha<char> pilha;
    String posfixa;
    char c;
    for(int i = 0; i < infixa.length(); i++){
        c = infixa[i];
        if(c == ' '){ 
            continue;   
        }

        else if(ehNumero(c)){
            posfixa.append(c);
        }

        else if(c == '('){
            pilha.Empilhar('(');
        }

        else if (c == ')') {
            while (!pilha.Vazia() && pilha.Topo() != '(') {
                posfixa.append(pilha.Desempilhar());
            }
            if (!pilha.Vazia() && pilha.Topo() == '(') {
                pilha.Desempilhar(); 
            }
        }

        else {
            while (!pilha.Vazia() && precedencia(pilha.Topo()) >= precedencia(c)) {
                posfixa.append(pilha.Desempilhar());
            }
            pilha.Empilhar(c);
        }

        while (!pilha.Vazia()) {
            posfixa.append(pilha.Desempilhar());
        }

        return posfixa;
    }
}

