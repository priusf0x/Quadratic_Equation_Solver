#ifndef CALCULATION_H
#define CALCULATION_H
#include "Solve.h"
#include <math.h>

/**
 * @brief This is calculation function. It is the most important function in the program
 * @param [in] Coefficient *pointer* type with input data
 * @return New object with type *Solution*.
 * @warning Do not support Poltorashka
 */
struct Solution SolveQuadraticEquation(struct Equation * Coefficient);

/**
 * @brief Check if function is valid
 * @param [in] Coefficient *double* type
 * @return *Boolean* type, *true* if it is OK
 * @warning Дед, возьми в продву
 */
bool IsOK(double double_number);

/// @brief the maximum amount of input
const double max_input_amount = pow(2 , 30);
#endif
