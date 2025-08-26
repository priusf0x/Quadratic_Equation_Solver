#ifndef SOLVE_H
#define SOLVE_H

/// @brief Type of equation
enum EquationType
{
    EQUATION_TYPE_TWO_ROOTS = 0,
    EQUATION_TYPE_ONE_ROOT = 1,
    EQUATION_TYPE_NO_ROOTS = 2,
    EQUATION_TYPE_LINEAR = 3,
    EQUATION_TYPE_INFINITY = 4,
    EQUATION_TYPE_UNSOLVABLE = 5
};

/// @brief Includes *double* type coefficients of sqr. equation
struct Equation
{
    double a;
    double b;
    double c;
};

/// @brief Struct for ouput of Calculation function
struct Solution
{
    enum EquationType solution_type;
    double solution_1;
    double solution_2;
};

#endif
