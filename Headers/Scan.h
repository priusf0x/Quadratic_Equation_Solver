#ifndef SCAN_H
    #ifndef CALCULATION_H
        #include "Calculation.h"
    #endif

    #ifndef PROGRAM_H
        #include "Program.h"
    #endif

    #define SCAN_H

    enum ProgramStatus ReadUserInput(void);
    enum ProgramStatus ReadCoefficients( struct Equation * coefficient);
#endif
