#include "HypothesisTesting.h"
#include <iostream>     
#include <math.h>       /* sqrt */

double HypothesisTesting::testAverage(double sampleAvg1, double sampleStdDev1, unsigned long sampleNumElements1, double confidencelevel, double sampleAvg2, double sampleStdDev2, unsigned long sampleNumElements2, H1Comparition comp)
{
	return 0;
}
//Returns the probability of rejecting H0 with true H0
double HypothesisTesting::testProportion(double sampleProp1, unsigned long sampleNumElements1, double confidencelevel, double sampleProp2, unsigned long sampleNumElements2, H1Comparition comp)
{
	double sampleProp = (sampleProp1*sampleNumElements1 + sampleProp2*sampleNumElements2)/(sampleNumElements1+sampleNumElements2);
	double zobs = (sampleProp2 - sampleProp1)/sqrt(sampleProp * (1 - sampleProp) * (1.0 / sampleNumElements1 + 1.0 / sampleNumElements2));
	if (comp == H1Comparition::DIFFERENT) {
		return 2*(normalCDF(-abs(zobs)));
	} else if (comp == H1Comparition::LESS_THAN) {
		return normalCDF(zobs);
	} else if (comp == H1Comparition::GREATER_THAN) {
		return 1-normalCDF(zobs);
	}
	return zobs;
}

double HypothesisTesting::testVariance(double sampleVar1, unsigned long sampleNumElements1, double confidencelevel, double sampleVar2, unsigned long sampleNumElements2, H1Comparition comp)
{
	unsigned long m = sampleNumElements1-1;
	unsigned long n = sampleNumElements2-1;
	double fcal = sampleVar1/sampleVar2;
	return 0;
}

//https://stackoverflow.com/questions/2328258/cumulative-normal-distribution-function-in-c-c
double HypothesisTesting::normalCDF(double value)
{
   return 0.5 * erfc(-value * M_SQRT1_2);
}

int main() {
	HypothesisTesting tester;
	std::cout << tester.testProportion(0.3,200,0.90,0.38,250,H1Comparition::DIFFERENT) << std::endl;	
	return 0;
}
