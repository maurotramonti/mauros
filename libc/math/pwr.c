#include <math.h>

uint32_t pwr(uint32_t base, uint32_t esponent) {
  uint32_t result = base;
  if (esponent == 0) return 1;
  if (esponent == 1) return base;
  for (int i = 1; i < esponent; i++) {
    result = result * base;
  }
  return result;
}
