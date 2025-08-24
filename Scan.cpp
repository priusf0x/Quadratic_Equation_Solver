#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "StructInfo.h"
#include "Scan.h"

enum ProgramStatus ReadUserInput(void)
{
    char command[maxsize] = {0};
    int character = 0;
    int count = 0;

    while ((character = getchar()) != '\n' && character != ' ' && count < maxsize)
    {
        command[count] = character;
        count++;
    }

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

enum ProgramStatus ReadCoefficients( struct Equation * coefficient)
{

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

