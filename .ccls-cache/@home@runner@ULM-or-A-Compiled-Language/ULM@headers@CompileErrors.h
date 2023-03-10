#ifndef ULM_COMPILE_ERRORS_H
#define ULM_COMPILE_ERRORS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// User Errors
#define ULM_DASHC_TOO_FEW_ARGS_F "[ULMVM] Too Few Compile Arguments!"
#define ULM_SYNTAX_NULL_INSTRUCTION_F "[ULMVM] <Syntax Error> No such instruction"
// Source errors
#define ULM_SRCERROR_MEMORYALLOCATION_F "[ULMVM] <SRCERROR> Memory Allocation Error"

#define ULM_SRCERROR_FILENOTAVAILABLE_F "[ULMVM] <SRCERROR> Could not open file"


#endif // ULM_COMPILE_ERRORS_H