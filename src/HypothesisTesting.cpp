#include "HypothesisTesting.h"
#include "IncompleteBeta.h"
#include <math.h>

namespace HypothesisTesting {

/*! Function implementation of a Parametric Hypothesis Test for equality of
 * 	means in non-paired samples.
 *	Returns p-value (Probability of Type 1 Error) */
double testAverage(
	double sampleAvg1, double sampleStdDev1, unsigned long sampleNumElements1,
	double confidencelevel, double sampleAvg2, double sampleStdDev2,
	unsigned long sampleNumElements2, H1Comparition comp) {
	// Calculating variance from standard deviation
	double var1 = sampleStdDev1 * sampleStdDev1;
	double var2 = sampleStdDev2 * sampleStdDev2;
	// Calculating degrees of freedom from number of elements in sample
	double df1 = sampleNumElements1 - 1;
	double df2 = sampleNumElements2 - 1;
	// Calculating alfa from confidence level
	double alfa = 1 - confidencelevel;

	double tobs, df;

	// Call Hypothesis Test for equality of Variances for variance p-value
	double pvalueVar = testVariance(
		var1, sampleNumElements1, var2, sampleNumElements2,
		H1Comparition::DIFFERENT);

	if (pvalueVar < alfa) { // Case 1: Populational variances are unknown, but different
		double se2 = var1 / sampleNumElements1 + var2 / sampleNumElements2;
		double aux1 =
			((var1 / sampleNumElements1) * (var1 / sampleNumElements1)) / df1;
		double aux2 =
			((var2 / sampleNumElements2) * (var2 / sampleNumElements2)) / df2;
		df = (se2 * se2) / (aux1 + aux2); // Degrees of Freedom can be fractional 
		tobs = (sampleAvg1 - sampleAvg2) / sqrt(se2);
	} else { // Case 2: Populational variances are unknown, but equal
		df = df1 + df2;
		double sp = sqrt(
			((sampleNumElements1 - 1) * var1 +
			 (sampleNumElements2 - 1) * var2) /
			df);
		double se =
			sp * sqrt(1.0 / sampleNumElements1 + 1.0 / sampleNumElements2);
		tobs = (sampleAvg1 - sampleAvg2) / se;
	}

	// Get p-value and return
	return pValueStudentT(tobs, df, comp);
}

/*! Function implementation of a Parametric Hypothesis Test for difference of
 * 	proportions in non-paired samples.
 *	Returns p-value (Probability of Type 1 Error) */
double testProportion(
	double sampleProp1, unsigned long sampleNumElements1, double sampleProp2,
	unsigned long sampleNumElements2, H1Comparition comp) {
	// Calculate common proportion (x1 + x2)/(n1 + n2)
	double sampleProp =
		(sampleProp1 * sampleNumElements1 + sampleProp2 * sampleNumElements2) /
		(sampleNumElements1 + sampleNumElements2);
	// Calculate tobs (Student's t equivalent for Zobs)
	double tobs = (sampleProp2 - sampleProp1) /
				  sqrt(
					  sampleProp * (1 - sampleProp) *
					  (1.0 / sampleNumElements1 + 1.0 / sampleNumElements2));
	// Calculate degrees of freedom
	double df = sampleNumElements1 + sampleNumElements2 - 2;
	return pValueStudentT(tobs, df, comp);
}

/*! Function implementation of a Parametric Hypothesis Test for difference of
 * 	variances in non-paired samples.
 *	Returns p-value (Probability of Type 1 Error) */
double testVariance(
	double sampleVar1, unsigned long sampleNumElements1, double sampleVar2,
	unsigned long sampleNumElements2, H1Comparition comp) {
	// Calculate degrees of freedom based on number of elements in sample
	unsigned long n = sampleNumElements1 - 1;
	unsigned long m = sampleNumElements2 - 1;
	// Calculate Fcal based on variances
	double fcal = sampleVar1 / sampleVar2;
	// Calculate p-value based on Fcal and type of comparison
	if (comp == H1Comparition::DIFFERENT) { // Two-Tailed test
		double leftTail = fsnedecorCDF(n, m, fcal);
		double rightTail = 1 - leftTail;
		return (rightTail < leftTail) ? 2 * rightTail : 2 * leftTail;
	} else if (comp == H1Comparition::LESS_THAN) { // Left-Tailed test
		double leftTail = fsnedecorCDF(n, m, fcal);
		return leftTail;
	} else if (comp == H1Comparition::GREATER_THAN) { // Right-Tailed test
		double rightTail = 1 - fsnedecorCDF(n, m, fcal);
		return rightTail;
	}
	return fcal;
}

/*! Student's T Cumulative Distribution Function based on a regularized
 *	incomplete beta function.
 *	References:
 * 		https://github.com/codeplea/incbeta
 * 		https://codeplea.com/incomplete-beta-function-c
 *	Tested against Student's T distribution table generated by Microsoft Excel,
 *	obtaining acceptable error values.*/
double studenttCDF(double t, double v) {
	double x = (t + sqrt(t * t + v)) / (2.0 * sqrt(t * t + v));
	return IncompleteBeta::incbeta(v / 2.0, v / 2.0, x);
}

/*! Calculation of p-value for given value of t, degrees of freedom and type of
 *	comparition (Different, Greater than or Less than). */
double pValueStudentT(double tobs, double df, H1Comparition comp) {
	if (comp == H1Comparition::DIFFERENT) { // Two-tailed test
		return 2 * (studenttCDF(-abs(tobs), df));
	} else if (comp == H1Comparition::LESS_THAN) { // Left-tailed test
		return studenttCDF(tobs, df);
	} else if (comp == H1Comparition::GREATER_THAN) { // Right-tailed test
		return 1 - studenttCDF(tobs, df);
	}
	return 1;
}

/*! Snedcor's F Cumulative Distribution Function based on a regularized
 *	incomplete beta function.
 *	References:
 * 		http://mathworld.wolfram.com/F-Distribution.html
 * 		https://en.wikipedia.org/wiki/F-distribution
 *	Tested against Snedcor's F distribution table generated by Microsoft Excel,
 *	obtaining acceptable error values.*/
double fsnedecorCDF(unsigned long n, unsigned long m, double x) {
	return IncompleteBeta::incbeta(n / 2.0, m / 2.0, (n * x) / (m + n * x));
}

}  // namespace HypothesisTesting
