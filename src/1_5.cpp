#include <iostream> // std::cin e std::cout

void interpor_pa(float* pa, float a_1, float a_n, int k) {
	float razao = (a_n - a_1)/(k+1); // razao da pa

	for (int i = 0; i < k+2; ++i) {
		pa[i] = a_1; 				 // inserindo elementos a partir de a_1
		a_1 += razao; 				 // incremento com base na razao
	}
}

int main() {
	float a_1, a_n;
	int k;

	std::cout << "Insira o primeiro termo da P.A.: ";
	std::cin >> a_1;
	std::cout << "Insira o ultimo termo da P.A.: ";
	std::cin >> a_n;
	std::cout << "Insira o valor de k: ";
	std::cin >> k;

	float* pa;
	pa = (float*) malloc(sizeof(float) * (k+2)); // alocando memoria para k+2 termos reais
	interpor_pa(pa, a_1, a_n, k);

	std::cout << "P.A. interpolada: ";
	for (int i = 0; i < k+2; ++i) {
		std::cout << pa[i] << " ";
	}

	free(pa); // liberando memoria
}
