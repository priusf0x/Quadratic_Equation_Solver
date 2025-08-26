#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Headers/Scan.h"
#include "../Headers/Assert.h"
#include "../Headers/Program.h"
#include "../Headers/Color.h"

static char command[PROGRAM_INPUT_BUFFER_SIZE] = {0};

enum ProgramState ReadUserInput()
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
        command[count] = (char)character;
        count++;
    }

    if (count == PROGRAM_INPUT_BUFFER_SIZE)
    {
        ClearBuffer();
        return PROGRAM_STATE_BUFFER_OVERFLOW;
    }
    if (strcmp(command, "quit") == 0) //ANCHOR -  strncmp ANCHOR v chem problema
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
        printf(RED "Incorrect Input\n" STANDARD);
        while (character != '\n')
        {
            character = getchar();
        }
        return PROGRAM_STATE_MENU;
    }

}

enum ProgramState ReadCoefficients(struct Equation * coefficient)
{
    ASSERT(coefficient != NULL);

    int character = '\n';

    if (scanf("%lf %lf %lf", &(coefficient->a), &(coefficient->b), &(coefficient->c)) != 3)
    {
        printf(RED "Incorrect Input\n" STANDARD);
        ClearBuffer();
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

void ClearBuffer()
{
    int character = 0;
    while ((character = getchar()) != '\n' && character != EOF)
    {
        continue;
    }
}

