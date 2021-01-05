#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H 1

#include <stddef.h>
#include <stdint.h>

#include "../../kernel/arch/i386/vga.h"

size_t terminal_get_coord(int coord);
void terminal_set_coord(int x, int y);

void terminal_initialize(void);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);
void terminal_writestring(const char* data);

void terminal_putentryat(unsigned char c, uint8_t color, size_t x, size_t y);
void terminal_writestring_color(const char* str, uint8_t color);

//void monitor_write_hex(uint32_t n);

#endif
