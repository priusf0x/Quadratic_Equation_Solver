#include <stdio.h>
#include "Headers/Solve.h"
#include "Headers/Test.h"
#include "Headers/TestCreator.h"
#include "Headers/Calculation.h"
#include "Headers/Float.h"

void TestCalculation()
{
    int test_num = 0;
    double solution_1 = 0, solution_2 = 0;
    struct Equation coefficient;
    struct Solution output;
    FILE * test_file;
    test_file = fopen("TestFiles/test.txt", "r");

    for (test_num = 1; test_num <= max_test_number; test_num++)
    {
        fscanf(test_file, "%lf %lf %lf %lf %lf", &(coefficient.a), &(coefficient.b), &(coefficient.c), &solution_2, &solution_1);

        output = SolveQuadraticEquation(&coefficient);

        if (!(IsNull(max(output.solution_1,output.solution_2) - max(solution_1,solution_2)) \
        && IsNull(min(output.solution_1,output.solution_2) - min(solution_1,solution_2))))
            {
                printf("%d:real x1 =  %lf, expected %lf, real x2 = %lf, expected %lf \n", test_num, max(output.solution_1,output.solution_2), max(solution_1,solution_2), min(output.solution_1,output.solution_2), min(solution_1,solution_2));
            }
    }
}

