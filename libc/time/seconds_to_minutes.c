#include <time.h>
#include <string.h>

void seconds_to_minutes(uint32_t seconds) {
  uint32_t final_seconds = seconds % 60;
  uint32_t minutes = (seconds - final_seconds) / 60;
  printf("%sm %ss\n", itoa(minutes), itoa(final_seconds));
}
