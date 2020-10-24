#include <iostream> // std::cin e std::cout
#include <cmath> 	// std::pow()

void interpor_pg(float* pg, float a_1, float a_n, int k) {
	float q = pow((a_n/a_1), (1.0/(k+1)));  //razao da pg

	for (int i = 0; i < k+2; ++i) {
		pg[i] = a_1; 						// inserindo elementos a partir de a_1
		a_1 *= q; 							// incremento com base em q
	}
}

int main() {
	float a_1, a_n;
	int k;

	std::cout << "Insira o primeiro termo da P.G.: ";
	std::cin >> a_1;
	std::cout << "Insira o ultimo termo da P.G.: ";
	std::cin >> a_n;
	std::cout << "Insira o valor de k: ";
	std::cin >> k;

	float* pg;
	pg = (float*) malloc(sizeof(float) * (k+2)); // alocando memoria para k+2 termos
	interpor_pg(pg, a_1, a_n, k);

	std::cout << "P.G. interpolada: ";
	for (int i = 0; i < k+2; ++i) {
		std::cout << pg[i] << " ";
	}

	free(pg); // liberando memoria
}
