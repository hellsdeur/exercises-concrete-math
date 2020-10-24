#include <iostream> // std::cin e std::cout

bool checar_pa(float *sequencia, float razao, int n) {
	for (int i = 2; i < n ; ++i) {
		if (sequencia[i] - sequencia[i-1] != razao) {
			return false; // caso uma das razoes seja diferente
		}
	}
	return true; // caso todas as razoes sejam iguais
}

void categorizar_pa(float *sequencia, int n) {
	float razao = sequencia[1] - sequencia[0]; // a_2 - a_1

	if (checar_pa(sequencia, razao, n) == false) {
		std::cout << "A sequencia nao eh P.A.";
	}
	else {
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
}

int main() {
	int n;
	std::cout << "Insira o tamanho da sequencia: ";
	std::cin >> n;

	float sequencia[n];
	std::cout << "Insira os " << n << " elementos: ";
	for (int i = 0; i < n; ++i) {
		std::cin >> sequencia[i];
	}

	categorizar_pa(sequencia, n);
}
