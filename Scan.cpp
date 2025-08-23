#include <stdio.h>
#include <ctype.h>
#include "Scan.h"
#include "StructInfo.h" b

// local snake_case
bool ScanCoefficients(struct equation * Coefficient, bool * end_flag)
{
    int character = '\n';
    int input_flag = false;
    if (scanf("%f %f %f", &(Coefficient->a), &(Coefficient->b), &(Coefficient->c)) != 3 )
    {
        input_flag = true;

        if ((character = getchar()) == 'q')
        {
            * end_flag = true;
            input_flag = false;
        }

        while ((character = getchar()) != '\n')
        {
            continue;
        }
    }
    else
    {
        while ((character = getchar()) != '\n')
        {
            if (!(isdigit(character) || character == '.' || character == ' '))
            {
                input_flag = true;
            }
        }
    }
    return input_flag;
}
