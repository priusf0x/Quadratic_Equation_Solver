#include <stdio.h>
#include <stdlib.h>
#include "../Headers/TestCreator.h"
#include "../Headers/Float.h"
#include "../Headers/Colour.h"
#include <time.h>

double CreateCoefficient(time_t seed)
{
    srand((unsigned int)seed);
    return double(random() % 500 - 500);
}

void GenerateEquation(struct TestData * data, time_t seed)
{
    srand((unsigned int)seed);
    data->type = int(random() % 4);

    data->a = CreateCoefficient(seed);
    if (!IsNull(data->a))
        if (data->type == 0)
        {
            data->solution_1 = CreateCoefficient(seed);
            data->solution_2 = CreateCoefficient(seed);
            data->b = (-data->solution_1 - data->solution_2) * (data->a);
            data->c = (data->solution_1 * data->solution_2) * (data->a);
        }
        else if (data->type == 1)
        {
            data->solution_1 = CreateCoefficient(seed);
            data->solution_2 = data->solution_1;
            data->b = (-data->solution_1 - data->solution_2) * (data->a);
            data->c = (data->solution_1 * data->solution_2) * (data->a);
        }
        else if (data->type == 2)
        {
            double a = CreateCoefficient(seed);
            double b = CreateCoefficient(seed);
            data->b = -2 * data->a * a;
            data->c = (a * a + b* b + 1) * data->a;
            data->solution_1 = 0;
            data->solution_2 = 0;
        }
        else
        {
            data->a = 0;
            data->b = 0;
            data->c = 0;
            data->solution_1 = 0;
            data->solution_2 = 0;
        }
    else
        {
            data->solution_1 = CreateCoefficient(seed);
            data->solution_2 = data->solution_1;
            data->b = CreateCoefficient(seed);
            data->c = - data->b * data->solution_1;
        }
}

void CreateTest(void)
{
    time_t start_seed = 0, seed=0;
    int test_number = 0;
    struct TestData data = { .type = 0,.a = 0, .b = 0, .c = 0, .solution_1 = 0, .solution_2 = 0};
    FILE * file_test = fopen("TestFiles/test.txt", "w");

    time(&start_seed);
    seed = start_seed;

    if (file_test == NULL)
    {
        printf(RED "FAILED TO WRITE FILE" STANDART);
        exit(EXIT_FAILURE);
    }


    for (test_number = 1; test_number <= max_test_number + 1000; test_number++, seed++ ) //this cycle very baggy, it fluctuate around value
    {
        GenerateEquation(&data, seed);
        fprintf(file_test, "%4.6lf %4.6lf %4.6lf %4.2lf %4.2lf \n", data.a, data.b, data.c, data.solution_1, data.solution_2);
    }
    printf(WHITE "Tests were created successful(SEED = %ld).\n" STANDART, start_seed);
    if (fclose(file_test) != 0)
    {
        printf(RED "FAILED TO READ FILE" STANDART);
        exit(EXIT_FAILURE);
    }
}
