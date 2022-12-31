#include "../headers/Parser.h"
#include "../headers/ParserHints.h"
#include "../headers/Token.h"
#include "../headers/Types.h"
#include "../headers/CompileErrors.h"
// strd libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Parser
// Convert the lex buffer to a signed int
int32_t _ulm_parser_signed_int(const char* _buf) {
  // TODO: Convert the lex buffer to a signed int
  return 0;
}

// Convert the lex buffer to an unsigned int
uint32_t _ulm_parser_unsigned_int(const char* _buf) {
  long _uint = (long)atoi(&_buf[1]);
  return (_uint <= UINT32_MAX)? _uint : 0;
}

// Compare the lex buffer to check if the token is a instruction
_ulm_token_inst _ulm_parser_instruction(const char* _buf) {
  if (strcmp(_buf, _ULM_ASM_INSTRUCTION_PUSH) == 0)    return PUSH;
  if (strcmp(_buf, _ULM_ASM_INSTRUCTION_POP)  == 0)    return POP;
  if (strcmp(_buf, _ULM_ASM_INSTRUCTION_ADD)  == 0)    return ADD;
  if (strcmp(_buf, _ULM_ASM_INSTRUCTION_HALT) == 0)    return HALT;
  return NULL_INST;
}

// Begin parsing
_ulm_parser_status _ulm_parser_init(
_ulm_token_array* _token_array,
const char* cSource) {
  char _lexBuffer[256];
  int _nLexIndex = 0;
  int _nSourceIndex = 0;

  int _line = 1;
  
  // Lexer, and generates token
  while ((int)1) {
    while (
      cSource[_nSourceIndex] != '\n' &&
      cSource[_nSourceIndex] != ' '  &&
      cSource[_nSourceIndex] != '\0') {

      _lexBuffer[_nLexIndex++] = cSource[_nSourceIndex++];
    }
    _lexBuffer[_nLexIndex] = '\0';
    // break if it is the end of the line
    if (_lexBuffer[0] == '\0') break;

    
    // Numerical Constants
    if (_lexBuffer[0] == _ULM_DT_UNSIGNED_INT) {
      // Create a new unsigned int token
      uint32_t num = (uint32_t)_ulm_parser_unsigned_int(_lexBuffer);
      _ulm_token_array_add(_token_array, _ulm_new_token(
        num, UNSIGNED_INT, _line ));
      printf("UNSIGNED INT: %d\n", num);
    } 
    else if (_lexBuffer[0] == _ULM_DT_SIGNED_INT) {
      // Create a new signed int token
       int32_t num = (int32_t)_ulm_parser_signed_int(_lexBuffer);
      _ulm_token_array_add(_token_array, _ulm_new_token(
        num, SIGNED_INT, _line ));
      printf("SIGNED INT: %d\n", num);
      
    } 
    else { // Instruction
      int _instruction = _ulm_parser_instruction(_lexBuffer);
      if (_instruction != NULL_INST) {
        // Case: valid instruction
        _ulm_token_array_add(_token_array, _ulm_new_token(
          _instruction, INSTRUCTION, _line ));
        printf("INSTRUCTION: %s\n", _lexBuffer);
      } else {
        // Case: Not a valid instruction (Syntax Error)
        printf("%s '%s' (Line %d)\n", 
          ULM_SYNTAX_NULL_INSTRUCTION_F,
          _lexBuffer,
          _line);
        return PARSER_SYNTAX_ERROR;
      }
    }

    // Reset & Update Indexes
    if(cSource[_nSourceIndex] == '\n') {
      _line++;
    } else if (cSource[_nSourceIndex] == '\0') {
      break;
    }
    _nLexIndex = 0;
    _nSourceIndex++;
  }
  return PARSER_SUCCESS;
}

