#include <kernel/tty.h>
#include "../../kernel/arch/i386/vga.h"
#include <stdio.h>


void put_ok(const char* msg) {
  size_t y;
  y = terminal_get_coord(1);

  terminal_putentryat('[', vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK), 0, y);
  terminal_putentryat('O', vga_entry_color(VGA_COLOR_GREEN, VGA_COLOR_BLACK), 1, y);
  terminal_putentryat('K', vga_entry_color(VGA_COLOR_GREEN, VGA_COLOR_BLACK), 2, y);
  terminal_putentryat(']', vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK), 3, y);
  terminal_set_coord(5, y);
  printf(msg);
  terminal_putchar('\n');
}
