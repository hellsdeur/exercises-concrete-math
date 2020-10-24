#include <iostream>
#include <cmath>

int main() {
	int n;
	float soma = 0;

	std::cout << "Insira o valor de n: ";
	std::cin >> n;

	for (int i = 0; i <= n; ++i) {
		soma += pow(2, i);
	}

	std::cout << "Valor do somatorio: " << soma;
}
