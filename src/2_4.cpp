#include <iostream>
#include <vector>

std::vector<int> segmentar(std::vector<int> input, int a, int b) {
	std::vector<int> segmento(b - a + 1);
	std::vector<int>::iterator inicio = input.begin() + a;
	std::vector<int>::iterator fim = input.begin() + b + 1;

	std::copy(inicio, fim, segmento.begin());

	return segmento;
}

int main() {
	std::vector<int> input;
	std::vector<int> segmento;
	int n, x, a, b;

	std::cout << "Insira o tamanho da sequencia: ";
	std::cin >> n;
	std::cout << "Insira os " << n << " elementos da sequencia: ";
	while (n > 0) {
		std::cin >> x;
		input.push_back(x);
		--n;
	}
	std::cout << "Insira o indice para o extremo inferior a: ";
	std::cin >> a;
	std::cout << "Insira o indice para o extremo superior b: ";
	std::cin >> b;
	segmento = segmentar(input, a, b);

	std::cout << "Segmento entre x["  << a << "] e x[" << b << "]: ";
	for (auto i: segmento) {
		std::cout << i << " ";
	}
}
