#include "Scan.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Assert.h"
#include "Program.h"
#include "Color.h"
#include "Logger.h"

static char command[PROGRAM_INPUT_BUFFER_SIZE] = {0};

enum ProgramState ReadUserInput()
{
    int character = 0;
    int count = 0;

    memset(command, 0, PROGRAM_INPUT_BUFFER_SIZE);

    count = 0;

    while ((character = getchar()) != '\n' && character != ' ' && count < PROGRAM_INPUT_BUFFER_SIZE)
    {
        command[count] = (char)character;
        count++;
    }

    LogShit(DETALIZATION_LEVEL_DEBUG, "Program read the command");

    ungetc(character, stdin);

    if (count == PROGRAM_INPUT_BUFFER_SIZE)
    {
        return PROGRAM_STATE_BUFFER_OVERFLOW;
    }

    if (strcmp(command, "quit") == 0)
    {
        LogShit(DETALIZATION_LEVEL_DEBUG, "Program have read quit command");
        return CheckIfSpaces(PROGRAM_STATE_EXIT);
    }
    else if (strcmp(command, "solve") == 0)
    {
        LogShit(DETALIZATION_LEVEL_DEBUG, "Program have read solve command");
        return PROGRAM_STATE_SOLVE;
    }
    else if (strcmp(command, "help") == 0)
    {
        LogShit(DETALIZATION_LEVEL_DEBUG, "Program have read help command");
        return CheckIfSpaces(PROGRAM_STATE_HELP);
    }
    else if (strcmp(command, "createtest") == 0)
    {
        LogShit(DETALIZATION_LEVEL_DEBUG, "Program have read create_test command");
        return CheckIfSpaces(PROGRAM_STATE_TEST_CREATE);
    }
    else if (strcmp(command, "test") == 0)
    {
        LogShit(DETALIZATION_LEVEL_DEBUG, "Program have read test command");
        return CheckIfSpaces(PROGRAM_STATE_TEST);
    }
    else
    {
        LogShit(DETALIZATION_LEVEL_ERROR, "Program haven't classified the command");
        printf(RED "Incorrect Input\n" STANDARD);
        ClearBuffer();
        return PROGRAM_STATE_MENU;
    }

}

enum ProgramState ReadCoefficients(struct Equation * coefficient)
{
    ASSERT(coefficient != NULL);

    if (scanf("%lf %lf %lf", &(coefficient->a), &(coefficient->b), &(coefficient->c)) != 3)
    {
        LogShit(DETALIZATION_LEVEL_DEBUG, "Program could't read the coefficients");
        printf(RED "Incorrect Input\n" STANDARD);
        ClearBuffer();
        return PROGRAM_STATE_MENU;
    }
    else
    {
        LogShit(DETALIZATION_LEVEL_DEBUG, "SolveQuadraticEquation got coefficients a = %lf, b = %lf, c = %lf", coefficient->a, coefficient->b, coefficient->c);
        return CheckIfSpaces(PROGRAM_STATE_CALCULATION);
    }
}

bool ClearBuffer()
{
    bool flag = false;
    int character = 0;
    while ((character = getchar()) != '\n' && character != EOF)
    {
        if (!isspace(character))
        {
            flag = true;
        }
    }
    LogShit(DETALIZATION_LEVEL_DEBUG, "Program cleared buffer");
    return flag;
}

enum ProgramState CheckIfSpaces(enum ProgramState expected_state)
{
    if (ClearBuffer())
    {
        LogShit(DETALIZATION_LEVEL_DEBUG, "Program detected symbols after command");
        printf(RED "Incorrect Input\n" STANDARD);
        return PROGRAM_STATE_MENU;
    }
    else
    {
        return expected_state;
    }
}


