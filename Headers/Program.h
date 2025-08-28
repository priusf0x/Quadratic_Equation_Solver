#ifndef PROGRAM_H
#define PROGRAM_H

/// @brief The maximum size of buffer space
const int PROGRAM_INPUT_BUFFER_SIZE = 30;

/// @brief States of Program
enum ProgramState // Finite State Machine (ProgramState)
{
    PROGRAM_STATE_MENU,
    PROGRAM_STATE_EXIT,
    PROGRAM_STATE_SOLVE,
    PROGRAM_STATE_FILE_ERROR,
    PROGRAM_STATE_CALCULATION,
    PROGRAM_STATE_HELP,
    PROGRAM_STATE_TEST,
    PROGRAM_STATE_BUFFER_OVERFLOW,
    PROGRAM_STATE_TEST_CREATE
};

#endif
