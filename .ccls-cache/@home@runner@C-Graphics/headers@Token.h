#ifndef _ulmtoken_TOKEN_H
#define _ulmtoken_TOKEN_H
#include <stdio.h> 
#include <string.h>

#define CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOP"

#define INTV "_i"
#define UINTV "_u"
#define LONGV "_l"
#define FLOATV "_f"

struct _ulmtoken_TOKEN {
  char type[2];
  int _mutable;

  signed int INT_VALUE;
  unsigned int UINT_VALUE;
  unsigned long LONG_VALUE;
  float FLOAT_VALUE;
};
struct _ulmtoken_TOKEN _ulmtoken_intToken(signed int _value) {
  struct _ulmtoken_TOKEN _token;
  _token.INT_VALUE = (signed int)_value;
  _token.UINT_VALUE = 0u;
  _token.LONG_VALUE = 0l;
  _token.FLOAT_VALUE = 0.0f;
  strcpy(_token.type, INTV);
  return _token;
}
struct _ulmtoken_TOKEN _ulmtoken_uintToken(unsigned int _value) {
  struct _ulmtoken_TOKEN _token;
  _token.INT_VALUE = 0;
  _token.UINT_VALUE = (unsigned int)_value;
  _token.LONG_VALUE = 0l;
  _token.FLOAT_VALUE = 0.0f;
  strcpy(_token.type, UINTV);
  return _token;
}
struct _ulmtoken_TOKEN _ulmtoken_longToken(unsigned long _value) {
  struct _ulmtoken_TOKEN _token;
  _token.INT_VALUE = 0;
  _token.UINT_VALUE = 0u;
  _token.LONG_VALUE = (unsigned long)_value;
  _token.FLOAT_VALUE = 0.0f;
  strcpy(_token.type, UINTV);
  return _token;
}
struct _ulmtoken_TOKEN _ulmtoken_floatToken(float _value) {
  struct _ulmtoken_TOKEN _token;
  _token.INT_VALUE = 0;
  _token.UINT_VALUE = 0u;
  _token.LONG_VALUE = 0l;
  _token.FLOAT_VALUE = (float)_value;
  strcpy(_token.type, UINTV);
  return _token;
}
#endif