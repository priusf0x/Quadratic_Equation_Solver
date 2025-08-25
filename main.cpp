#include <stdio.h>
#include "Headers/Scan.h"
#include "Headers/Print.h"
#include "Headers/TestCreator.h"
#include "Headers/Test.h"

int main()
{
    //srand(time(NULL));
    struct Solution output = {.solution_type = EQUATION_TYPE_ERROR, .solution_1 = 0, .solution_2 = 0};
    struct Equation Coefficient = {.a = 0.0,.b = 0.0,.c = 0.0};
    enum ProgramStatus status = PROGRAM_STATE_MENU;

    PrintHelloMessage();

    while (status != PROGRAM_STATE_EXIT)
    {
        //printf(">>>");
        switch (status)
        {
            case PROGRAM_STATE_SOLVE:
                status = ReadCoefficients(&Coefficient);
                break;
            case PROGRAM_STATE_MENU:
                status = ReadUserInput();
                break;
            case PROGRAM_STATE_CALCULATION:
                status = PROGRAM_STATE_MENU;
                output = SolveQuadraticEquation(&Coefficient);
                Output(&output);
                break;
            case PROGRAM_STATE_HELP:
                status = PROGRAM_STATE_MENU;
                PrintHelp();
                break;
            case PROGRAM_STATE_TEST_CREATE:
                status = PROGRAM_STATE_MENU;
                CreateTest();
                printf("Tests were created successful.\n");
                break;
            case PROGRAM_STATE_TEST:
                status = PROGRAM_STATE_MENU;
                printf("Tests were done.\n");
                TestCalculation();
                break;
            case PROGRAM_STATE_EXIT:
                break;
            case PROGRAM_STATE_ERROR:
                printf("FATAL ERROR");
                break;
            case PROGRAM_STATE_BUFFER_OVERFLOW:
                status = PROGRAM_STATE_MENU;
                printf("BUFFER OVERFLOW. Try again:\n");
                break;
            default:
                status = PROGRAM_STATE_ERROR;
                break;
        }
    }
    return 0;
}
