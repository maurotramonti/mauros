#include <kernel/tty.h>
#include "../../kernel/arch/i386/vga.h"
#include <stdio.h>


void put_fail(const char* msg) {
  size_t y;
  y = terminal_get_coord(1);

  terminal_putentryat('[', vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK), 0, y);
  terminal_putentryat('F', vga_entry_color(VGA_COLOR_RED, VGA_COLOR_BLACK), 1, y);
  terminal_putentryat('A', vga_entry_color(VGA_COLOR_RED, VGA_COLOR_BLACK), 2, y);
  terminal_putentryat('I', vga_entry_color(VGA_COLOR_RED, VGA_COLOR_BLACK), 3, y);
  terminal_putentryat('L', vga_entry_color(VGA_COLOR_RED, VGA_COLOR_BLACK), 4, y);
  terminal_putentryat(']', vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK), 5, y);
  terminal_set_coord(7, y);
  printf(msg);
  terminal_putchar('\n');
}
