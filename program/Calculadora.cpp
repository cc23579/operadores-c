#include "Calculadora.h"
#include "Pilha.h"
#include <cmath>

Token Calculadora::calcular(Fila<Token>& expressaoPosFixa) {
    Pilha<Token> pilhaResultados;

    while (!expressaoPosFixa.Vazia()) {
        Token t = expressaoPosFixa.Desenfileirar();

        // Se for um número ou booleano empilha
        if (t.type == NUMBER || t.type == BOOLEAN) {
            pilhaResultados.Empilhar(t);
        } 
        // Se for um operador realiza o cálculo
        else if (t.type == OPERATOR) {
            Token res;

            //  operadores com DOIS operandos
            if (t.op_str == "+" || t.op_str == "-" || t.op_str == "*" || t.op_str == "/" || t.op_str == "^" ||
                t.op_str == ">" || t.op_str == "<" || t.op_str == ">=" || t.op_str == "<=" || t.op_str == "==" || t.op_str == "!=" ||
                t.op_str == "&&" || t.op_str == "||")
            {
                // Pega os dois operandos do topo da pilha
                if (pilhaResultados.Vazia()) throw "Erro de sintaxe: Faltam operandos.";
                Token operando2 = pilhaResultados.Desempilhar();
                if (pilhaResultados.Vazia()) throw "Erro de sintaxe: Faltam operandos.";
                Token operando1 = pilhaResultados.Desempilhar();

                //  Operações Aritméticas 
                if (t.op_str == "+") {
                    if (operando1.type != NUMBER || operando2.type != NUMBER) throw "Operador '+' exige dois números.";
                    res.type = NUMBER;
                    res.num_val = operando1.num_val + operando2.num_val;
                }
                else if (t.op_str == "-") {
                    if (operando1.type != NUMBER || operando2.type != NUMBER) throw "Operador '-' exige dois números.";
                    res.type = NUMBER;
                    res.num_val = operando1.num_val - operando2.num_val;
                }
                else if (t.op_str == "*") {
                    if (operando1.type != NUMBER || operando2.type != NUMBER) throw "Operador '*' exige dois números.";
                    res.type = NUMBER;
                    res.num_val = operando1.num_val * operando2.num_val;
                }
                else if (t.op_str == "/") {
                    if (operando1.type != NUMBER || operando2.type != NUMBER) throw "Operador '/' exige dois números.";
                    if (operando2.num_val == 0) throw "Divisão por zero.";
                    res.type = NUMBER;
                    res.num_val = operando1.num_val / operando2.num_val;
                }
                else if (t.op_str == "^") {
                    if (operando1.type != NUMBER || operando2.type != NUMBER) throw "Operador '^' exige dois números.";
                    res.type = NUMBER;
                    res.num_val = pow(operando1.num_val, operando2.num_val);
                }

                //  Operações booleanas
                else if (t.op_str == ">") {
                    if (operando1.type != NUMBER || operando2.type != NUMBER) throw "Operador '>' exige dois números.";
                    res.type = BOOLEAN;
                    res.bool_val = operando1.num_val > operando2.num_val;
                }
                else if (t.op_str == "<") {
                    if (operando1.type != NUMBER || operando2.type != NUMBER) throw "Operador '<' exige dois números.";
                    res.type = BOOLEAN;
                    res.bool_val = operando1.num_val < operando2.num_val;
                }
                else if (t.op_str == ">=") {
                    if (operando1.type != NUMBER || operando2.type != NUMBER) throw "Operador '>=' exige dois números.";
                    res.type = BOOLEAN;
                    res.bool_val = operando1.num_val >= operando2.num_val;
                }
                else if (t.op_str == "<=") {
                    if (operando1.type != NUMBER || operando2.type != NUMBER) throw "Operador '<=' exige dois números.";
                    res.type = BOOLEAN;
                    res.bool_val = operando1.num_val <= operando2.num_val;
                }
                else if (t.op_str == "==") {
                    if (operando1.type != operando2.type) throw "Comparação '==' entre tipos diferentes (número e booleano).";
                    res.type = BOOLEAN;
                    if (operando1.type == NUMBER) res.bool_val = (operando1.num_val == operando2.num_val);
                    else res.bool_val = (operando1.bool_val == operando2.bool_val);
                }
                else if (t.op_str == "!=") {
                    if (operando1.type != operando2.type) throw "Comparação '!=' entre tipos diferentes (número e booleano).";
                    res.type = BOOLEAN;
                    if (operando1.type == NUMBER) res.bool_val = (operando1.num_val != operando2.num_val);
                    else res.bool_val = (operando1.bool_val != operando2.bool_val);
                }

                //  Operações Lógicas 
                else if (t.op_str == "&&") {
                    if (operando1.type != BOOLEAN || operando2.type != BOOLEAN) throw "Operador '&&' exige dois booleanos.";
                    res.type = BOOLEAN;
                    res.bool_val = operando1.bool_val && operando2.bool_val;
                }
                else if (t.op_str == "||") {
                    if (operando1.type != BOOLEAN || operando2.type != BOOLEAN) throw "Operador '||' exige dois booleanos.";
                    res.type = BOOLEAN;
                    res.bool_val = operando1.bool_val || operando2.bool_val;
                }
            }
            //  Lógica para operadores com UM operando 
            else if (t.op_str == "!") {
                 if (pilhaResultados.Vazia()) throw "Erro de sintaxe: Falta operando para '!'.";
                 Token operando = pilhaResultados.Desempilhar();
                 if (operando.type != BOOLEAN) throw "Operador '!' exige um booleano.";
                 res.type = BOOLEAN;
                 res.bool_val = !operando.bool_val;
            }
            else {
                throw "Operador desconhecido encontrado durante o cálculo.";
            }
             
           
            pilhaResultados.Empilhar(res);
        }
    }

    if (pilhaResultados.Vazia()) throw "Erro: Expressão inválida ou vazia.";
    Token resultadoFinal = pilhaResultados.Desempilhar();
    if (!pilhaResultados.Vazia()) throw "Erro: Expressão mal formada (operandos sobrando).";

    return resultadoFinal;
}