#ifndef SCAN_H
#define SCAN_H
    #include "Calculation.h"
    #include "Program.h"

    void ClearBuffer();

    enum ProgramStatus ReadUserInput(void);
    enum ProgramStatus ReadCoefficients( struct Equation * coefficient);
#endif
