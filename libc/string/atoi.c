#include <string.h>
#include <math.h>


static int ctoi(const unsigned char c) {
  switch(c) {
    case '0':
      return 0;
      break;
    case '1':
      return 1;
      break;
    case '2':
      return 2;
      break;
    case '3':
      return 3;
      break;
    case '4':
      return 4;
      break;
    case '5':
      return 5;
      break;
    case '6':
      return 6;
      break;
    case '7':
      return 7;
      break;
    case '8':
      return 8;
      break;
    case '9':
      return 9;
      break;
    default:
      return -1;
      break;
  }
}

static void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

uint32_t atoi(const char* str) {
  reverse(str);
  size_t num_len = strlen(str);
  uint32_t result = 0;
  size_t i;
  for (i = 0; i < num_len; i++) if (ctoi(str[i]) == -1) return 0xBAD;
  for (i = 0; i < num_len; i++) {
    result = result + ctoi(str[i]) * pwr(10, i);
  }

  return result;
}
