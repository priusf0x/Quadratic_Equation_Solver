const double EPSILON = 1e-4;

bool IsNull(float x);

bool IsNull(float x)
{
    if (x < EPSILON)
    {
        return true;
    }
    else
    {
        return false;
    }
}
