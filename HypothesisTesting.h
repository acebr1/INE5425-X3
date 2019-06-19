#ifndef HYPOTHESISTESTING_H
#define HYPOTHESISTESTING_H

#include <math.h>
#include "IncompleteBeta.h"

enum H1Comparition {
DIFFERENT = 1,
LESS_THAN = 2,
GREATER_THAN = 3
};

class HypothesisTesting {
public:
	HypothesisTesting() {}
	static double testAverage(double sampleAvg1, double sampleStdDev1, unsigned long sampleNumElements1, double confidencelevel, double sampleAvg2, double sampleStdDev2, unsigned long sampleNumElements2, H1Comparition comp);
	static double testProportion(double sampleProp1, unsigned long sampleNumElements1, double sampleProp3, unsigned long sampleNumElements2, H1Comparition comp);
	static double testVariance(double sampleVar1, unsigned long sampleNumElements1, double sampleVar2, unsigned long sampleNumElements2, H1Comparition comp);
public:
	static double studenttCDF(double t, double v);
	static double fsnedecorCDF(unsigned long n, unsigned long m, double x);
};

#endif
