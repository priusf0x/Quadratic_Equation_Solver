enum equation_types // EquationType
{
    // EQUATION_TYPE_TWO_ROOTS
    // EQUATION_TYPE_ONE_ROOT,
    // EQUATION_TYPE_LINEAR
    //
    TWOSOLUTIONS = 0,
    NOSOLUTION = 1,
    ONESOLUTION = 2,
    LINEAR = 3,
    ERROR = -1
};


#define EPSILON 1e-4 // const

struct equation // Equation
{
    float a;
    float b;
    float c;
};

struct calculator_output_s // Solution
{
    enum equation_types solution_type;
    float solution_1;
    float solution_2;
};
