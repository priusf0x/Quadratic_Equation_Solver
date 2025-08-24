#ifndef fabs
    #include <math.h>
#endif


const double EPSILON = 1e-4;

bool IsNull(double x);

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
