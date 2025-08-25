#ifndef SOLVE_H

    #define SOLVE_H

    enum EquationType
    {
        EQUATION_TYPE_TWO_ROOTS = 0,
        EQUATION_TYPE_ONE_ROOT = 1,
        EQUATION_TYPE_NOSOLUTION = 2,
        EQUATION_TYPE_LINEAR = 3,
        EQUATION_TYPE_ERROR = -1
    };

    struct Equation
    {
        double a;
        double b;
        double c;
    };

    struct Solution
    {
        enum EquationType solution_type;
        double solution_1;
        double solution_2;
    };
#endif
