#include <iostream>

int main() {
	int n;
	float soma = 0;
	float x_i, y_i;

	std::cout << "Insira o valor de n: ";
	std::cin >> n;

	for (int i = 1; i <= n; ++i) {
		std::cout << "Insira o valor de x_" << i << ": ";
		std::cin >> x_i;
		std::cout << "Insira o valor de y_" << i << ": ";
		std::cin >> y_i;
		soma += (x_i * y_i);
	}

	std::cout << "Valor do somatorio: " << soma;
}
