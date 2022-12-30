#include "../headers/Parser.h"
#include "../headers/ParserHints.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void _ulm_parser_init(
_ulm_token_array* _token_array,
char* cSource) {
  char _lexBuffer[256];
  int _nLexIndex = 0;
  int _nSourceIndex = 0;
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
    if (strcmp(_lexBuffer, _ULM_ASM_INSTRUCTION_PUSH) == 0) {
      _ulm_token ulmNewToken = _ulm_new_token();
      _ulm_token_array_add(_token_array, ulmNewToken);
    }
  }

}
