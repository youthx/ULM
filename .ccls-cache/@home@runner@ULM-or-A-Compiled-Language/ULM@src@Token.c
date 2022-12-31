#include "../headers/Token.h"
#include <stdio.h> 
#include <stdlib.h>

// New Token
_ulm_token* _ulm_new_token(
int _data,
int _type,
int _line) {
  _ulm_token* t = (_ulm_token*)malloc(sizeof(_ulm_token));
  t->_nLine = _line;
  t->_nData = _data;
  t->_type = _type;
  return t;
}

// New token array
void _ulm_token_array_new(
_ulm_token_array* _ref,
int _size
) {
  _ref->_nSize = _size;
  _ref->_token_data = (_ulm_token**)malloc(sizeof(_ulm_token*) * _size);
  _ref->_nPtr = 0;
}

// Get element at index in token array
_ulm_token* _ulm_token_array_get(_ulm_token_array* _token_array, int _index) {
  return (_ulm_token*)_token_array->_token_data[_index];
}

// Append to the token array
void _ulm_token_array_add(
_ulm_token_array* _token_array,
_ulm_token* _token) {
  if (_token_array->_nPtr >= _token_array->_nSize) {
    // Allocate more memory
    _token_array->_nSize*=2;
    int nSize = sizeof(_ulm_token_array*)*_token_array->_nSize;
    _token_array->_token_data =  (_ulm_token**)realloc(_token_array->_token_data, nSize);
    
  unsigned int index = (unsigned int)_token_array->_nPtr++;
  _token_array->_token_data[index] = _token;
  }
  else {
    _token_array->_token_data[_token_array->_nPtr++] = _token;
  }
}



void _ulm_token_array_drop(
_ulm_token_array* _token_array
) {
  for (int i = 0; i < _token_array->_nPtr; i++) {
    free(_token_array->_token_data[i]);
  }
  free(_token_array->_token_data);
}