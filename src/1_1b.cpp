#include <iostream> // std::cin e std::cout
#include <cmath> 	// pow()

#define a_1 2 	// primeiro termo da sequencia
#define n 	6 	// tamanho da sequencia

int main() {
	float sequencia[n]; 						// declarando arrays de n elementos

	sequencia[0] = a_1; 						// inserindo o primeiro termo
	for (int i = 1; i < n; ++i) { 				// inserindo os demais termos
		sequencia[i] = pow(sequencia[i-1], 2); 	// funcao de recorrencia
	}

	std::cout << n << " primeiros termos da sequencia: ";
	for (int i = 0; i < n; ++i) {
		std::cout << sequencia[i] << " ";
	}
}
