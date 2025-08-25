#ifndef SCAN_H
#define SCAN_H

    #ifndef CALCULATION_H
        #include "Calculation.h"
    #endif

    #ifndef PROGRAM_H
        #include "Program.h"
    #endif


    enum ProgramStatus ReadUserInput(void);
    enum ProgramStatus ReadCoefficients( struct Equation * coefficient);
#endif
