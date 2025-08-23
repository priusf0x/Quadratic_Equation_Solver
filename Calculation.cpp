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

struct calculator_output_s SolveQuadraticEquation(struct equation * Coefficient)
{
   // assert(Coefficient != NULL);

    float coefficient_a = Coefficient->a, coefficient_b = Coefficient->b, coefficient_c = Coefficient->c;
    float discriminant =  coefficient_b * coefficient_b  - 4 * coefficient_a * coefficient_c;
    float sqrt_D = sqrt(discriminant);
    struct calculator_output_s out = {.solution_type = NOSOLUTION, .solution_1 = 0, .solution_2 = 0};

    if (fabs(coefficient_a) > EPSILON)
    {
        if (fabs(discriminant) < EPSILON)
        {
            out.solution_type = ONESOLUTION;
            out.solution_1 = (-coefficient_b) / 2 / coefficient_a;
        }
        else if (discriminant > 0)
        {
            out.solution_type = TWOSOLUTIONS;
            out.solution_1 = (-coefficient_b + sqrt_D) / 2 / coefficient_a;
            out.solution_2 = (-coefficient_b - sqrt_D) / 2 / coefficient_a;
        }
        else if (discriminant < 0)
        {
            out.solution_type = NOSOLUTION;
        }
    }
    else if (fabs(coefficient_a) < EPSILON)
    {
        out.solution_type = LINEAR;
    }
    else
    {
        out.solution_type = ERROR;
    }
    return out;
}


