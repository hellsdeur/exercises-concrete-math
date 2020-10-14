#include <iostream> // std::cin and std::cout
#include <vector> 	// std::vector
#include <cmath> 	// pow()

std::vector<float> recorrencia_1b(float b_1, int n) {
	std::vector<float> elementos = {b_1};

	while (n > 1) {
		elementos.push_back(pow(elementos.back(), 2));
		--n;
	}

	return elementos;
}

int main() {
	int n;
	float b_1;
	std::vector<float> resposta;

	std::cout << "Insira o valor de b_1: ";
	std::cin >> b_1;
	std::cout << "Insira o valor de n: ";
	std::cin >> n;
	resposta = recorrencia_1b(b_1, n);

	std::cout << n << " primeiros termos da sequencia: ";
	for (auto i: resposta) {
		std::cout << i << " ";
	}
}
