#include <stdio.h>
#include <ctype.h>
#include "StructInfo.h"
#include "Scan.h"

void ClearBuffer(void);

void ClearBuffer(void)
{
    while (getchar() != '\n')
    {
        continue;
    }
}

enum ProgramStatus ReadUserInput(void)
{
    int command[maxsize] = {0}; // make constant
    int character = 0; // initialize
    int count = 0;

    while ((character = getchar()) != '\n' && character != ' ' && count < maxsize)
    {
        command[count] = character;
        count++;
    }

    if (count == 4)
    {
        if (command[0] == 'q' && command[1] == 'u' && command[2] == 'i' && command[3] == 't')
        {
            return PROGRAM_STATUS_EXIT;
        }
        else
        {
            printf("Incorrect Input\n");
            return PROGRAM_STATUS_MENU;
        }
    }
    else if (count == 5)
    {
        if (command[0] == 's' && command[1] == 'o' && command[2] == 'l' && command[3] == 'v' && command[4] == 'e')
        {
            return PROGRAM_STATUS_SOLVE;
        }
        else
        {
            printf("Incorrect Input\n");
            return PROGRAM_STATUS_MENU;
        }
    }
    else
    {
        printf("Incorrect Input\n");
        return PROGRAM_STATUS_MENU;
    }
}

enum ProgramStatus ReadCoefficients( struct Equation * coefficient)
{
    // assert

    int character = '\n';

    if (scanf("%f %f %f", &(coefficient->a), &(coefficient->b), &(coefficient->c)) != 3)
    {
        printf("Incorrect Input\n");
        ClearBuffer();
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

