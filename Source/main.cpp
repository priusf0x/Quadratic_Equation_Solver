#include "Main.h"

#include <stdio.h>
#include <string.h>

#include "Scan.h"
#include "Print.h"
#include "TestCreator.h"
#include "Test.h"
#include "Color.h"
#include "Flag.h"
#include "Assert.h"
#include "Logger.h"

int main(int argc, char **argv)
{
    printf("Poltorashka studio presents\n");

    ReadFlags(argc, argv);

    LogShit(DETALIZATION_LEVEL_DEBUG, "Program has read flags");

    PrintHelloMessage();
    StartStateMachine();

    printf("Vsyo poka\n"
           "GIT COMMIT\n");

    LogShit(DETALIZATION_LEVEL_DEBUG, "Program stopped running");

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
                LogShit(DETALIZATION_LEVEL_DEBUG, "Program in state solve");
                status = ReadCoefficients(&Coefficient);
                break;

            case PROGRAM_STATE_MENU:
                LogShit(DETALIZATION_LEVEL_DEBUG, "Program in state menu");
                printf(YELLOW ">>> " STANDARD);
                status = ReadUserInput();
                break;

            case PROGRAM_STATE_CALCULATION:
                LogShit(DETALIZATION_LEVEL_DEBUG, "Program in state calculation");
                status = PROGRAM_STATE_MENU;
                output = SolveQuadraticEquation(&Coefficient);
                Output(&output);
                break;

            case PROGRAM_STATE_HELP:
                LogShit(DETALIZATION_LEVEL_DEBUG, "Program in state help_menu");
                status = PROGRAM_STATE_MENU;
                PrintHelp();
                break;

            case PROGRAM_STATE_TEST_CREATE:
                LogShit(DETALIZATION_LEVEL_DEBUG, "Program in state create");
                status = PROGRAM_STATE_MENU;
                CreateTest(&status);
                break;

            case PROGRAM_STATE_TEST:
                LogShit(DETALIZATION_LEVEL_DEBUG, "Program in state test");
                status = PROGRAM_STATE_MENU;
                TestCalculation(&status);
                break;

            case PROGRAM_STATE_EXIT:
                LogShit(DETALIZATION_LEVEL_ERROR, "ERROR: Program in state exit");
                break;

            case PROGRAM_STATE_FILE_ERROR:
                LogShit(DETALIZATION_LEVEL_ERROR, "ERROR: Program in state file_error");
                status = PROGRAM_STATE_MENU;
                printf("Something happened with your file.");
                break;

            case PROGRAM_STATE_BUFFER_OVERFLOW:
                LogShit(DETALIZATION_LEVEL_ERROR, "ERROR: Program in state buffer_overflow");
                status = PROGRAM_STATE_MENU;
                printf(RED "BUFFER OVERFLOW. Try again:\n" STANDARD);
                break;

            default:
                LogShit(DETALIZATION_LEVEL_ERROR, "ERROR: Fatal error happened");
                status = PROGRAM_STATE_EXIT;
                printf("Something bad happened(");
                break;
        }
    }
}

