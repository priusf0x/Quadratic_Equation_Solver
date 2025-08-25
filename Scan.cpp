#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Headers/Scan.h"
#include "Headers/Assert.h"
#include "Headers/Program.h"

static char command[PROGRAM_INPUT_BUFFER_SIZE] = {0};

enum ProgramStatus ReadUserInput()
{
    int character = 0;
    int count = 0;

    while (count < PROGRAM_INPUT_BUFFER_SIZE)
    {
        command[count] = 0;
        count++;
    }

    count = 0;

    while ((character = getchar()) != '\n' && character != ' ' && count < PROGRAM_INPUT_BUFFER_SIZE)
    {
        command[count] = character;
        count++;
    }

    if (count == PROGRAM_INPUT_BUFFER_SIZE)
        {
            while (getchar() != '\n')
            {
                continue;
            }
            return PROGRAM_STATE_BUFFER_OVERFLOW;
        }
    if (strcmp(command, "quit") == 0)
    {
        return PROGRAM_STATE_EXIT;
    }
    else if (strcmp(command, "solve") == 0)
    {
        return PROGRAM_STATE_SOLVE;
    }
    else if (strcmp(command, "help") == 0)
    {
        return PROGRAM_STATE_HELP;
    }
    else if (strcmp(command, "createtest") == 0)
    {
        return PROGRAM_STATE_TEST_CREATE;
    }
    else if (strcmp(command, "test") == 0)
    {
        return PROGRAM_STATE_TEST;
    }
    else
    {
        printf("Incorrect Input\n");
        while (character != '\n')
        {
            character = getchar();
        }
        return PROGRAM_STATE_MENU;
    }
}

enum ProgramStatus ReadCoefficients(struct Equation * coefficient)
{
    ASSERT(coefficient == NULL)
    int character = '\n';

    if (scanf("%lf %lf %lf", &(coefficient->a), &(coefficient->b), &(coefficient->c)) != 3)
    {
        printf("Incorrect Input\n");
        while (getchar() != '\n')
        {
            continue;
        }
        return PROGRAM_STATE_MENU;
    }
    else
    {
        while ((character = getchar()) != '\n')
        {
            if (character != ' ')
            {
                return PROGRAM_STATE_MENU;
            }
        }

        return PROGRAM_STATE_CALCULATION;
    }
}

