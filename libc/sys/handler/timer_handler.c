#include <sys/handler.h>
#include <stdio.h>
#include <string.h>

static uint32_t tick = 0;

uint32_t timer_get_ticks() {
  return tick;
}

void timer_handler() {
  tick++;
}
