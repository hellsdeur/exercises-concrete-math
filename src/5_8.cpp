#include <iostream>

int main() {
	int n;
	float soma = 0;
	float b_i;

	std::cout << "Insira o valor de n: ";
	std::cin >> n;

	for (int i = 1; i <= n; ++i) {
		std::cout << "Insira o valor de x_" << i << ": ";
		std::cin >> b_i;
		soma += (b_i * b_i);
	}

	std::cout << "Valor do somatorio: " << soma;
}
