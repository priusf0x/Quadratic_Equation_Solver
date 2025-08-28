#ifndef TEST_CREATOR_H
#define TEST_CREATOR_H
#include <time.h>
#include "Program.h"

/// @brief Generates Equation with solution
/// @param [in] data pointer to *TestData* struct
void GenerateEquation(struct TestData * data, time_t seed);

/// @brief Struct for output of GenerateEquation() fuction
struct TestData
{
    int type;
    double a;
    double b;
    double c;
    double solution_1;
    double solution_2;
};

const int additional_test = 1000;

/// @brief Creates test in Test.txt file
void CreateTest(enum ProgramState * status);

/// @brief Limit of test number
const int max_test_number = 100000;

/// @brief function for random number
double CreateCoefficient();
enum CreatedEquationType
{
    CREATED_EQUATION_TYPE_TWO_SOLUTIONS = 0,
    CREATED_EQUATION_TYPE_ONE_SOLUTION = 1,
    CREATED_EQUATION_TYPE_NO_SOLUTION = 2
};

const int GenerationRange = 500;

const char MEOW_FILE[] = "TestFiles/test.txt";

#endif
