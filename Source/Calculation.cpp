#include "Calculation.h"

#include <math.h>

#include "Assert.h"
#include "Assert.h"
#include "Float.h"
#include "Logger.h"

struct Solution SolveQuadraticEquation(struct Equation * coefficient)
{
    ASSERT(coefficient != NULL);

    double coefficient_a = coefficient->a;
    double coefficient_b = coefficient->b;
    double coefficient_c = coefficient->c;

    double discriminant =  coefficient_b * coefficient_b  - 4 * coefficient_a * coefficient_c;
    struct Solution out = {.solution_type = EQUATION_TYPE_NO_ROOTS, .solution_1 = 0, .solution_2 = 0};

    if (IsOK(coefficient_a) && IsOK(coefficient_a) && IsOK(coefficient_c))
    {
        if (!IsZero(coefficient_a))
        {
            SolveSquareCase(&out, coefficient_a, coefficient_b, discriminant);
        }
        else if (IsZero(coefficient_a) && IsZero(coefficient_b) && IsZero(coefficient_c))
        {
            out.solution_type = EQUATION_TYPE_INFINITY;
        }
        else
        {
            SolveLinearCase(&out, coefficient_b, coefficient_c);
        }
    }
    else
    {
        out.solution_type = EQUATION_TYPE_UNSOLVABLE;
    }

    if (IsZero(out.solution_1))
    {
        out.solution_1 = fabs(out.solution_1);
    }
    if (IsZero(out.solution_2))
    {
        out.solution_2 = fabs(out.solution_2);
    }

    return out;
}


bool IsOK(double number_double)
{
    return !(isnan(number_double) ||  isinf(number_double) || fabs(number_double) > max_input_amount);
}

void SolveSquareCase(struct Solution * out, double coefficient_a,  double coefficient_b, double discriminant)
{
    if (fabs(discriminant) < EPSILON)
    {
        out->solution_type = EQUATION_TYPE_ONE_ROOT;
        out->solution_1 = (-coefficient_b) / 2 / coefficient_a;
        out->solution_2 = (-coefficient_b) / 2 / coefficient_a;
    }
    else if (discriminant > 0)
    {
        double sqrt_D = sqrt(discriminant);
        out->solution_type = EQUATION_TYPE_TWO_ROOTS;
        out->solution_1 = (-coefficient_b + sqrt_D) / 2 / coefficient_a;
        out->solution_2 = (-coefficient_b - sqrt_D) / 2 / coefficient_a;
    }
    else if (discriminant < 0)
    {
        out->solution_type = EQUATION_TYPE_NO_ROOTS;
    }
}

void SolveLinearCase(struct Solution * out, double coefficient_b, double coefficient_c)
{
    ASSERT(out != NULL);

    out->solution_type = EQUATION_TYPE_LINEAR;
    out->solution_1 = (-coefficient_c) / coefficient_b;
    out->solution_2 = out->solution_1;
}




