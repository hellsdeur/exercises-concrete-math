#include <iostream>
#include <vector>

std::vector<int> prefixar(std::vector<int> input, int k) {
	std::vector<int> prefixo(k);
	std::vector<int>::iterator inicio = input.begin();
	std::vector<int>::iterator fim = input.begin() + k;

	std::copy(inicio, fim, prefixo.begin());

	return prefixo;
}

int main() {
	std::vector<int> input;
	std::vector<int> prefixo;
	int n, x, k;

	std::cout << "Insira o tamanho da sequencia: ";
	std::cin >> n;
	std::cout << "Insira os " << n << " elementos da sequencia: ";
	while (n > 0) {
		std::cin >> x;
		input.push_back(x);
		--n;
	}
	std::cout << "Insira o valor k: ";
	std::cin >> k;
	prefixo = prefixar(input, k);

	std::cout << "Prefixo de comprimento " << k << ": ";
	for (auto i: prefixo) {
		std::cout << i << " ";
	}
}
