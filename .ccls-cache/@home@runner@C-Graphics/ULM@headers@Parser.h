#ifndef ULM_PARSER_H
#define ULM_PARSER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Token.h"

void _ulm_parser_init(_ulm_token_array* _token_array, char* cSource);

#endif // ULM_PARSER_H