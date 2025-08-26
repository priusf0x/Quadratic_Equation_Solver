#include "../Headers/Float.h"

bool IsZero(double x) // IsZero()
{
    if (fabs(x) < EPSILON)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double Max(double x, double y)
{
    return (x > y) ? x : y;
}

double Min(double x, double y)
{
    return (x < y) ? x : y;
}
