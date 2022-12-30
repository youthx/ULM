#ifndef ULM_PARSER_H
#define ULM_PARSER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Token.h"
#include "Types.h"

void _ulm_parser_init(_ulm_token_array* _token_array, char* cSource);
signed int _ulm_parser_signed_int(char* _buf);
unsigned int _ulm_parser_unsigned_int(char* _buf);
_ulm_token_inst _ulm_parser_instruction(char* _buf);

#endif // ULM_PARSER_H