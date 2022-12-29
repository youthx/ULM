#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// Includes
#include "ULM/headers/CompileErrors.h"
#include "ULM/headers/Util.h"

// ULM -c file.ulm
int main(int argc, char** argv) { 
  if (argc < 2) {
    printf("%s\n", ULM_DASHC_TOO_FEW_ARGS_F);
    return 1;
  } 
  if (strcmp(argv[1], "-c") == 0) {
    char* src = _ulm_get_file_contents(argv[2]);
    
    free(src);
  }
  return 0;
}