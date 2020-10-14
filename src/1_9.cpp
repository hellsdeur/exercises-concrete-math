#include <iostream> // std::cin e std::cout
#include <vector> 	// std::vector
#include <cmath> 	// std::pow()

float round(float num) {
	return std::floor(num*100000.0) / 100000.0;
}

void soma_produto_pg(std::vector<float> seq, int n) {
	float q = round(seq[1] / seq[0]);
	bool pg = false;
	float soma, prod;

	for (int i = 2; i < n; ++i) {
		if (round(seq[i] / seq[i-1]) == q || q == 0 && seq[i-1] == 0) {
			pg = true;
		}
		else {
			pg = false;
			break;
		}
	}

	if (pg == true){
		soma = (seq[0] * pow(q, n) - seq[0]) / (q-1);
		prod = pow(seq[0], n) * pow(q, n*(n-1)/2.0);

		std::cout << "A sequencia eh uma P.G.\n";
		std::cout << "Sua soma eh: " << soma << "\n";
		std::cout << "Seu produto eh: " << prod << "\n";
	}
	else std::cout << "A sequencia nao eh uma P.G.";
}

int main() {
	int n;
	float x;
	std::vector<float> sequencia;

	std::cout << "Insira o tamanho da sequencia: ";
	std::cin >> n;
	std::cout << "Insira os " << n << " elementos da sequencia: ";
	for (int i = 0; i < n; ++i){
		std::cin >> x;
		sequencia.push_back(x);
	}
	soma_produto_pg(sequencia, n);
}
