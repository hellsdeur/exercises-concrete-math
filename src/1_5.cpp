#include <iostream> // std::cin e std::cout
#include <vector> 	// std::vector

std::vector<float> interpor_pa(float a_1, float a_n, int k) {
	float razao;
	std::vector<float> elementos;

	razao = (a_n - a_1)/(k+1);
	while (a_1 <= a_n) {
		elementos.push_back(a_1);
		a_1 += razao;
	}

	return elementos;
}

int main() {
	float a_1, a_n;
	int k;
	std::vector<float> resposta;

	std::cout << "Insira o primeiro termo da P.A.: ";
	std::cin >> a_1;
	std::cout << "Insira o ultimo termo da P.A.: ";
	std::cin >> a_n;
	std::cout << "Insira o valor de k: ";
	std::cin >> k;
	resposta = interpor_pa(a_1, a_n, k);

	std::cout << "P.A. interpolada: ";
	for (auto i: resposta) {
		std::cout << i << " ";
	}
}
