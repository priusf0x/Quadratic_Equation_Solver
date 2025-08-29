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

    OpenLogFile();

    ReadFlags(argc, argv);

    LOGDEBUG("Function have read the flags in function %s" COMMA __FUNCTION__);

    PrintHelloMessage();
    StartStateMachine();

    printf("Vsyo poka\n"
           "GIT COMMIT\n");

    LOGDEBUG("Program ended");
    CloseLogFile();
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
                LOGDEBUG("Program in state solve");
                status = ReadCoefficients(&Coefficient);
                break;

            case PROGRAM_STATE_MENU:
                LOGDEBUG("Program in state menu");
                printf(YELLOW ">>> " STANDARD);
                status = ReadUserInput();
                break;

            case PROGRAM_STATE_CALCULATION:
                LOGDEBUG("Program in state calculation");
                status = PROGRAM_STATE_MENU;
                output = SolveQuadraticEquation(&Coefficient);
                Output(&output);
                break;

            case PROGRAM_STATE_HELP:
                LOGDEBUG("Program in state help");
                status = PROGRAM_STATE_MENU;
                PrintHelp();
                break;

            case PROGRAM_STATE_TEST_CREATE:
                LOGDEBUG("Program in state create");
                status = PROGRAM_STATE_MENU;
                CreateTest(&status);
                break;

            case PROGRAM_STATE_TEST:
                LOGDEBUG("Program in state test");
                status = PROGRAM_STATE_MENU;
                TestCalculation(&status);
                break;

            case PROGRAM_STATE_EXIT:
                LOGERROR("Leaving state machine...");
                break;

            case PROGRAM_STATE_FILE_ERROR:
                LOGERROR("Program got file error");
                status = PROGRAM_STATE_MENU;
                printf("Something happened with your file.");
                break;

            case PROGRAM_STATE_BUFFER_OVERFLOW:
                LOGERROR("Program got buffer_overflow");
                status = PROGRAM_STATE_MENU;
                printf(RED "BUFFER OVERFLOW. Try again:\n" STANDARD);
                break;

            default:
                LOGERROR("Program got fatal error");
                status = PROGRAM_STATE_EXIT;
                printf("Something bad happened(");
                break;
        }
    }
}

