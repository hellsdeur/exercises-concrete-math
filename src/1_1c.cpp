#include <iostream> //std::cin e std::cout
#include <vector> 	//std::vector

std::vector<float> recorrencia_1c(float c_1, int n) {
	std::vector<float> elementos = {c_1};

	for (int i = 2; i <= n; ++i) {
		elementos.push_back(2 * elementos.back() + i);
	}

	return elementos;
}

int main() {
	float c_1;
	int n;
	std::vector<float> resposta;

	std::cout << "Insira o valor de c_1: ";
	std::cin >> c_1;
	std::cout << "Insira o valor de n: ";
	std::cin >> n;
	resposta = recorrencia_1c(c_1, n);

	std::cout << n << " primeiros termos da sequencia: ";
	for (auto i: resposta) {
		std::cout << i << " ";
	}
}
