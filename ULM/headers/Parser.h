#ifndef ULM_PARSER_H
#define ULM_PARSER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

#include "Token.h"
#include "Types.h"

// Parser Result
enum _ulm_parser_status_e {
  PARSER_SUCCESS,
  PARSER_SYNTAX_ERROR,
};

typedef enum _ulm_parser_status_e _ulm_parser_status;

// Parser Methods
_ulm_parser_status _ulm_parser_init(_ulm_token_array* _token_array, const char* cSource);
int32_t _ulm_parser_signed_int(const char* _buf);
uint32_t _ulm_parser_unsigned_int(const char* _buf);
_ulm_token_inst _ulm_parser_instruction(const char* _buf);

#endif // ULM_PARSER_H