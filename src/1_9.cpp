#include <iostream> // std::cin e std::cout
#include <vector> 	// std::vector
#include <cmath> 	// std::pow()

float chao(float num) {
	return std::floor(num*100000.0) / 100000.0;
}

bool checar_pg(float* sequencia, float q, int n) {
	for (int i = 2; i < n; ++i) {
		if (chao(sequencia[i]/sequencia[i-1]) != q) {
			return false;
		}
	}
	return true;
}

void soma_produto_pg(float* seq, int n) {
	float q = round(seq[1] / seq[0]);
	float soma, prod;

	if (checar_pg(seq, q, n) == false) {
		std::cout << "A sequencia nao eh uma P.G.";
	}
	else {
		soma = (seq[0] * pow(q, n) - seq[0]) / (q-1);
		prod = pow(seq[0], n) * pow(q, n*(n-1)/2.0);

		std::cout << "A sequencia eh uma P.G.\n";
		std::cout << "Sua soma eh: " << soma << "\n";
		std::cout << "Seu produto eh: " << prod << "\n";
	}
}

int main() {
	int n;

	std::cout << "Insira o tamanho da sequencia: ";
	std::cin >> n;

	float* sequencia;
	sequencia = (float*) malloc(sizeof(float) * n);

	std::cout << "Insira os " << n << " elementos da sequencia: ";
	for (int i = 0; i < n; ++i){
		std::cin >> sequencia[i];
	}

	soma_produto_pg(sequencia, n);
	free(sequencia)
}
