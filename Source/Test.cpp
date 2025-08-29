#include "Test.h"

#include <stdio.h>

#include "Solve.h"
#include "TestCreator.h"
#include "Calculation.h"
#include "Float.h"
#include "Color.h"
#include "Logger.h"

void TestCalculation(enum ProgramState * status)
{
    int test_num = 0;
    double solution_1 = 0, solution_2 = 0;
    struct Equation coefficient = {.a = 0, .b = 0, .c = 0};
    struct Solution output = {.solution_type = EQUATION_TYPE_TWO_ROOTS, .solution_1 = 0, .solution_2 = 0};
    FILE * file_test = fopen(MEOW_FILE, "r");

    if (file_test == NULL)
    {
        LogShit(DETALIZATION_LEVEL_ERROR, "Program couldn't open the file");
        printf(RED "FAILED TO READ FILE\n" STANDARD);
        *status = PROGRAM_STATE_EXIT;
        return;
    }

    for (test_num = 1; test_num <= max_test_number; test_num++)
    {
        if (GetTestFromFile(&coefficient, &solution_1, &solution_2, file_test))
        {
            LogShit(DETALIZATION_LEVEL_ERROR, "Program couldn't read from the file");
            printf(RED "FAILED TO READ FILE" STANDARD);
            *status = PROGRAM_STATE_EXIT;
            return;
        }

        output = SolveQuadraticEquation(&coefficient);

        if (CheckIfTestIsCorrect(solution_1, solution_2, &output))
        {
            LogShit(DETALIZATION_LEVEL_ERROR, "Program failed in test %d", test_num);
            printf(RED "ERROR in test %d:real x1 =  %lf, expected %lf, real x2 = %lf, expected %lf \n"
                    STANDARD, test_num,
                    Max(output.solution_1,output.solution_2), Max(solution_1,solution_2),
                    Min(output.solution_1,output.solution_2), Min(solution_1,solution_2));
        }
    }

    if (fclose(file_test) != 0)
    {
        printf(RED "FAILED TO CLOSE FILE" STANDARD);
        LogShit(DETALIZATION_LEVEL_DEBUG, "FAILED TO CLOSE FILE");
        *status = PROGRAM_STATE_EXIT;
        return;
    }

    LogShit(DETALIZATION_LEVEL_DEBUG, "Tests were done");
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
