#include <stdio.h>
#include "../Headers/Solve.h"
#include "../Headers/Test.h"
#include "../Headers/TestCreator.h"
#include "../Headers/Calculation.h"
#include "../Headers/Float.h"
#include "../Headers/Colour.h"

void TestCalculation()
{
    int test_num = 0;
    double solution_1 = 0, solution_2 = 0;
    struct Equation coefficient = {.a = 0, .b = 0, .c = 0};
    struct Solution output = {.solution_type = EQUATION_TYPE_TWO_ROOTS, .solution_1 = 0, .solution_2 = 0};
    FILE * file_test = fopen("TestFiles/test.txt", "r");

    if (file_test == NULL)
    {
        printf(RED "FAILED TO WRITE FILE" STANDART);
        exit(EXIT_FAILURE);
    }


    for (test_num = 1; test_num <= max_test_number; test_num++)
    {
        fscanf(file_test, "%lf %lf %lf %lf %lf", &(coefficient.a), &(coefficient.b), &(coefficient.c),
         &solution_2, &solution_1);

        output = SolveQuadraticEquation(&coefficient);

        if (!(IsNull(max(output.solution_1,output.solution_2) - max(solution_1,solution_2))
           && IsNull(min(output.solution_1,output.solution_2) - min(solution_1,solution_2))))
            {
                printf(RED "ERROR in test %d:real x1 =  %lf, expected %lf, real x2 = %lf, expected %lf \n"
                       STANDART, test_num,
                       max(output.solution_1,output.solution_2), max(solution_1,solution_2),
                       min(output.solution_1,output.solution_2), min(solution_1,solution_2));
            }
    }

    if (fclose(file_test) != 0)
    {
        printf(RED "FAILED TO READ FILE" STANDART);
        exit(EXIT_FAILURE);
    }

}

