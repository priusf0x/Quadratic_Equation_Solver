#ifndef SCAN_H
#define SCAN_H

#include "Calculation.h"
#include "Program.h"

/// @brief Clears Buffer
void ClearBuffer();

/// @brief Reads User's input and change program state
enum ProgramStatus ReadUserInput(void);

/**
 * @brief Read input and put data in *Equation* struct
 * @param [in] coefficient *Equation * * type argument
 * @return *ProgramStatus* type.
 */
enum ProgramStatus ReadCoefficients(struct Equation * coefficient);

#endif // SCAN_H
