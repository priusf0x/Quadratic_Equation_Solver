#include "../Headers/Flag.h"
#include "../Headers/Program.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../Headers/Test.h"
#include "../Headers/Print.h"
#include "../Headers/Color.h"

void ReadFlags(int argc, char **argv)
{
    int index = 0;
    enum ProgramState status = PROGRAM_STATE_TEST;
    for (index = 1; index < argc; index++)
        if ((strcmp(argv[index], "-h") == 0 || strcmp(argv[index], "--help") == 0))
        {
            PrintHelp();
        }
        else if ((strcmp(argv[index], "-t") == 0 || strcmp(argv[index], "--test") == 0))
        {
            TestCalculation(&status);
            if (status == PROGRAM_STATE_EXIT)
                return;
        }
        else
        {
            printf(RED "Incorrect Flag \n" STANDARD);
        }
}
