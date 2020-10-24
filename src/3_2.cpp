#include <iostream>
#include <vector>
#include <cmath>

bool primacidade(int num) {
	if (num <= 2) {
		return (num == 2) ? true : false;
	}
	for (int i = 2; i <= std::sqrt(num); ++i) {
		if (num % i == 0) return false;
	}
	return true;
}

std::vector<int> subseq_primos(std::vector<int> input) {
	std::vector<int> primos;

	for (auto i: input) if (primacidade(i)) primos.push_back(i);

	return primos;
}

int main() {
	std::vector<int> input;
	std::vector<int> primos;
	int n, x;

	std::cout << "Insira o tamanho da sequencia: ";
	std::cin >> n;
	std::cout << "Insira os " << n << " elementos da sequencia: ";
	while (n > 0) {
		std::cin >> x;
		input.push_back(x);
		--n;
	}
	primos = subseq_primos(input);

	std::cout << primos.size() << " elementos primos: ";
	for (auto i: primos) std::cout << i << " ";
}
