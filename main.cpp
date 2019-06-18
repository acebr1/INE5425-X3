
#include "HypothesisTesting.cpp"
#include "IncompleteBeta.h"
#include <iostream>   

int main() {
	HypothesisTesting tester;
	//std::cout << tester.testProportion(0.3,200,0.90,0.38,250,H1Comparition::DIFFERENT) << std::endl;
	//std::cout << 1 - tester.fsnedecorCDF(10,20,2.348) << std::endl << tester.fsnedecorCDF(10,20,0.36);
	
	//double fcal = 0.5;
	//std::cout << 1 - tester.fsnedecorCDF(10, 20, fcal) << std::endl;
	//std::cout << tester.fsnedecorCDF(20, 10, 1/fcal) ;
	std::cout << tester.testVariance(0.00135, 39, 0.00020, 36, H1Comparition::DIFFERENT);
	std::cout << tester.testVariance(0.00020, 36, 0.00135, 39, H1Comparition::DIFFERENT);

	return 0;
}