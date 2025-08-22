#include <stdio.h>
#include "StructInfo.h"
#include "Scan.h"
#include "Print.h"
#include "Calculation.h"

int main(void)
{
    struct calculator_output_s output = {.solution_type = ERROR, .solution_1 = 0, .solution_2 = 0};
    struct equation Coefficient = {.a = 0.0,.b = 0.0,.c = 0.0};

    PrintHelloMessage();
    ScanCoefficients(&Coefficient);

    output = SolveQuadraticEquation(Coefficient);

    Output(output);

    return 0;
}
