#include "../headers/Util.h"
#include "../headers/CompileErrors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bad Practice, don't do this. 
// I am a bad programmer so it is okay for me to do.
char* _ulm_get_file_contents(const char* path) {
  FILE* fSource = fopen(path, "r");
  if (!fSource) {
    printf("%s `%s`\n", ULM_SRCERROR_FILENOTAVAILABLE_F, path);
    return NULL;
  }
  // Get the file size as an integer
  fseek(fSource, 0, SEEK_END);
  int nSize = ftell(fSource);
  fseek(fSource, 0, SEEK_SET);

  // Write to a buffer
  char* cBuf = (char*)malloc((1+nSize)*sizeof(char));
  if (!cBuf) {
    printf("%s\n (Util.c, line 23)\n", ULM_SRCERROR_MEMORYALLOCATION_F);
    fclose(fSource);
    return NULL;
  }
  fread(cBuf, 1, nSize, fSource);
  fclose(fSource);
  cBuf[nSize] = '\0';
  return cBuf;
}
