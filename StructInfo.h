enum EQUATION_TYPES
    {
    TwoSolutions = 0,
    NoSolution = 1,
    OneSolution = 2,
    ERROR = -1
    };

struct equation
{
    float a;
    float b;
    float c;
};

struct calculator_output_s
{
    enum EQUATION_TYPES solution_type;
    float solution_1;
    float solution_2;
};
