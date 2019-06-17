#ifndef HYPOTHESISTESTING_H
#define HYPOTHESISTESTING_H

#include <math.h>   
#include "IncompleteBeta.cpp"

enum H1Comparition {
DIFFERENT = 1,
LESS_THAN = 2,
GREATER_THAN = 3
};

class HypothesisTesting {
public:
	HypothesisTesting() {}
	double testAverage(double sampleAvg1, double sampleStdDev1, unsigned long sampleNumElements1, double confidencelevel, double sampleAvg2, double sampleStdDev2, unsigned long sampleNumElements2, H1Comparition comp);
	double testProportion(double sampleProp1, unsigned long sampleNumElements1, double confidencelevel, double sampleProp3, unsigned long sampleNumElements2, H1Comparition comp);
	double testVariance(double sampleVar1, unsigned long sampleNumElements1, double confidencelevel, double sampleVar2, unsigned long sampleNumElements2, H1Comparition comp);
public:
	double normalCDF(double value);
	double studenttCDF(double t, double v);
};

#endif