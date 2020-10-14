#include <iostream>
#include <vector>

std::vector<int> subseq_impar(std::vector<int> input) {
	std::vector<int> impares;

	for (auto i: input) {
		if (i % 2 != 0) {
			impares.push_back(i);
		}
	}

	return impares;
}

int main() {
	std::vector<int> input;
	std::vector<int> impares;
	int n, x;

	std::cout << "Insira o tamanho da sequencia: ";
	std::cin >> n;
	std::cout << "Insira os " << n << " elementos da sequencia: ";
	while (n > 0) {
		std::cin >> x;
		input.push_back(x);
		--n;
	}
	impares = subseq_impar(input);

	std::cout << impares.size() << " elementos impares: ";
	for (auto i: impares) {
		std::cout << i << " ";
	}
}
