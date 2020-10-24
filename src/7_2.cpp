#include <iostream>

void preencher_matriz(int matriz[12][12]) {
	std::cout << "Insira os " << 12*12 << "elementos da matriz: ";
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 12; ++j) {
			std::cin >> matriz[i][j];
		}
	}
}

int soma_acima_diagonal_secundaria(int matriz[12][12]) {
	int soma = 0;

	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 12; ++j) {
			if (i+j < 11) {
				soma += matriz[i][j];
			}
		}
	}

	return soma;
}

int main() {
	int matriz[12][12];

	preencher_matriz(matriz);

	std::cout << "\nSoma acima da diagonal secundaria: " << soma_acima_diagonal_secundaria(matriz);
}
