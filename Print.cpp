#include <stdio.h>
#include "Print.h"
#include "StructInfo.h"

void PrintHelloMessage()
{
    printf(
        "\n\n       +# #*                                                                                \n"
        "       #. .#.                                                                               \n"
        "      ##   #=                                                                               \n"
        "      #:   *#        ######  *#####:  :**####**+  *##########.####  =####*                  \n"
        "     +#    :#       -###### =##=### ####*###*####+===*###==== #### ######                   \n"
        "     #+     #.      ###-###:##.###*#### -### .###+   ####    =###-##+####                   \n"
        "    .#      #*      ### #####:.###.##############   .###*    ######.+###:                   \n"
        "    ##      +#     *##* +###- *###   .-+###*-:      *###.   .#####  ####                    \n"
        "   .#:      .#                                                                              \n"
        " ###.        #= -##########################################################- #####=         \n"
        "             ##.#.                                                                          \n"
        "              ##.\n\n\n\n\n"
        "Hello, This is my quadratic equation calculator\n"
        "Hope you'll enjoy it. Enter coefficients \n");
}

void Output(struct calculator_output_s input)
{
    if (input.solution_type == TwoSolutions)
    {
        printf("Your equation has 2 solution: %.2f and %.2f.", input.solution_1, input.solution_2);
    }
    else if (input.solution_type == NoSolution)
    {
        printf("Your equation has no solution.");
    }
    else if (input.solution_type == OneSolution)
    {
        printf("Your equation has only 1 solution: %.2f.", input.solution_1);
    }
    else if (input.solution_type == ERROR)
    {
        printf("FATAL ERROR was occurred.");
    }

}
