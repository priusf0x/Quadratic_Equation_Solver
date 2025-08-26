#ifndef FLOAT_H
#define FLOAT_H

#include <math.h>

/// @brief Constant for comparison with Null
const double EPSILON = 1e-2;

/**
 * @brief Function for checking if argument is Null
 * @param [in] x *double* type argument
 * @return *boolean* expression.
 */
bool IsZero(double x);

/**
 * @brief The most common max() function
 * @param [in] x *double* type argument
 * @param [in] y *double* type argument
 * @return the biggest *double* type number from arguments
 */

double Max(double x, double y);

/**
 * @brief The most common min() function
 * @param [in] x *double* type argument
 * @param [in] y *double* type argument
 * @return the least *double* type number from arguments
 */

double Min(double x, double y);
#endif
