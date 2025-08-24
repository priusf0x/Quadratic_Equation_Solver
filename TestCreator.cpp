#include <stdio.h>
#include <stdlib.h>
#include "Headers/TestCreator.h"

void GenerateEquation(struct TestData * data)
{
    data->type = int(random() % 3);
    data->a = double(random() % 2000 - 1000);
    if (data->type == 0)
    {
        data->solution_1 = double(random() % 2000 - 1000);
        data->solution_2 = double(random() % 2000 - 1000);
        data->b = (-data->solution_1 - data->solution_2) * (data->a);
        data->c = (data->solution_1 * data->solution_2) * (data->a);
    }
    else if (data->type == 1)
    {
        data->solution_1 = double(random() % 2000 - 1000);
        data->solution_2 = data->solution_1;
        data->b = (-data->solution_1 - data->solution_2) * (data->a);
        data->c = (data->solution_1 * data->solution_2) * (data->a);
    }
    else
    {
        double a = double(random() % 2000 - 1000);
        double b = double(random() % 2000 - 1000);
        data->b = -2 * data->a * a;
        data->c = (a * a + b* b + 1) * data->a;
        data->solution_1 = 0;
        data->solution_2 = 0;
    }
}

void CreateTest(void)
{
    FILE * file_test;
    int test_number = 0;
    struct TestData data = { .type = 0,.a = 0, .b = 0, .c = 0, .solution_1 = 0, .solution_2 = 0};
    file_test = fopen("TestFiles/test.txt", "w");

    for (test_number = 1; test_number <= max_test_number; test_number++)
    {
        GenerateEquation(&data);
        fprintf(file_test, "%4.6lf %4.6lf %4.6lf %d %4.2lf %4.2lf \n", data.a, data.b, data.c, data.type, data.solution_1, data.solution_2);
    }
}
