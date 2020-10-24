#include <iostream>
#include <vector>

std::vector<int> concatenar(std::vector<int> vec1, std::vector<int> vec2) {
	std::vector<int> concatenacao;

	concatenacao.insert(concatenacao.end(), vec1.begin(), vec1.end());
	concatenacao.insert(concatenacao.end(), vec2.begin(), vec2.end());

	return concatenacao;
}

int main() {
	std::vector<int> input_A;
	std::vector<int> input_B;
	std::vector<int> ba;
	int n, x;

	std::cout << "Insira o tamanho da sequencia A: ";
	std::cin >> n;
	std::cout << "Insira os " << n << " elementos da sequencia A: ";
	while (n > 0) {
		std::cin >> x;
		input_A.push_back(x);
		--n;
	}
	std::cout << "Insira o tamanho da sequencia B: ";
	std::cin >> n;
	std::cout << "Insira os " << n << " elementos da sequencia B: ";
	while (n > 0) {
		std::cin >> x;
		input_B.push_back(x);
		--n;
	}
	ba = concatenar(input_B, input_A);

	std::cout << ba.size() << " elementos BA: ";
	for (auto i: ba) std::cout << i << " ";
}
