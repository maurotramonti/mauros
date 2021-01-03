#include <string.h>


char* strcpy(char* dest, const char* src) {
  for (int i = 0; src[i] != '\0'; i++) dest[i] = src[i];
  return dest;
}
