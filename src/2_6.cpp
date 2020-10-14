#include <iostream>
#include <vector>

std::vector<int> sufixar(std::vector<int> input, int k) {
	std::vector<int> sufixo(k);
	std::vector<int>::iterator inicio = input.begin() + input.size() - k;
	std::vector<int>::iterator fim = input.end();

	std::copy(inicio, fim, sufixo.begin());

	return sufixo;
}

int main() {
	std::vector<int> input;
	std::vector<int> sufixo;
	int n, x, k;

	std::cout << "Insira o tamanho da sequencia: ";
	std::cin >> n;
	std::cout << "Insira os " << n << " elementos da sequencia: ";
	while (n > 0) {
		std::cin >> x;
		input.push_back(x);
		--n;
	}
	std::cout << "Insira o valor de k elementos do sufixo: ";
	std::cin >> k;
	sufixo = sufixar(input, k);

	std::cout << "Sufixo de comprimento " << k << ": ";
	for (auto i: sufixo) {
		std::cout << i << " ";
	}
}
