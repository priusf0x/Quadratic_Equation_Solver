#include "Headers/Float.h"

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
    if (x >= y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

double min(double x, double y)
{
    if (x <= y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
