#include <iostream>
#include "String.h"
#include "InfixaParaPosfixa.h"
#include "Calculadora.h"

int main() {
	String expressao;
	char buffer[1024];
	Calculadora calc;

	std::cout << "------------------------------------------------------------------" << std::endl;
	std::cout << "Digite a expressao abaixo, caso deseje sair, digite 'exit' no campo" << std::endl;
	std::cout << "------------------------------------------------------------------" << std::endl;
	std::cout << std::endl; 

	while (true) {
		std::cout << "calc > ";
		std::cin.getline(buffer, 1024);
		expressao = String(buffer);

		if (expressao == "exit") {
			break;
		}

		try {

			Fila<Token> filaPosfixa = infixaParaPosfixa(expressao);


			Token resultado = calc.calcular(filaPosfixa);


			std::cout << "Resultado: ";
			if (resultado.type == NUMBER) {
				std::cout << resultado.num_val << std::endl;
			} else if (resultado.type == BOOLEAN) {
				std::cout << (resultado.bool_val ? "true" : "false") << std::endl;
			}
		} catch (const char* erro) {
			std::cerr << "Erro: " << erro << std::endl;
		}
	}

	return 0;
}