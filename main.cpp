#include <stdio.h>
#include "StructInfo.h"
#include "Scan.h"
#include "Print.h"
#include "Calculation.h"


int main(void)
{
    struct Solution output = {.solution_type = EQUATION_TYPE_ERROR, .solution_1 = 0, .solution_2 = 0};
    struct Equation Coefficient = {.a = 0.0,.b = 0.0,.c = 0.0};
    enum ProgramStatus status = PROGRAM_STATUS_MENU;

    PrintHelloMessage();

    while (status != PROGRAM_STATUS_EXIT)
    {
        switch (status)
        {
            case PROGRAM_STATUS_SOLVE:
                status = ReadCoefficients(&Coefficient);
                break;
            case PROGRAM_STATUS_MENU:
                status = ReadUserInput();
                break;
            case PROGRAM_STATUS_CALCULATION:
                status = PROGRAM_STATUS_MENU;
                output = SolveQuadraticEquation(&Coefficient);
                Output(output);
                break;
            case PROGRAM_STATUS_EXIT:
                break;
            case PROGRAM_STATUS_ERROR:
                printf("FATAL ERROR");
                break;
            default:
                status = PROGRAM_STATUS_ERROR;
                break;
        }
    }

    return 0;
}
