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

void Output(struct Solution input)
{
    switch (input.solution_type)
    {
    case EQUATION_TYPE_TWO_ROOTS:
        printf("Your equation has 2 solution: %.2f and %.2f.\n", input.solution_1, input.solution_2);
        break;
    case EQUATION_TYPE_NOSOLUTION:
        printf("Your equation has no solution.\n");
        break;
    case EQUATION_TYPE_ONE_ROOT:
        printf("Your equation has only 1 solution: %.2f.\n", input.solution_1);
        break;
    case EQUATION_TYPE_LINEAR:
        printf("Your equation is linear, put another data.\n");
        break;
    case EQUATION_TYPE_ERROR:
        printf("FATAL ERROR was occurred.\n");
        break;
    default:
        printf("Oops! Something happened with print function(\n");
        break;
    }
}
