#ifndef TEST_H
#define TEST_H

#include "Solve.h"
#include "Program.h"

/// @brief Test Calculation function
void TestCalculation(enum ProgramState * status);

void GetTestFromFile(struct Equation coefficient, FILE * file_test);

int GetTestFromFile(struct Equation * coefficient, double * solution_1, double * solution_2, FILE * file_test);

bool CheckIfTestIsCorrect(double solution_1, double solution_2, struct Solution * output);

#endif
