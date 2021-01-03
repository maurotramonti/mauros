#include <string.h>

int strcmp(const char* s1, const char* s2) {
  int i = 0;
  while (1) {
    if (s1[i] != s2[i]) return -1;
    if (s1[i] == '\0') break;
    i++;
  }
  return 0;
}
