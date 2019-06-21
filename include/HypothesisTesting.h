#ifndef HYPOTHESISTESTING_H
#define HYPOTHESISTESTING_H

namespace HypothesisTesting {

enum H1Comparition { DIFFERENT = 1, LESS_THAN = 2, GREATER_THAN = 3 };

double testAverage(
	double sampleAvg1, double sampleStdDev1, unsigned long sampleNumElements1,
	double confidencelevel, double sampleAvg2, double sampleStdDev2,
	unsigned long sampleNumElements2, H1Comparition comp);
double testProportion(
	double sampleProp1, unsigned long sampleNumElements1, double sampleProp3,
	unsigned long sampleNumElements2, H1Comparition comp);
double testVariance(
	double sampleVar1, unsigned long sampleNumElements1, double sampleVar2,
	unsigned long sampleNumElements2, H1Comparition comp);

/* Cumulative distribution functions */
double studenttCDF(double t, double v);
double fsnedecorCDF(unsigned long n, unsigned long m, double x);

double pValueStudentT(double tobs, double df, H1Comparition comp);

}  // namespace HypothesisTesting

#endif
