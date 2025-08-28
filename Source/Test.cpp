#include <stdio.h>
#include "../Headers/Solve.h"
#include "../Headers/Test.h"
#include "../Headers/TestCreator.h"
#include "../Headers/Calculation.h"
#include "../Headers/Float.h"
#include "../Headers/Color.h"

void TestCalculation(enum ProgramState * status)
{
    int test_num = 0;
    double solution_1 = 0, solution_2 = 0;
    struct Equation coefficient = {.a = 0, .b = 0, .c = 0};
    struct Solution output = {.solution_type = EQUATION_TYPE_TWO_ROOTS, .solution_1 = 0, .solution_2 = 0};
    FILE * file_test = fopen("TestFiles/test.txt", "r");

    if (file_test == NULL)
    {
        printf(RED "FAILED TO READ FILE" STANDARD);
        *status = PROGRAM_STATE_EXIT;
        return;
    }

    for (test_num = 1; test_num <= max_test_number; test_num++)
    {
        if (GetTestFromFile(&coefficient, &solution_1, &solution_2, file_test))
        {
            printf(RED "FAILED TO READ FILE" STANDARD);
            *status = PROGRAM_STATE_EXIT;
            return;
        }

        output = SolveQuadraticEquation(&coefficient);

        if (CheckIfTestIsCorrect(solution_1, solution_2, &output))
        {
            printf(RED "ERROR in test %d:real x1 =  %lf, expected %lf, real x2 = %lf, expected %lf \n"
                    STANDARD, test_num,
                    Max(output.solution_1,output.solution_2), Max(solution_1,solution_2),
                    Min(output.solution_1,output.solution_2), Min(solution_1,solution_2));
        }
    }

    if (fclose(file_test) != 0)
    {
        printf(RED "FAILED TO READ FILE" STANDARD);
        *status = PROGRAM_STATE_EXIT;
        return;
    }

    printf(WHITE "Tests were done.\n" STANDARD);
}

int GetTestFromFile(struct Equation * coefficient, double * solution_1, double * solution_2, FILE * file_test)
{
    return (fscanf(file_test, "%lf %lf %lf %lf %lf", &(coefficient->a), &(coefficient->b), &(coefficient->c),
            solution_2, solution_1) != 5);
}

bool CheckIfTestIsCorrect(double solution_1, double solution_2, struct Solution * output)
{
    return !(IsZero(Max(output->solution_1,output->solution_2) - Max(solution_1,solution_2))
          && IsZero(Min(output->solution_1,output->solution_2) - Min(solution_1,solution_2)));
}
