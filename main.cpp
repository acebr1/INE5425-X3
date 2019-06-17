
#include "HypothesisTesting.cpp"
#include <iostream>   

int main() {
	HypothesisTesting tester;
	std::cout << tester.testProportion(0.3,200,0.90,0.38,250,H1Comparition::DIFFERENT) << std::endl;
	std::cout << tester.studenttCDF(1,2);
	return 0;
}