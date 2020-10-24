#include <iostream> // std::cin e std::cout
#include <cmath> 	// std::floor
#include <string> 	// std::string
#include <sstream> 	// std::isstringstream

float chao(float num) { // arredonda para baixo, 6 casas decimais
	return std::floor(num*100000.0) / 100000.0;
}

float parse_stof(std::string str) {
	float parsed_float;
	std::string num = "";
	bool divisao = false;
	int numerador, denominador;

	for (auto c: str) {
		if (std::isdigit(c) || c == '-') {
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

void split(float* sequencia, int n, std::string input) {
	std::istringstream iss(input); 		// stream de entrada das strings
	std::string number; 				// string que representa um numero

	int i = 0;
	while (std::getline(iss, number, ' ')) { 	// number armazena um termo
		sequencia[i] = parse_stof(number); 		// parse de cada termo
		++i;
	}
}

bool checar_pg(float* sequencia, float q, int n) {
	for (int i = 2; i < n; ++i) {
		if (chao(sequencia[i]/sequencia[i-1]) != q) {
			return false;
		}
	}
	return true;
}

void categorizar_pg(float* seq, int n) {
	float q = chao(seq[1] / seq[0]);

	if (checar_pg(seq, q, n) == false) {
		std::cout << "A sequencia nao eh P.G.";
	}
	else {
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

}

int main() {
	int n;
	std::string input;

	std::cout << "Insira o tamanho da sequencia: ";
	std::cin >> n;

	std::cout << "Insira os " << n << " primeiros termos da sequencia: ";
	std::cin.ignore();
	std::getline(std::cin, input);

	float* sequencia;
	sequencia = (float*) malloc(sizeof(float) * n);
	split(sequencia, n, input);

	categorizar_pg(sequencia, n);
	free(sequencia);
}
