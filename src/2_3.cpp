#include <iostream>
#include <vector>

std::vector<int> concatenar(std::vector<int> input_A, std::vector<int> input_B) {
	std::vector<int> ba;

	ba.insert(ba.end(), input_B.begin(), input_B.end());
	ba.insert(ba.end(), input_A.begin(), input_A.end());

	return ba;
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
	ba = concatenar(input_A, input_B);

	std::cout << ba.size() << " elementos BA: ";
	for (auto i: ba) {
		std::cout << i << " ";
	}
}
