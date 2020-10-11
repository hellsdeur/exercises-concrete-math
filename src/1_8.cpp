#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> interpolacao(int a_1, int a_n, int k) {
	std::vector<int> elementos;
	int q;

	q = pow((a_n/a_1), (1.0/(k+1)));
	while (a_1 <= a_n){
		elementos.push_back(a_1);
		a_1 *= q;
	}

	return elementos;
}

int main() {
	int a_1, a_n, k;
	std::vector<int> resposta;

	std::cin >> a_1 >> a_n >> k;
	resposta = interpolacao(a_1, a_n, k);
	for (auto i : resposta) {
		std::cout << i << " ";
	}
}
