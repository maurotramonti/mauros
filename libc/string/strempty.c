#include <string.h>

void strempty(char* str) {
  for (size_t i = 0; str[i] != '\0'; i++) str[i] = '\0';
}
