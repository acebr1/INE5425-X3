#include "HypothesisTesting.h" 

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
	unsigned long n = sampleNumElements1-1;
	unsigned long m = sampleNumElements2-1;
	double fcal = sampleVar1/sampleVar2;
	if (comp == H1Comparition::DIFFERENT) {
		double leftTail = fsnedecorCDF(n, m, fcal);
		double rightTail = 1 - leftTail;
		return !(rightTail < leftTail)?2*rightTail:2*leftTail;
	} else if (comp == H1Comparition::LESS_THAN) {
		double leftTail = fsnedecorCDF(n, m, fcal);
		return leftTail;
	} else if (comp == H1Comparition::GREATER_THAN) {
		double rightTail = 1 - fsnedecorCDF(n, m, fcal);
		return rightTail;
	}
	return fcal;
}

//https://stackoverflow.com/questions/2328258/cumulative-normal-distribution-function-in-c-c
double HypothesisTesting::normalCDF(double value)
{
   return 0.5 * erfc(-value * M_SQRT1_2);
}

//https://github.com/codeplea/incbeta
//https://codeplea.com/incomplete-beta-function-c

double HypothesisTesting::studenttCDF(double t, double v) 
{
    /*The cumulative distribution function (CDF) for Student's t distribution*/
    IncompleteBeta beta;
    double x = (t + sqrt(t * t + v)) / (2.0 * sqrt(t * t + v));
    return beta.incbeta(v/2.0, v/2.0, x);
}

//http://mathworld.wolfram.com/F-Distribution.html
//https://en.wikipedia.org/wiki/F-distribution
double HypothesisTesting::fsnedecorCDF(unsigned long n, unsigned long m, double x)
{
    /*The cumulative distribution function (CDF) for F distribution*/
    IncompleteBeta beta;
    return beta.regularizedbeta(n/2.0, m/2.0, (n*x)/(m+n*x));
}

