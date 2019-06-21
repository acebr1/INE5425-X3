#include "HypothesisTesting.h"
#include "testValues.h"
#include <iostream>

#define DEBUG false

bool tStudentTest(double tolerance);
double getMaxTStudentError();
bool fSnedcorTest(double tolerance);
double getMaxFSnedcorError();

int main() {
    std::cout << tStudentTest(10e-6) << std::endl;
    std::cout << getMaxTStudentError() << std::endl;
    std::cout << fSnedcorTest(10e-6) << std::endl;
    std::cout << getMaxFSnedcorError() << std::endl;
	return 0;
}

bool tStudentTest(double tolerance) {
    double t, calculatedQ, error;

    // Check whole table
    for(int n = 0; n < TStudent::numN; n++) {
        for(int q = 0; q < TStudent::numQ; q++) {
            t = TStudent::distribution[n][q]; // Get table value for t
            calculatedQ = HypothesisTesting::studenttCDF(t, TStudent::nValues[n]); // Calculate q for table t

            error = TStudent::qValues[q] - calculatedQ; // Error (Real value of q - Calculated q)

            // If error is too big, return false
            if(error > tolerance)
                return false;
        }
    }
    return true;
}

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

            error = TStudent::qValues[q] - calculatedQ; // Error (Real value of q - Calculated q)

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

bool fSnedcorTest(double tolerance) {
    double f, calculatedQ, error;
    // Check whole table
    for(int n = 0; n < FSnedcor::numN; n++) {
        for(int m = 0; m < FSnedcor::numM; m++) {
            // ---------- Q = 0.95 ----------

            f = FSnedcor::distribution95[m][n]; // Get table value for f
            calculatedQ = HypothesisTesting::fsnedecorCDF(FSnedcor::nValues[n], FSnedcor::mValues[m], f); // Calculate q for table f
            error = 0.95 - calculatedQ; // Error (Real value of q - Calculated q)

            // If error is too big, return false
            if(error > tolerance)
                return false;

            // ---------- Q = 0.975 ----------

            f = FSnedcor::distribution975[m][n]; // Get table value for f
            calculatedQ = HypothesisTesting::fsnedecorCDF(FSnedcor::nValues[n], FSnedcor::mValues[m], f); // Calculate q for table f
            error = 0.975 - calculatedQ; // Error (Real value of q - Calculated q)

            // If error is too big, return false
            if(error > tolerance)
                return false;

            // ---------- Q = 0.99 ----------

            f = FSnedcor::distribution99[m][n]; // Get table value for f
            calculatedQ = HypothesisTesting::fsnedecorCDF(FSnedcor::nValues[n], FSnedcor::mValues[m], f); // Calculate q for table f
            error = 0.99 - calculatedQ; // Error (Real value of q - Calculated q)

            // If error is too big, return false
            if(error > tolerance)
                return false;
        }
    }
    return true;
}

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
            error = 0.95 - calculatedQ; // Error (Real value of q - Calculated q)

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
            error = 0.975 - calculatedQ; // Error (Real value of q - Calculated q)

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
            error = 0.99 - calculatedQ; // Error (Real value of q - Calculated q)

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
