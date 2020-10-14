#include <iostream> // std::cin e std::cout
#include <vector> 	// std::vector

void categorizar_pa(std::vector<float> sequencia, int n) {
	float razao = sequencia[1] - sequencia[0];
	bool pa = true;

	for (int i = 2; i < n; ++i) {
		if (sequencia[i] - sequencia[i-1] != razao) {
			pa = false;
			break;
		}
	}

	if (pa == true) {
		if (razao > 0) {
			std::cout << "A sequencia eh P.A. crescente";
		}
		else if (razao < 0) {
			std::cout << "A sequencia eh P.A. decrescente";
		}
		else {
 			std::cout << "A sequencia eh P.A. constante";
		}
	}
	else {
		std::cout << "A sequencia nao eh P.A.";
	}
}

int main() {
	int n;
	float x;
	std::vector<float> sequencia;

	std::cout << "Insira o tamanho da sequencia: ";
	std::cin >> n;
	std::cout << "Insira os " << n << " elementos: ";
	for (int i = 0; i < n; ++i) {
		std::cin >> x;
		sequencia.push_back(x);
	}

	categorizar_pa(sequencia, n);
}
