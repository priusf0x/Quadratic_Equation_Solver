#ifndef SCAN_H
#define SCAN_H

#include "Calculation.h"
#include "Program.h"

/// @brief Clears Buffer
void ClearBuffer(int character);

/// @brief Reads User's input and change program state
enum ProgramState ReadUserInput(void);

/**
 * @brief Read input and put data in *Equation* struct
 * @param [in] coefficient *Equation * * type argument
 * @return *ProgramStatus* type.
 */
enum ProgramState ReadCoefficients(struct Equation * coefficient);

enum ProgramState CheckIfSpaces(enum ProgramState expected_state, int character);

#endif // SCAN_H
