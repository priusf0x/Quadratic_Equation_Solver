#include "TestCreator.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Float.h"
#include "Color.h"
#include "Assert.h"
#include "Logger.h"

double CreateCoefficient()
{
    return double(random() % GenerationRange - GenerationRange);
}

void GenerateEquation(struct TestData * data, time_t seed)
{
    ASSERT(data != NULL);

    srand((unsigned int)seed);
    data->type = int(random() % 4);

    data->a = CreateCoefficient();
    if (!IsZero(data->a))
        if (data->type == CREATED_EQUATION_TYPE_TWO_SOLUTIONS)
        {
            data->solution_1 = CreateCoefficient();
            data->solution_2 = CreateCoefficient();
            data->b = (-data->solution_1 - data->solution_2) * (data->a);
            data->c = (data->solution_1 * data->solution_2) * (data->a);
        }
        else if (data->type == CREATED_EQUATION_TYPE_ONE_SOLUTION)
        {
            data->solution_1 = CreateCoefficient();
            data->solution_2 = data->solution_1;
            data->b = (-data->solution_1 - data->solution_2) * (data->a);
            data->c = (data->solution_1 * data->solution_2) * (data->a);
        }
        else if (data->type == CREATED_EQUATION_TYPE_NO_SOLUTION)
        {
            double a = CreateCoefficient();
            double b = CreateCoefficient();
            data->b = -2 * data->a * a;
            data->c = (a * a + b* b + 1) * data->a;
            data->solution_1 = 0;
            data->solution_2 = 0;
        }
        else // Null coeff test
        {
            data->a = 0;
            data->b = 0;
            data->c = 0;
            data->solution_1 = 0;
            data->solution_2 = 0;
        }
    else //coeff_a is zero type
        {
            data->solution_1 = CreateCoefficient();
            data->solution_2 = data->solution_1;
            data->b = CreateCoefficient();
            data->c = - data->b * data->solution_1;
        }
}

void CreateTest(enum ProgramState * status)
{
    FILE * file_test = fopen(MEOW_FILE, "w");

    if (file_test == NULL)
    {
        LogShit(DETALIZATION_LEVEL_DEBUG, "FAILED TO OPEN FILE");
        *status = PROGRAM_STATE_EXIT;
        printf(RED "FAILED TO WRITE FILE" STANDARD);
        return;
    }

    time_t start_seed = 0, seed = 0;
    time(&start_seed);
    seed = start_seed;

    struct TestData data = { .type = 0, .a = 0, .b = 0, .c = 0, .solution_1 = 0, .solution_2 = 0};
    for (int test_number = 1; test_number <= max_test_number + additional_test; test_number++, seed++ )
    {
        GenerateEquation(&data, seed);
        fprintf(file_test, "%4.6lf %4.6lf %4.6lf %4.2lf %4.2lf \n", data.a, data.b, data.c, data.solution_1, data.solution_2);
    }

    printf(WHITE "Tests were created successful(SEED = %ld).\n" STANDARD, start_seed);

    if (fclose(file_test) != 0)
    {
        LogShit(DETALIZATION_LEVEL_DEBUG, "FAILED TO CLOSE FILE");
        *status = PROGRAM_STATE_EXIT;
        printf(RED "FAILED TO READ FILE" STANDARD);
        return;
    }

    LogShit(DETALIZATION_LEVEL_DEBUG, "Created tests");
}
