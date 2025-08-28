#include "Float.h"

bool IsZero(double x)
{
    return (fabs(x) < EPSILON);
}

double Max(double x, double y)
{
    return (x > y) ? x : y;
}

double Min(double x, double y)
{
    return (x < y) ? x : y;
}
