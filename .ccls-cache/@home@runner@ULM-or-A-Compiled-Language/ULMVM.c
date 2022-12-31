#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// Includes
#include "ULM/headers/CompileErrors.h"
#include "ULM/headers/Util.h"
#include "ULM/headers/Token.h"
#include "ULM/headers/Parser.h"

// ULM -c file.ulm
int main(int argc, char** argv) { 
  if (argc < 2) {
    printf("%s\n", ULM_DASHC_TOO_FEW_ARGS_F);
    return 1;
  } 
  
  if (strcmp(argv[1], "-c") == 0) {
    int showLexerResults = (strcmp(argv[2], "-l") == 0)? 0:1;
    const char* file = (!showLexerResults)? argv[3]:argv[2];
    char* src = _ulm_get_file_contents(file);
    _ulm_token_array tokenArray;
    _ulm_token_array_new(&tokenArray, 1);
    
    _ulm_parser_status parsedResult = _ulm_parser_init(&tokenArray, src);
    if (parsedResult != PARSER_SUCCESS) return 1;
    for (int i = 0; i < tokenArray._nPtr; i++) {
      _ulm_token* t = _ulm_token_array_get(&tokenArray, i);
      if (showLexerResults == 0)
        
        printf("%d  %d  %d\n", 
          (int)t->_type, 
          (int)t->_nData, 
          (int)t->_nLine);
    }
    _ulm_token_array_drop(&tokenArray);
    free(src);
  }
  
  return 0;
}
