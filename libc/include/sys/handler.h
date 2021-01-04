#ifndef _HANDLER_H
#define _HANDLER_H 1

#include <stdint.h>

void cli_keyboard_handler();

void timer_handler();
uint32_t timer_get_ticks();

#endif
