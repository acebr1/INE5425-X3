#include "HypothesisTesting.h"
#include "IncompleteBeta.h"
#include <math.h>

namespace HypothesisTesting {

double testAverage(
	double sampleAvg1, double sampleStdDev1, unsigned long sampleNumElements1,
	double confidencelevel, double sampleAvg2, double sampleStdDev2,
	unsigned long sampleNumElements2, H1Comparition comp) {
	double var1 = sampleStdDev1 * sampleStdDev1;
	double var2 = sampleStdDev2 * sampleStdDev2;
	double df1 = sampleNumElements1 - 1;
	double df2 = sampleNumElements2 - 1;
	double alfa = 1 - confidencelevel;
	double tobs, df;

	double pvalueVar = testVariance(
		var1, sampleNumElements1, var2, sampleNumElements2,
		H1Comparition::DIFFERENT);
	if (pvalueVar < alfa) {
		double se2 = var1 / sampleNumElements1 + var2 / sampleNumElements2;
		double aux1 =
			((var1 / sampleNumElements1) * (var1 / sampleNumElements1)) / df1;
		double aux2 =
			((var2 / sampleNumElements2) * (var2 / sampleNumElements2)) / df2;
		df = (se2 * se2) / (aux1 + aux2);
		tobs = (sampleAvg1 - sampleAvg2) / sqrt(se2);
	} else {
		df = df1 + df2;
		double sp = sqrt(
			((sampleNumElements1 - 1) * var1 +
			 (sampleNumElements2 - 1) * var2) /
			df);
		double se =
			sp * sqrt(1.0 / sampleNumElements1 + 1.0 / sampleNumElements2);
		tobs = (sampleAvg1 - sampleAvg2) / se;
	}

	return pValueStudentT(tobs, df, comp);
}

double testProportion(
	double sampleProp1, unsigned long sampleNumElements1, double sampleProp2,
	unsigned long sampleNumElements2, H1Comparition comp) {
	double sampleProp =
		(sampleProp1 * sampleNumElements1 + sampleProp2 * sampleNumElements2) /
		(sampleNumElements1 + sampleNumElements2);
	double tobs = (sampleProp2 - sampleProp1) /
				  sqrt(
					  sampleProp * (1 - sampleProp) *
					  (1.0 / sampleNumElements1 + 1.0 / sampleNumElements2));
	double df = sampleNumElements1 + sampleNumElements2 - 2;
	return pValueStudentT(tobs, df, comp);
}

double testVariance(
	double sampleVar1, unsigned long sampleNumElements1, double sampleVar2,
	unsigned long sampleNumElements2, H1Comparition comp) {
	unsigned long n = sampleNumElements1 - 1;
	unsigned long m = sampleNumElements2 - 1;
	double fcal = sampleVar1 / sampleVar2;
	if (comp == H1Comparition::DIFFERENT) {
		double leftTail = fsnedecorCDF(n, m, fcal);
		double rightTail = 1 - leftTail;
		return (rightTail < leftTail) ? 2 * rightTail : 2 * leftTail;
	} else if (comp == H1Comparition::LESS_THAN) {
		double leftTail = fsnedecorCDF(n, m, fcal);
		return leftTail;
	} else if (comp == H1Comparition::GREATER_THAN) {
		double rightTail = 1 - fsnedecorCDF(n, m, fcal);
		return rightTail;
	}
	return fcal;
}

// https://github.com/codeplea/incbeta
// https://codeplea.com/incomplete-beta-function-c
double studenttCDF(double t, double v) {
	double x = (t + sqrt(t * t + v)) / (2.0 * sqrt(t * t + v));
	return IncompleteBeta::incbeta(v / 2.0, v / 2.0, x);
}

double pValueStudentT(double tobs, double df, H1Comparition comp) {
	if (comp == H1Comparition::DIFFERENT) {
		return 2 * (studenttCDF(-abs(tobs), df));
	} else if (comp == H1Comparition::LESS_THAN) {
		return studenttCDF(tobs, df);
	} else if (comp == H1Comparition::GREATER_THAN) {
		return 1 - studenttCDF(tobs, df);
	}
	return 1;
}

// http://mathworld.wolfram.com/F-Distribution.html
// https://en.wikipedia.org/wiki/F-distribution
double fsnedecorCDF(unsigned long n, unsigned long m, double x) {
	return IncompleteBeta::incbeta(n / 2.0, m / 2.0, (n * x) / (m + n * x));
}

}  // namespace HypothesisTesting
