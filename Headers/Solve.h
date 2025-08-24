#ifndef SOLVE_H
    #define SOLVE_H

    enum EquationType
    {
        EQUATION_TYPE_TWO_ROOTS = 0,
        EQUATION_TYPE_NOSOLUTION = 1,
        EQUATION_TYPE_ONE_ROOT = 2,
        EQUATION_TYPE_LINEAR = 3,
        EQUATION_TYPE_ERROR = -1
    };

    struct Equation
    {
        float a;
        float b;
        float c;
    };

    struct Solution
    {
        enum EquationType solution_type;
        float solution_1;
        float solution_2;
    };
#endif
