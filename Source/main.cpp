#include <stdio.h>
#include <string.h>
#include "../Headers/Scan.h"
#include "../Headers/Print.h"
#include "../Headers/TestCreator.h"
#include "../Headers/Test.h"
#include "../Headers/Color.h"
#include "../Headers/Main.h"

int main(int argc, char **argv)
{

    printf("Poltorashka studio presents\n");

    if (argc > 1)
    {
        ReadFlags(argc, argv);
    }
    else
    {
        PrintHelloMessage();
        StartStateMachine();
    }

    printf("Vsyo poka\n"
           "GIT COMMIT\n");
    return 0;
}

void StartStateMachine()
{
    struct Solution output = {.solution_type = EQUATION_TYPE_NO_ROOTS, .solution_1 = 0, .solution_2 = 0};
    struct Equation Coefficient = {.a = 0.0,.b = 0.0,.c = 0.0};
    enum ProgramState status = PROGRAM_STATE_MENU;

    while (status != PROGRAM_STATE_EXIT)
    {
        switch (status)
        {
            case PROGRAM_STATE_SOLVE:
                status = ReadCoefficients(&Coefficient);
                break;

            case PROGRAM_STATE_MENU:
                printf(YELLOW ">>> " STANDARD);
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
                TestCalculation(&status);
                break;

            case PROGRAM_STATE_EXIT:
                break;

            case PROGRAM_STATE_FILE_ERROR:
                printf("Something happened with your file.");
                status = PROGRAM_STATE_EXIT;
                break;

            case PROGRAM_STATE_BUFFER_OVERFLOW:
                status = PROGRAM_STATE_MENU;
                printf(RED "BUFFER OVERFLOW. Try again:\n" STANDARD);
                break;

            default:
                status = PROGRAM_STATE_EXIT;
                printf("Something bad happened(");
                break;
        }
    }
}

// TODO: move to Flags.cpp

void ReadFlags(int argc, char **argv)
{
    int index = 0;
    enum ProgramState status = PROGRAM_STATE_TEST;
    for (index = 1; index < argc; index++)
        if ((strcmp(argv[index], "-h") == 0 || strcmp(argv[index], "--help") == 0))
        {
            PrintHelp();
        }
        else if ((strcmp(argv[index], "-t") == 0 || strcmp(argv[index], "--test") == 0))
        {
            TestCalculation(&status);
            if (status == PROGRAM_STATE_EXIT)
                return;
        }
        else
        {
            printf("Incorrect Flag \n");
        }
}
