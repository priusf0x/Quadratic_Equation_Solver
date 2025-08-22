#include "StructInfo.h"
#include <math.h>
#include "Calculation.h"
#define EPSILON 1e-4

struct calculator_output_s SolveQuadraticEquation(struct equation Coefficient)
{
    float discriminant = Coefficient.b * Coefficient.b  - 4 * Coefficient.a * Coefficient.c;
    float sqrt_D = sqrt(discriminant);
    struct calculator_output_s out = {.solution_type = NoSolution, .solution_1 = 0, .solution_2 = 0};

    if (fabs(Coefficient.a) > EPSILON)
    {
        if (fabs(discriminant) < EPSILON)
        {
            out.solution_type = OneSolution;
            out.solution_1 = (-Coefficient.b) / 2 / Coefficient.a;
        }
        else if (discriminant > 0)
        {
            out.solution_type = TwoSolutions;
            out.solution_1 = (-Coefficient.b + sqrt_D) / 2 / Coefficient.a;
            out.solution_2 = (-Coefficient.b - sqrt_D) / 2 / Coefficient.a;
        }
        else if (discriminant < 0)
        {
            out.solution_type = NoSolution;
        }
    }
    else
    {
        out.solution_type = ERROR;
    }
    return out;
}


