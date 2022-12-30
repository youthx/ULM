#include "../headers/Parser.h"
#include "../headers/ParserHints.h"
#include "../headers/Types.h"

// strd libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void _ulm_parser_init(
_ulm_token_array* _token_array,
char* cSource) {
  char _lexBuffer[256];
  int _nLexIndex = 0;
  int _nSourceIndex = 0;

  int _line = 1;
  // Lexer, and generates token
  while ((int)1) {
    memset(_lexBuffer, '\0', 256);
    while (
      cSource[_nSourceIndex] != '\n' &&
      cSource[_nSourceIndex] != ' ' &&
      cSource[_nSourceIndex] == '\0') {
      _nLexIndex++;
      _nSourceIndex++;
      _lexBuffer[_nLexIndex] = cSource[_nSourceIndex];
    }
    _lexBuffer[_nLexIndex] = '\0';

    // Lex Numerical Constants
    if (_lexBuffer[0] == _ULM_DT_SIGNED_INT) {
       int num = _ulm_parser_signed_int(_lexBuffer);
      _ulm_token_array_add(_token_array, _ulm_new_token(
        num, SIGNED_INT, _line
      ));
    } else if (_lexBuffer[0] == _ULM_DT_UNSIGNED_INT) {
      int num = _ulm_parser_unsigned_int(_lexBuffer);
      _ulm_token_array_add(_token_array, _ulm_new_token(
        num, UNSIGNED_INT, _line
      ));
    }
    else {
      
    }
    _nLexIndex = 0;
    _nSourceIndex++;
  }

}
