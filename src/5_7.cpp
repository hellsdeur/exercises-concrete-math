#include <iostream>

int main() {
	int n;
	int soma = 0;

	std::cout << "Insira o valor de n: ";
	std::cin >> n;

	for (int i = 1; i <= n; ++i) {
		soma += i;
	}

	std::cout << "Valor do somatorio: " << soma;
}
