#include <stdio.h>

// Program.h
enum ProgramStatus
{
    PROGRAM_STATUS_MENU,
    PROGRAM_STATUS_EXIT,
    PROGRAM_STATUS_SOLVE,
    PROGRAM_STATUS_ERROR,
    PROGRAM_STATUS_CALCULATION,
    PROGRAM_STATUS_HELP
};

// Solve.h
enum EquationType
{
    EQUATION_TYPE_TWO_ROOTS = 0,
    EQUATION_TYPE_NOSOLUTION = 1,
    EQUATION_TYPE_ONE_ROOT = 2,
    EQUATION_TYPE_LINEAR = 3,
    EQUATION_TYPE_ERROR = -1
};

// Solve.h
struct Equation
{
    float a;
    float b;
    float c;
};

// Solve.h
struct Solution
{
    enum EquationType solution_type;
    float solution_1;
    float solution_2;
};

// Float.h IsZero ...
const double EPSILON = 1e-4;

// Program.h
const int maxsize = 100;

// Assert.h
#ifndef DEBUG
    #define ASSERT(X) \
    if (X) { printf("ERROR(" #X ") in %d line in file %s", __LINE__, __FILE__); exit(0); } // abort()
#else
    #define ASSERT(X)
#endif

