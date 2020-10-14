#include <iostream> // std::cin e std::cout
#include <vector> 	// std::vector
#include <cmath> 	// std::pow()

std::vector<float> interpolar_pg(float a_1, float a_n, int k) {
	std::vector<float> elementos;
	float q;

	q = pow((a_n/a_1), (1.0/(k+1)));
	while (a_1 <= a_n){
		elementos.push_back(a_1);
		a_1 *= q;
	}

	return elementos;
}

int main() {
	float a_1, a_n;
	int k;
	std::vector<float> resposta;

	std::cout << "Insira o valor de a_1: ";
	std::cin >> a_1;
	std::cout << "Insira o valor de a_n: ";
	std::cin >> a_n;
	std::cout << "Insira o valor de k: ";
	std::cin >> k;
	resposta = interpolar_pg(a_1, a_n, k);

	std::cout << "P.G. interpolada: ";
	for (auto i: resposta) {
		std::cout << i << " ";
	}
}
