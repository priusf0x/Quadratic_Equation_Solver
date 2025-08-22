#include <stdio.h>
#include "Scan.h"
#include "StructInfo.h"

void ScanCoefficients(struct equation * Coefficient)
{
    int character = '\n';
    while (scanf("%f %f %f", &(Coefficient->a), &(Coefficient->b), &(Coefficient->c)) != 3 )
    {
        printf("Unable to read. Try again with correct Input \n");
        while ((character = getchar()) != '\n')
        {
            continue;
        }
    }
}
