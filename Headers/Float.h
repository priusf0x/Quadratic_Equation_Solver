#ifndef FLOAT_H

    #ifndef fabs
        #include <math.h>
    #endif

    #define FLOAT_H

    const double EPSILON = 1e-4;

    bool IsNull(double x);

    double max(double x, double y);

    double min(double x, double y);

#endif
