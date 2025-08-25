#include <math.h>
#include "Headers/Calculation.h"
#include "Headers/Assert.h"
#include "Headers/Float.h"

struct Solution SolveQuadraticEquation(struct Equation * coefficient)
{
    double coefficient_a = coefficient->a, coefficient_b = coefficient->b, coefficient_c = coefficient->c;
    double discriminant =  coefficient_b * coefficient_b  - 4 * coefficient_a * coefficient_c;
    double sqrt_D = sqrt(discriminant);
    struct Solution out = {.solution_type = EQUATION_TYPE_NOSOLUTION, .solution_1 = 0, .solution_2 = 0};

    if (!IsNull(coefficient_a))
    {
        if (fabs(discriminant) < EPSILON)
        {
            out.solution_type = EQUATION_TYPE_ONE_ROOT;
            out.solution_1 = (-coefficient_b) / 2 / coefficient_a;
            out.solution_2 = (-coefficient_b) / 2 / coefficient_a;
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
    else if (IsNull(coefficient_a))
    {
        out.solution_type = EQUATION_TYPE_LINEAR;
    }
    else
    {
        out.solution_type = EQUATION_TYPE_ERROR;
    }
    if (IsNull(out.solution_1))
    {
        out.solution_1 = fabs(out.solution_1);
    }
    if (IsNull(out.solution_2))
    {
        out.solution_2 = fabs(out.solution_2);
    }
    return out;
}



