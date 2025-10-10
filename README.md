# Calculadora de Expressões em C++

Este é um projeto de uma Calculadora de Expressões em C++, capaz de avaliar expressões matemáticas e lógicas. A implementação foi feita do zero, sem o uso de bibliotecas de coleções da STL.

## O Algoritmo

O programa funciona em três etapas principais para calcular o resultado de uma expressão:

**1. Tokenização**
Primeiro, a expressão digitada (ex: `(10 + 2) * 5`) é lida e quebrada em pedaços menores chamados "tokens". Cada token representa uma parte da expressão.
- A expressão `(10 + 2) * 5` se transforma na sequência de tokens: `(`, `10`, `+`, `2`, `)`, `*`, `5`.

**2. Conversão para Pós-fixa (Algoritmo Shunting-Yard)**
Em seguida, os tokens são reorganizados da ordem "infixa" (o formato que escrevemos) para a ordem "pós-fixa" (ou RPN - Notação Polonesa Reversa). A ordem pós-fixa elimina a necessidade de parênteses e torna o cálculo muito mais simples para o computador.
- A sequência `(`, `10`, `+`, `2`, `)`, `*`, `5` se torna `10`, `2`, `+`, `5`, `*`.

**3. Cálculo da Expressão Pós-fixa**
Finalmente, a expressão pós-fixa é calculada usando uma Pilha. Lemos os tokens da esquerda para a direita:
- Se for um **número**, ele é empilhado.
- Se for um **operador**, desempilhamos os números necessários, realizamos a conta e empilhamos o resultado de volta.

Exemplo com `10 2 + 5 *`:
1.  Empilha `10`. Pilha: `[10]`
2.  Empilha `2`. Pilha: `[10, 2]`
3.  Encontra `+`. Desempilha `2` e `10`, calcula `10 + 2 = 12`. Empilha `12`. Pilha: `[12]`
4.  Empilha `5`. Pilha: `[12, 5]`
5.  Encontra `*`. Desempilha `5` e `12`, calcula `12 * 5 = 60`. Empilha `60`. Pilha: `[60]`

No final, o único valor na pilha é o resultado final: **60**.

## Estrutura dos Arquivos

Cada arquivo do projeto tem uma responsabilidade bem definida:

-   **`main.cpp`**
    Programa principal. Lê a entrada do usuário, chama os outros módulos e imprime o resultado.

-   **`string.h`**
    Nossa própria classe `String` para manipular texto sem usar a `std::string` da biblioteca padrão.

-   **`structures.h`**
    Define a `struct Token`, que é a estrutura que representa cada pedaço da expressão (um número, um operador, etc.).

-   **`lista.h`, `pilha.h`, `fila.h`**
    Implementações manuais das estruturas de dados básicas (Lista, Pilha e Fila) que são usadas pelo algoritmo.

-   **`InfixaParaPosfixa.h` / `.cpp`**
    Responsável pela **Etapa 2 (Conversão)**. Implementa o algoritmo Shunting-Yard para transformar a expressão do usuário para o formato pós-fixo.

-   **`calculadora.h` / `.cpp`**
    Responsável pela **Etapa 3 (Cálculo)**. Pega a expressão já em formato pós-fixo e calcula o resultado final.