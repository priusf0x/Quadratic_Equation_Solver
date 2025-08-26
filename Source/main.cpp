#include <stdio.h>
#include "../Headers/Scan.h"
#include "../Headers/Print.h"
#include "../Headers/TestCreator.h"
#include "../Headers/Test.h"
#include "../Headers/Color.h"


// argc argv
// ./Solver --tests <path>
// ./Solver 12 32 44
// ./Solver --interactive
int main()
{
    struct Solution output = {.solution_type = EQUATION_TYPE_NO_ROOTS, .solution_1 = 0, .solution_2 = 0};
    struct Equation Coefficient = {.a = 0.0,.b = 0.0,.c = 0.0};
    enum ProgramState status = PROGRAM_STATE_MENU;

    PrintHelloMessage();

    while (status != PROGRAM_STATE_EXIT)
    {
        switch (status)
        {
            case PROGRAM_STATE_SOLVE:
                status = ReadCoefficients(&Coefficient);
                break;
            case PROGRAM_STATE_MENU:
                printf(YELLOW ">>> "STANDARD);
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
                break;
            case PROGRAM_STATE_TEST:
                status = PROGRAM_STATE_MENU;
                printf(WHITE "Tests were done.\n" STANDARD);
                TestCalculation();
                break;
            case PROGRAM_STATE_EXIT:
                break;
            case PROGRAM_STATE_ERROR:
                break;
            case PROGRAM_STATE_BUFFER_OVERFLOW:
                status = PROGRAM_STATE_MENU;
                printf(RED "BUFFER OVERFLOW. Try again:\n" STANDARD);
                break;
            default:
                status = PROGRAM_STATE_ERROR;
                break;
        }
    }

    printf("Vsyo poka\n");
    return 0;
}
