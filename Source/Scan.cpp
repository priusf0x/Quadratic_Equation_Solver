#include "Scan.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Assert.h"
#include "Program.h"
#include "Color.h"

// NOTE: -I

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

    ungetc(character, stdin);

    if (count == PROGRAM_INPUT_BUFFER_SIZE)
    {
        return PROGRAM_STATE_BUFFER_OVERFLOW;
    }

    if (strcmp(command, "quit") == 0)
    {
        return CheckIfSpaces(PROGRAM_STATE_EXIT);
    }
    else if (strcmp(command, "solve") == 0)
    {
        return PROGRAM_STATE_SOLVE;
    }
    else if (strcmp(command, "help") == 0)
    {
        return CheckIfSpaces(PROGRAM_STATE_HELP);
    }
    else if (strcmp(command, "createtest") == 0)
    {
        return CheckIfSpaces(PROGRAM_STATE_TEST_CREATE);
    }
    else if (strcmp(command, "test") == 0)
    {
        return CheckIfSpaces(PROGRAM_STATE_TEST);
    }
    else
    {
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
        printf(RED "Incorrect Input\n" STANDARD);
        ClearBuffer();
        return PROGRAM_STATE_MENU;
    }
    else
    {
        return CheckIfSpaces(PROGRAM_STATE_CALCULATION);
    }
}

bool ClearBuffer()
{
    bool flag = false;
    int character = 0;
    while ((character = getchar()) != '\n' && character != EOF)
    {
        if (isspace(character))
        {
            flag = true;
        }
    }
    return flag;
}

enum ProgramState CheckIfSpaces(enum ProgramState expected_state)
{
    if (ClearBuffer())
    {
        printf(RED "Incorrect Input\n" STANDARD);
        return PROGRAM_STATE_MENU;
    }
    else
    {
        return expected_state;
    }
}


