#include "../Headers/Float.h"

bool IsNull(double x)
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

double max(double x, double y)
{
    return (x > y) ? x : y;
}

double min(double x, double y)
{
    return (x < y) ? x : y;
}
