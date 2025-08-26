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
        return PROGRAM_STATE_BUFFER_OVERFLOW;
    }
    if (strcmp(command, "quit") == 0) //ANCHOR -  strncmp ANCHOR v chem problema
    {
        return CheckIfSpaces(PROGRAM_STATE_EXIT, character);
    }
    else if (strcmp(command, "solve") == 0)
    {
        return PROGRAM_STATE_SOLVE;
    }
    else if (strcmp(command, "help") == 0)
    {
        return CheckIfSpaces(PROGRAM_STATE_HELP, character);
    }
    else if (strcmp(command, "createtest") == 0)
    {
        return CheckIfSpaces(PROGRAM_STATE_TEST_CREATE, character);
    }
    else if (strcmp(command, "test") == 0)
    {
        return CheckIfSpaces(PROGRAM_STATE_TEST, character);
    }
    else
    {
        printf(RED "Incorrect Input\n" STANDARD);
        ClearBuffer(character);
        return PROGRAM_STATE_MENU;
    }

}

enum ProgramState ReadCoefficients(struct Equation * coefficient)
{
    ASSERT(coefficient != NULL);
    int character = 0;

    if (scanf("%lf %lf %lf", &(coefficient->a), &(coefficient->b), &(coefficient->c)) != 3)
    {
        printf(RED "Incorrect Input\n" STANDARD);
        ClearBuffer(character);
        return PROGRAM_STATE_MENU;
    }
    else
    {
        while((character = getchar()) != '\n')
        {
            if (character != ' ')
            {
                printf(RED "Incorrect Input\n" STANDARD);
                ClearBuffer(character);
                return PROGRAM_STATE_MENU;
            }
            character = getchar();        }
        return PROGRAM_STATE_CALCULATION;
    }
}

void ClearBuffer(int character)
{
    while (character != '\n' && character != EOF)
    {
        character = getchar();
    }
}

enum ProgramState CheckIfSpaces(enum ProgramState expected_state, int character)
{
    while (character != '\n')
        {
            character = getchar();
            if (character != ' ')
            {
                printf(RED "Incorrect Input\n" STANDARD);
                ClearBuffer(character);
                return PROGRAM_STATE_MENU;
            }
        }
    return expected_state;
}


