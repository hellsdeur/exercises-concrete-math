#include <iostream> // std::cin e std::cout
#include <vector> 	// std::vector
#include <cmath> 	// std::floor
#include <string> 	// std::string
#include <sstream> 	// std::isstringstream

float round(float num) {
	return std::floor(num*100000.0) / 100000.0;
}

float parse_stof(std::string str) {
	float parsed_float;
	std::string num = "";
	bool divisao = false;
	int numerador, denominador;

	for (auto c: str) {
		if (std::isdigit(c)) {
			num += c;
		}
		else if (c == '/') {
			numerador = stoi(num);
			num = "";
			divisao = true;
		}
		if (c == str.back() && divisao == true) {
			denominador = stoi(num);
			parsed_float = 1.0*numerador/denominador;
		}
		else if (c == str.back() && divisao == false) {
			parsed_float = stoi(num);
		}
	}

	return parsed_float;
}

std::vector<float> split_and_parse(std::string input) {
	std::vector<float> sequencia;
	std::vector<std::string> splitted_strings;
	std::istringstream iss(input);
	std::string number;

	while (std::getline(iss, number, ' ')) {
		splitted_strings.push_back(number);
	}
	for (auto str: splitted_strings) {
		sequencia.push_back(parse_stof(str));
	}

	return sequencia;
}

void categorizar_pg(std::vector<float> seq, int n) {
	float q = round(seq[1] / seq[0]);
	bool pg = false;

	for (int i = 2; i < n; ++i) {
		if (round(seq[i] / seq[i-1]) == q || q == 0 && seq[i-1] == 0) {
			pg = true;
		}
		else {
			pg = false;
			break;
		}
	}

	if (pg == true) {
		if ((q > 1 && seq[0] > 0) || (q > 0 && q < 1 && seq[0] < 0)) {
			std::cout << "A sequencia eh P.G. crescente";
		}
		else if ((q > 0 && q < 1 && seq[0] > 0) || (q > 1 && seq[0] < 0)) {
			std::cout << "A sequencia eh P.G. decrescente";
		}
		else if (q == 1 && seq[0] != 0) {
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
	sequencia = split_and_parse(input);

	categorizar_pg(sequencia, n);
}
