#include <stdio.h>
#include "StructInfo.h"
#include "Scan.h"
#include "Print.h"
#include "Calculation.h"

int main(void)
{
    struct calculator_output_s output = {.solution_type = ERROR, .solution_1 = 0, .solution_2 = 0};
    struct equation Coefficient = {.a = 0.0,.b = 0.0,.c = 0.0};
    bool end_flag = false;

    PrintHelloMessage();

    while (true)
    {
        // input = ReadUserInput()
        // asdfw 123 1fasef 1 2\n
        // quit
        // exit
        // tests
        // solve

        // buffer overflow
        while (ScanCoefficients(&Coefficient, &end_flag))
        {
            printf("Unable to read. Try again with correct Input \n");
        }

        if (end_flag)
        {
            break;
        }

        output = SolveQuadraticEquation(&Coefficient);

        Output(output);
        printf("Enter coefficients:('q' to leave) \n");
    }

    return 0;
}
