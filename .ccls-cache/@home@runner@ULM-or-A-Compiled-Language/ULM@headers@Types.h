#ifndef ULM_TYPES_H
#define ULM_TYPES_H
#include <stdio.h>
#include <stdlib.h> 
#include <stdint.h>

// Easier types, less writing, lazyness 100
enum _ulm_token_type {
  INSTRUCTION, 
  SIGNED_INT,
  UNSIGNED_INT,
};

enum _ulm_token_inst_e {
  PUSH, 
  ADD,
  HALT,
};
typedef enum _ulm_token_inst_e _ulm_token_inst;

#endif // ULM_TYPES_H