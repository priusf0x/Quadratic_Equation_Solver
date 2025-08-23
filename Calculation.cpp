#define NDEBUG
#include "StructInfo.h"
#include <math.h>
#include "Calculation.h"

//double CalcFastSqrt(double x)
//{
   // assert(x > 0);
//    return 1;
//}

// calloc malloc free
// NULL

// #define ifdef #

struct Solution SolveQuadraticEquation(struct Equation * coefficient)
{
   // assert(Coefficient != NULL);

    float coefficient_a = coefficient->a, coefficient_b = coefficient->b, coefficient_c = coefficient->c;
    float discriminant =  coefficient_b * coefficient_b  - 4 * coefficient_a * coefficient_c;
    float sqrt_D = sqrt(discriminant);
    struct Solution out = {.solution_type = EQUATION_TYPE_NOSOLUTION, .solution_1 = 0, .solution_2 = 0};

    if (fabs(coefficient_a) > EPSILON)
    {
        if (fabs(discriminant) < EPSILON)
        {
            out.solution_type = EQUATION_TYPE_ONE_ROOT;
            out.solution_1 = (-coefficient_b) / 2 / coefficient_a;
        }
        else if (discriminant > 0)
        {
            out.solution_type = EQUATION_TYPE_TWO_ROOTS;
            out.solution_1 = (-coefficient_b + sqrt_D) / 2 / coefficient_a;
            out.solution_2 = (-coefficient_b - sqrt_D) / 2 / coefficient_a;
        }
        else if (discriminant < 0)
        {
            out.solution_type = EQUATION_TYPE_NOSOLUTION;
        }
    }
    else if (fabs(coefficient_a) < EPSILON)
    {
        out.solution_type = EQUATION_TYPE_LINEAR;
    }
    else
    {
        out.solution_type = EQUATION_TYPE_ERROR;
    }
    return out;
}


