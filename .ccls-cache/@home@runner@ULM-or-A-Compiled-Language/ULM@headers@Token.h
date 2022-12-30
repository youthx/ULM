#ifndef ULM_TOKEN_H
#define ULM_TOKEN_H
#include <stdio.h> 
#include <stdlib.h>

// ULM Token
struct _ulm_token_s {
  // Position
  int _nLine;

  // Token Attributes
  int _nData;
  int _nType; 
}; // Token Type
typedef struct _ulm_token_s _ulm_token;

// Create a token 
_ulm_token _ulm_new_token(
int _data,
int _type,
int _line);
// Destroy a token
void _ulm_rm_token(_ulm_token* _token);

// ULM Token Array
struct _ulm_token_array_s {
  // Token Array Data
  _ulm_token** _token_data;

  // Token Array Attributes
  int _nPtr;
  int _nSize;
}; // Token Array Type
typedef struct _ulm_token_array_s _ulm_token_array;

// Create a token array
_ulm_token_array _ulm_new_token_array(
int _size
);
// Destroy a token array
void _ulm_rm_token_array(_ulm_token_array* _token_array);

// Token Array methods
void _ulm_token_array_add(
_ulm_token_array* _token_array,
_ulm_token _token);

_ulm_token _ulm_token_array_get(
_ulm_token_array* _token_array,
int _index
);

#endif // ULM_TOKEN_H
