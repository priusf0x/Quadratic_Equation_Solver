#include <stdio.h>
#include "../Headers/Print.h"
#include "../Headers/Solve.h"
#include "../Headers/Color.h"
#include "../Headers/Float.h"

// argv argc

// ./Solver --file coeffs.txt
//
// Doxygen (style)
//
void PrintHelloMessage()
{
    printf(BLUE
        "\n\n       +# #*                                                                                \n"
        "       #. .#.                                                                               \n"
        "      ##   #=                                                                               \n"
        "      #:   *#        ######  *#####:  :**####**+  *##########.####  =####*                  \n"
        "     +#    :#       -###### =##=### ####*###*####+===*###==== #### ######                   \n"
        "     #+     #.      ###-###:##.###*#### -### .###+   ####    =###-##+####                   \n"
        "    .#      #*       ### #####:.###.##############   .###*    ######.+###:                   \n"
        "    ##      +#     *##* +###- *###   .-+###*-:      *###.   .#####  ####                    \n"
        "   .#:      .#                                                                              \n"
        " ###.        #= -##########################################################- #####=         \n"
        "             ##.#.                                                                          \n"
        "              ##.\n\n\n\n\n" WHITE
        "Hello, This is my quadratic equation calculator\n"
        "Hope you'll enjoy it. Enter coefficients: (to read manual type \"help\")\n" STANDARD );
}

void Output(struct Solution * input)
{
    switch (input->solution_type)
    {
    case EQUATION_TYPE_TWO_ROOTS:
        printf(WHITE "Your equation has 2 solution: %.2lf and %.2lf.\n" STANDARD, input->solution_1, input->solution_2);
        break;
    case EQUATION_TYPE_NO_ROOTS:
        printf(WHITE "Your equation has no solution.\n" STANDARD);
        break;
    case EQUATION_TYPE_ONE_ROOT:
        printf(WHITE "Your equation has only 1 solution: %.2lf.\n" STANDARD, input->solution_1);
        break;
    case EQUATION_TYPE_LINEAR:
        printf(WHITE "Your equation is linear and has only 1 solution: %.2lf.\n" STANDARD, input->solution_1);
        break;
    case EQUATION_TYPE_UNSOLVABLE:
        printf(RED "This calculator do not this types. Try another equation:\n");
        break;
    case EQUATION_TYPE_INFINITY:
        printf("Your equation has infinity solution.\n");
        break;
    default:
        printf(RED "Oops! Something happened with print function(\n" STANDARD);
        break;
    }
}

void PrintHelp()
{
    printf(WHITE "\n            HELP MENU\n\n"
           "To solve equation type \"solve\" command.\n"
           "EXAMPLE:  >>> solve [a] [b] [c] (a, b, c are\n"
           "coefficients in quadratic equation)\n\n"
           "To leave program type \"quit\" command.\n"
           "EXAMPLE:  >>> quit\n\n"
           "To enter help menu type \"help\".\n"
           "EXAMPLE:  >>> help\n\n"
           "To create unique tests type \"createtest\".\n"
           "EXAMPLE:  >>> createtest\n\n"
           "To create start tests type \"test\".\n"
           "EXAMPLE:  >>> test (if any test fails, it writes in the console)\n\n" STANDARD);
}
