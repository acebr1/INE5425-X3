#include "HypothesisTesting.h"
#include <iostream>

int main() {
	// Exemplo 1: resposta aproximadamente 0.231 (OK)
	std::cout << "Teste de Igualdade entre duas Médias:" << std::endl;
	std::cout << HypothesisTesting::testAverage(
					28, 4.1, 15, 0.95, 26, 3.8, 10,
					HypothesisTesting::H1Comparition::DIFFERENT)
			  << std::endl;

	// Exemplo 2: resposta aproximadamente 0.0016 (OK)
	std::cout << "Teste de Igualdade entre duas Proporções:" << std::endl;
	std::cout << HypothesisTesting::testProportion(
					0.753, 69, 0.916, 131,
					HypothesisTesting::DIFFERENT)
			  << std::endl;

	// Exemplo 3: resposta aproximadamente 0.891 (OK)
	std::cout << "Teste de Igualdade entre duas Variâncias:" << std::endl;
	std::cout << HypothesisTesting::testVariance(
					0.683, 10, 0.750, 10,
					HypothesisTesting::DIFFERENT)
			  << std::endl;
	return 0;
}
