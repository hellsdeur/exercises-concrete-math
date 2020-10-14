#include <iostream> // std::cin e std::cout
#include <vector> 	// std::vector

std::vector<float> recorrencia_1a(float a_1, int n) {
	std::vector<float> elementos = {a_1};

	while (n > 1) {
		elementos.push_back(elementos.back() + 3);
		--n;
	}

	return elementos;
}

int main() {
	int a_1, n;
	std::vector<float> resposta;

	std::cout << "Insira o valor de a_1: ";
	std::cin >> a_1;
	std::cout << "Insira o valor de n: ";
	std::cin >> n;
	resposta = recorrencia_1a(a_1, n);

	std::cout << n << " primeiros termos da sequencia: ";
	for (auto i: resposta) {
		std::cout << i << " ";
	}
}
