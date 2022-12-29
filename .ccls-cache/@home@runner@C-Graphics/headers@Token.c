#include "Token.h"

intToken _intToken(signed int _value) {
  intToken* token;
  token->type = TokenType::INT;
  token->value = _value;
  return *token;
}
uintToken _uintToken(unsigned int _value) {
  uintToken* token;
  token->type = TokenType::UINT;
  token->value = _value;
  return *token;
}

longToken _longToken(unsigned long _value) {
  longToken* token;
  token->type = TokenType::LONG;
  token->value = _value;
  return *token;
}

chrToken _charToken(char _value) {
  chrToken* token;
  token->type = TokenType::CHAR;
  token->value = _value;
  return *token;
}

