#include <iostream> // std::cin e std::cout
#include <vector> 	// std::vector
#include <cmath> 	// std::floor
#include <string> 	// std::string

float round(float num) {
	return std::floor(num*100000.0) / 100000.0;
}

std::vector<float> split_parse(std::string input) {
	std::vector<float> vec;
	std::string numero = "";
	float num1;
	float num2;
	bool divisao = false;

	for (auto c: input) {
		if (std::isdigit(c)) {
			numero += c;
		}
		else if (c == ' ' && divisao == false) {
			vec.push_back(stoi(numero));
			numero = "";
		}
		else if (c == '/') {
			divisao = true;
			num1 = stoi(numero);
			numero = "";
		}
		else if (c == ' ' && divisao == true) {
			num2 = stoi(numero);
			vec.push_back(num1*1.0/num2);
			numero = "";
			divisao = false;
		}
	}
	if (divisao == true) {
		num2 = stoi(numero);
		vec.push_back(num1*1.0/num2);
	}
	else {
		vec.push_back(stoi(numero));
	}

	return vec;
}

void categorizar_pg(std::vector<float> sequencia, int n) {
	float q = round(sequencia[1] / sequencia[0]);
	bool pg = false;

	for (int i = 2; i < n; ++i) {
		if ((round(sequencia[i] / sequencia[i-1]) == q) || (q == 0 && sequencia[i-1] == 0)) {
			pg = true;
		}
		else {
			pg = false;
			break;
		}
	}

	if (pg == true) {
		if ((q > 1 && sequencia[0] > 0) || (q > 0 && q < 1 && sequencia[0] < 0)) {
			std::cout << "A sequencia eh P.G. crescente";
		}
		else if ((q > 0 && q < 1 && sequencia[0] > 0) || (q > 1 && sequencia[0] < 0)) {
			std::cout << "A sequencia eh P.G. decrescente";
		}
		else if (q == 1 && sequencia[0] != 0) {
			std::cout << "A sequencia eh P.G. constante";
		}
		else if (q < 0) {
			std::cout << "A sequencia eh P.G. alternante";
		}
		else if (q == 0) {
			std::cout << "A sequencia eh P.G. estacionaria";
		}
	}
	else {
		std::cout << "A sequencia nao eh P.G.";
	}
}

int main() {
	int n;
	float x;
	std::vector<float> sequencia;
	std::string input;

	std::cout << "Insira o tamanho da sequencia: ";
	std::cin >> n;
	std::cout << "Insira os " << n << " primeiros termos da sequencia: ";
	std::cin.ignore();
	std::getline(std::cin, input);
	sequencia = split_parse(input);

	categorizar_pg(sequencia, n);
}
