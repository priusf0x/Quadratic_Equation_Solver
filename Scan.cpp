#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Headers/Scan.h" // Linux Paths syntax
#include "Headers/Assert.h"
#include "Headers/Program.h"


// Header Guard

// From file

// PROGRAM_INPUT_BUFFER_SIZE

// static
enum ProgramStatus ReadUserInput()
{
    char command[PROGRAM_INPUT_BUFFER_SIZE] = {0};
    int character = 0;
    int count = 0;

    while ((character = getchar()) != '\n' && character != ' ' && count < PROGRAM_INPUT_BUFFER_SIZE)
    {
        command[count] = character;
        count++;
    } // Too long input...

    if (strcmp(command, "quit") == 0)
    {
        return PROGRAM_STATUS_EXIT;
    }
    else if (strcmp(command, "solve") == 0)
    {
        return PROGRAM_STATUS_SOLVE;
    }
    else if (strcmp(command, "help") == 0)
    {
        return PROGRAM_STATUS_HELP;
    }
    else
    {
        printf("Incorrect Input\n");
        while (character != '\n')
        {
            character = getchar();
        }
        return PROGRAM_STATUS_MENU;
    }
}

enum ProgramStatus ReadCoefficients(struct Equation * coefficient)
{
    ASSERT(coefficient != NULL)
    int character = '\n';

    if (scanf("%f %f %f", &(coefficient->a), &(coefficient->b), &(coefficient->c)) != 3)
    {
        printf("Incorrect Input\n");
        while (getchar() != '\n')
        {
            continue;
        }
        return PROGRAM_STATUS_MENU;
    }
    else
    {
        while ((character = getchar()) != '\n')
        {
            if (character != ' ')
            {
                return PROGRAM_STATUS_MENU;
            }
        }

        return PROGRAM_STATUS_CALCULATION;
    }
}

