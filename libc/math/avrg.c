#include <math.h>
#include <stdarg.h>
#include <stddef.h>

uint32_t avrg(uint32_t tot_n, ...) {
  uint32_t nums[tot_n];
  uint32_t sum = 0;

  va_list parameters;
  va_start(parameters, tot_n);

  for (size_t i = 0; i < tot_n; i++) {
    nums[i] = va_arg(parameters, uint32_t);
  }

  for(size_t i = 0; i < tot_n; i++) {
    sum += nums[i];
  }

  return (uint32_t) sum / tot_n;
}
