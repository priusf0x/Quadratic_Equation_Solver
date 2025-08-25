#ifndef CALCULATION_H
#define CALCULATION_H
    #ifndef SOLVE_H
        #include "Solve.h"
    #endif
    /**
     * @brief This is calculation function. It is the most important function in the program
     * @param [in] Coefficient *pointer* type with input data
     * @return New object with type *Solution*.
     * @warning Do not support Poltorashka
     */
    struct Solution SolveQuadraticEquation(struct Equation * Coefficient);
#endif
