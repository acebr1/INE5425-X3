#include "HypothesisTesting.h"
#include "testValues.h"
#include <iostream>

#define DEBUG false

bool testAverageTest(double sampleAvg1, double sampleStdDev1,
    unsigned long sampleNumElements1,double confidencelevel, double sampleAvg2,
    double sampleStdDev2, unsigned long sampleNumElements2,
    HypothesisTesting::H1Comparition comp,
    double expectedResult, double tolerance);
bool testProportionTest(double sampleProp1, unsigned long sampleNumElements1,
    double sampleProp2, unsigned long sampleNumElements2,
    HypothesisTesting::H1Comparition comp, double expectedResult,
    double tolerance);
bool testVarianceTest(double sampleVar1, unsigned long sampleNumElements1,
    double sampleVar2, unsigned long sampleNumElements2,
    HypothesisTesting::H1Comparition comp, double expectedResult,
    double tolerance);
bool tStudentTest(double tolerance);
double getMaxTStudentError();
bool fSnedcorTest(double tolerance);
double getMaxFSnedcorError();

int main() {
    double tolerance;

    // Tolerance for Distribution tests
    tolerance = 1e-5;

    // Call for Student's t cumulative distribution function tests
    std::cout << "Testing Student's t cumulative distribution function with "
        << tolerance << " tolerance:\n\n"
        << "\t" << (tStudentTest(tolerance) ? "Passed" : "Failed") << "\n"
        << "\tMaximum error = " << getMaxTStudentError()
        << "\n" << std::endl;

    // Call for Snedcor's F cumulative distribution function tests
    std::cout << "Testing Snedcor's F cumulative distribution function with "
        << tolerance << " tolerance:\n\n"
        << "\t" << (fSnedcorTest(tolerance) ? "Passed" : "Failed") << "\n"
        << "\tMaximum error = " << getMaxFSnedcorError()
        << "\n" << std::endl;

    // Tolerance for Hypothesis Tests
    tolerance = 1e-3;

    // Call for Average test tests
    std::cout << "Testing Average Test with "
        << tolerance << " tolerance:\n" << std::endl;

    for(int i = 0; i < testAverageData::numTests; i++) {
        std::cout << "\tTest " << i + 1 << ": "
        << (testAverageTest(
            testAverageData::sampleAvg1[i],
            testAverageData::sampleStdDev1[i],
            testAverageData::sampleNumElements1[i],
        	testAverageData::confidencelevel[i],
            testAverageData::sampleAvg2[i],
            testAverageData::sampleStdDev2[i],
        	testAverageData::sampleNumElements2[i],
            testAverageData::comp[i],
            testAverageData::expectedResult[i],
            tolerance) ? "Passed" : "Failed")
        <<  std::endl;
    }

    std::cout << std::endl;

    // Call for Proportion test tests
    std::cout << "Testing Proportion Test with "
        << tolerance << " tolerance:\n" << std::endl;

    for(int i = 0; i < testProportionData::numTests; i++) {
        std::cout << "\tTest " << i + 1 << ": "
        << (testProportionTest(
			testProportionData::sampleProp1[i],
			testProportionData::sampleNumElements1[i],
			testProportionData::sampleProp2[i],
			testProportionData::sampleNumElements2[i],
			testProportionData::comp[i],
			testProportionData::expectedResult[i],
            tolerance) ? "Passed" : "Failed")
        <<  std::endl;
    }

    std::cout << std::endl;

    // Call for Variance test tests
    std::cout << "Testing Variance Test with "
        << tolerance << " tolerance:\n" << std::endl;

    for(int i = 0; i < testVarianceData::numTests; i++) {
        std::cout << "\tTest " << i + 1 << ": "
        << (testProportionTest(
			testVarianceData::sampleVar1[i],
			testVarianceData::sampleNumElements1[i],
			testVarianceData::sampleVar2[i],
			testVarianceData::sampleNumElements2[i],
			testVarianceData::comp[i],
			testVarianceData::expectedResult[i],
            tolerance) ? "Passed" : "Failed")
        <<  std::endl;
    }

    std::cout << std::endl;


	for(int i = 0; i < testVarianceData::numTests; i++) {
	std::cout << "\tTest " << i + 1 << ": "
	<< testProportion(
		testVarianceData::sampleVar1[i],
		testVarianceData::sampleNumElements1[i],
		testVarianceData::sampleVar2[i],
		testVarianceData::sampleNumElements2[i],
		testVarianceData::comp[i])
	<<  std::endl;
	}

	std::cout << "Finished all tests!" <<  std::endl;
	return 0;
}

/*! Unit test for testAverage
 *  Tests if the diference between the result given by the testAverage function
 *  and the provided expected result is within the given tolerance
 */
 bool testAverageTest(
 	double sampleAvg1, double sampleStdDev1, unsigned long sampleNumElements1,
 	double confidencelevel, double sampleAvg2, double sampleStdDev2,
 	unsigned long sampleNumElements2, HypothesisTesting::H1Comparition comp,
    double expectedResult, double tolerance) {
        // Get testAverage result
        double result = HypothesisTesting::testAverage(sampleAvg1, sampleStdDev1,
            sampleNumElements1, confidencelevel, sampleAvg2, sampleStdDev2,
            sampleNumElements2, comp);
        // Calculate error
        double error = std::abs(expectedResult - result);
        // Return true if error is below given tolerance, otherwise return false
        return (error <= tolerance);
    }

/*! Unit test for testProportion
 *  Tests if the diference between the result given by the testProportion function
 *  and the provided expected result is within the given tolerance
 */
 bool testProportionTest(
 	double sampleProp1, unsigned long sampleNumElements1, double sampleProp2,
 	unsigned long sampleNumElements2, HypothesisTesting::H1Comparition comp,
    double expectedResult, double tolerance) {
        // Get testProportion result
        double result = HypothesisTesting::testProportion(sampleProp1,
            sampleNumElements1, sampleProp2, sampleNumElements2, comp);
        // Calculate error
        double error = std::abs(expectedResult - result);
        // Return true if error is below given tolerance, otherwise return false
        return (error <= tolerance);
    }

/*! Unit test for testVariance
 *  Tests if the diference between the result given by the testVariance function
 *  and the provided expected result is within the given tolerance
 */
 bool testVarianceTest(double sampleVar1, unsigned long sampleNumElements1,
    double sampleVar2, unsigned long sampleNumElements2,
    HypothesisTesting::H1Comparition comp, double expectedResult,
    double tolerance) {
        // Get testVariance result
        double result = HypothesisTesting::testVariance(sampleVar1,
            sampleNumElements1, sampleVar2, sampleNumElements2, comp);
        // Calculate error
        double error = std::abs(expectedResult - result);
        // Return true if error is below given tolerance, otherwise return false
        return (error <= tolerance);
    }

/*! Unit test for studenttCDF
 *  Tests if the difference between the values given by the studenttCDF function
 *  and the value expected according to the studnet's t distribution table are
 *  below the given tolerance
 */
bool tStudentTest(double tolerance) {
    double t, calculatedQ, error;

    // Check whole table
    for(int n = 0; n < TStudent::numN; n++) {
        for(int q = 0; q < TStudent::numQ; q++) {
            t = TStudent::distribution[n][q]; // Get table value for t
            calculatedQ = HypothesisTesting::studenttCDF(t, TStudent::nValues[n]); // Calculate q for table t

            error = std::abs(TStudent::qValues[q] - calculatedQ); // Error (Real value of q - Calculated q)

            // If error is too big, return false
            if(error > tolerance)
                return false;
        }
    }
    return true;
}

/*! Unit test for studenttCDF
 *  Retuns the maximum found difference for the values given by the
 *  studenttCDF function and the value expected according to the studnet's t
 *  distribution table
 */
double getMaxTStudentError() {
    double t, calculatedQ, error;
    double maxError = 0;

    if(DEBUG) {
        std::cout << "------------------------------" << std::endl;
        std::cout << "-------T STUDENT ERROR--------" << std::endl;
        std::cout << "------------------------------" << std::endl;
    }

    // Check whole table
    for(int n = 0; n < TStudent::numN; n++) {
        for(int q = 0; q < TStudent::numQ; q++) {
            t = TStudent::distribution[n][q]; // Get table value for t
            calculatedQ = HypothesisTesting::studenttCDF(t, TStudent::nValues[n]); // Calculate q for table t

            error = std::abs(TStudent::qValues[q] - calculatedQ); // Error (Real value of q - Calculated q)

            // Check if largest error so far
            if(error > maxError) {
                maxError = error;
                if(DEBUG) {
                    std::cout << "\nN = " << TStudent::nValues[n] << std::endl;
                    std::cout << "T = " << t << std::endl;
                    std::cout << "Q = " << TStudent::qValues[q] << std::endl;
                    std::cout << "CalculatedQ = " << calculatedQ << std::endl;
                    std::cout << "Error = " << error << std::endl;
                }
            }
        }
    }
    // Return max error found
    return maxError;
}

/*! Unit test for fsnedecorCDF
 *  Tests if the difference between the values given by the fsnedecorCDF function
 *  and the value expected according to the snedcor's f distribution table are
 *  below the given tolerance
 */
bool fSnedcorTest(double tolerance) {
    double f, calculatedQ, error;
    // Check whole table
    for(int n = 0; n < FSnedcor::numN; n++) {
        for(int m = 0; m < FSnedcor::numM; m++) {
            // ---------- Q = 0.95 ----------

            f = FSnedcor::distribution95[m][n]; // Get table value for f
            calculatedQ = HypothesisTesting::fsnedecorCDF(FSnedcor::nValues[n], FSnedcor::mValues[m], f); // Calculate q for table f
            error = std::abs(0.95 - calculatedQ); // Error (Real value of q - Calculated q)

            // If error is too big, return false
            if(error > tolerance)
                return false;

            // ---------- Q = 0.975 ----------

            f = FSnedcor::distribution975[m][n]; // Get table value for f
            calculatedQ = HypothesisTesting::fsnedecorCDF(FSnedcor::nValues[n], FSnedcor::mValues[m], f); // Calculate q for table f
            error = std::abs(0.975 - calculatedQ); // Error (Real value of q - Calculated q)

            // If error is too big, return false
            if(error > tolerance)
                return false;

            // ---------- Q = 0.99 ----------

            f = FSnedcor::distribution99[m][n]; // Get table value for f
            calculatedQ = HypothesisTesting::fsnedecorCDF(FSnedcor::nValues[n], FSnedcor::mValues[m], f); // Calculate q for table f
            error = std::abs(0.99 - calculatedQ); // Error (Real value of q - Calculated q)

            // If error is too big, return false
            if(error > tolerance)
                return false;
        }
    }
    return true;
}

/*! Unit test for fsnedecorCDF
 *  Retuns the maximum found difference for the values given by the
 *  fsnedecorCDF function and the value expected according to the snedcor's f
 *  distribution table
 */
double getMaxFSnedcorError() {
    double f, calculatedQ, error;
    double maxError = 0;

    if(DEBUG) {
        std::cout << "------------------------------" << std::endl;
        std::cout << "-------F SNEDCOR ERROR--------" << std::endl;
        std::cout << "------------------------------" << std::endl;
    }

    // Check whole table
    for(int n = 0; n < FSnedcor::numN; n++) {
        for(int m = 0; m < FSnedcor::numM; m++) {
            // ---------- Q = 0.95 ----------

            f = FSnedcor::distribution95[m][n]; // Get table value for f
            calculatedQ = HypothesisTesting::fsnedecorCDF(FSnedcor::nValues[n], FSnedcor::mValues[m], f); // Calculate q for table f
            error = std::abs(0.95 - calculatedQ); // Error (Real value of q - Calculated q)

            // Check if largest error so far
            if(error > maxError) {
                maxError = error;
                if(DEBUG) {
                    std::cout << "\nN = " << FSnedcor::nValues[n] << std::endl;
                    std::cout << "M = " << FSnedcor::mValues[m] << std::endl;
                    std::cout << "F = " << f << std::endl;
                    std::cout << "Q = 0.95" << std::endl;
                    std::cout << "CalculatedQ = " << calculatedQ << std::endl;
                    std::cout << "Error = " << error << std::endl;
                }
            }

            // ---------- Q = 0.975 ----------

            f = FSnedcor::distribution975[m][n]; // Get table value for f
            calculatedQ = HypothesisTesting::fsnedecorCDF(FSnedcor::nValues[n], FSnedcor::mValues[m], f); // Calculate q for table f
            error = std::abs(0.975 - calculatedQ); // Error (Real value of q - Calculated q)

            // Check if largest error so far
            if(error > maxError) {
                maxError = error;
                if(DEBUG) {
                    std::cout << "\nN = " << FSnedcor::nValues[n] << std::endl;
                    std::cout << "M = " << FSnedcor::mValues[m] << std::endl;
                    std::cout << "F = " << f << std::endl;
                    std::cout << "Q = 0.95" << std::endl;
                    std::cout << "CalculatedQ = " << calculatedQ << std::endl;
                    std::cout << "Error = " << error << std::endl;
                }
            }

            // ---------- Q = 0.99 ----------

            f = FSnedcor::distribution99[m][n]; // Get table value for f
            calculatedQ = HypothesisTesting::fsnedecorCDF(FSnedcor::nValues[n], FSnedcor::mValues[m], f); // Calculate q for table f
            error = std::abs(0.99 - calculatedQ); // Error (Real value of q - Calculated q)

            // Check if largest error so far
            if(error > maxError) {
                maxError = error;
                if(DEBUG) {
                    std::cout << "\nN = " << FSnedcor::nValues[n] << std::endl;
                    std::cout << "M = " << FSnedcor::mValues[m] << std::endl;
                    std::cout << "F = " << f << std::endl;
                    std::cout << "Q = 0.95" << std::endl;
                    std::cout << "CalculatedQ = " << calculatedQ << std::endl;
                    std::cout << "Error = " << error << std::endl;
                }
            }
        }
    }
    // Return max error found
    return maxError;
}
