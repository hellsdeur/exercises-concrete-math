#include <iostream>
#include <vector>
#include <cmath>

void soma_produto_pg(std::vector<float> sequencia, int n) {
	float q = sequencia[1] / sequencia[0];
	bool pg = false;
	float soma, prod;

	for (int i = 2; i < n; ++i){
		if ((sequencia[i] / sequencia[i-1] == q) || std::isnan(sequencia[i] / sequencia[i-1])) {
			pg = true;
		}
		else {
			pg = false;
			break;
		}
	}

	if (pg == true){
		prod = pow(sequencia[0], n) * pow(q, n*(n-1)/2.0);
		soma = (sequencia[0] * pow(q, n) - sequencia[0]) / (q-1);

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

	std::cin >> n;
	for (int i = 0; i < n; ++i){
		std::cin >> x;
		sequencia.push_back(x);
	}
	soma_produto_pg(sequencia, n);
}
