#include "HypothesisTesting.h"
#include "TStudent.h"
#include <iostream>

bool tStudentTest(double tolerance);

int main() {
    std::cout << tStudentTest(10e-8) << std::endl;
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

            /*
            if(error > maxError) {
                std::cout << "\nt: " << t << std::endl;
                std::cout << "n: " << nValues[n] << std::endl;
                std::cout << "Esperado: " << qValues[q] << std::endl;
                std::cout << "Obtido: "	<< calculatedQ << std::endl;
                std::cout << "Erro: "	<< error << std::endl;
                maxError = error;
            }
            */
        }
    }
    return true;
    //std::cout << "\n\nErro máximo: " << maxError << std::endl;
}
