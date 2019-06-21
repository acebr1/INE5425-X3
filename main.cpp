
#include "HypothesisTesting.h"
#include <iostream>

int main() {
	//HypothesisTesting HypothesisTesting;
	//std::cout << HypothesisTesting::testProportion(0.3,200,0.38,250,H1Comparition::DIFFERENT) << std::endl;
	//std::cout << 1 - HypothesisTesting::fsnedecorCDF(10,20,2.348) << std::endl << HypothesisTesting::fsnedecorCDF(10,20,0.36);

	//double fcal = 0.5;
	//std::cout << 1 - HypothesisTesting::fsnedecorCDF(10, 20, fcal) << std::endl;
	//std::cout << HypothesisTesting::fsnedecorCDF(20, 10, 1/fcal) ;
	//std::cout << HypothesisTesting::fsnedecorCDF(22, 41, 1.705) ;
	//std::cout << HypothesisTesting::testVariance(0.00135, 39, 0.00020, 36, H1Comparition::DIFFERENT);
	//std::cout << HypothesisTesting::testVariance(0.00020, 36, 0.00135, 39, H1Comparition::DIFFERENT);
	// Resolução dos exercicios em
	// https://www.inf.ufsc.br/~andre.zibetti/probabilidade/teste-de-hipoteses.html

	// exercicio1 resposta aproximadamente 0.231 (OK)
	std::cout << HypothesisTesting::testAverage(28, 4.1, 15, 0.95, 26, 3.8, 10, HypothesisTesting::H1Comparition::DIFFERENT) << std::endl;

	// exercicio 2 resposta aproximadamente 0.0131 (OK)
	std::cout << HypothesisTesting::testAverage(29, 3.7, 17, 0.95, 26, 3.8, 17, HypothesisTesting::H1Comparition::GREATER_THAN) << std::endl;

	// exercicio 3 resposta aproximadamente 0.000824 (OK) vai dar diferente pq agora tem df  = 55.5 
	std::cout << HypothesisTesting::testAverage(105.5, 20.1, 34, 0.05, 90.9, 12.2, 29, HypothesisTesting::H1Comparition::DIFFERENT) << std::endl;
	return 0;
}
