#ifndef _CURSOR_H
#define _CURSOR_H 1

#include <stdint.h>

void update_cursor(int col, int row);
void enable_cursor(uint8_t cursor_start, uint8_t cursor_end);
void disable_cursor();

#endif
