#include <kernel/tty.h>
#include "../../kernel/arch/i386/vga.h"
#include <stdio.h>


void put_dbg(const char* msg) {
  size_t y;
  y = terminal_get_coord(1);

  terminal_putentryat('[', vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK), 0, y);
  terminal_putentryat('D', vga_entry_color(VGA_COLOR_MAGENTA, VGA_COLOR_BLACK), 1, y);
  terminal_putentryat('E', vga_entry_color(VGA_COLOR_MAGENTA, VGA_COLOR_BLACK), 2, y);
  terminal_putentryat('B', vga_entry_color(VGA_COLOR_MAGENTA, VGA_COLOR_BLACK), 3, y);
  terminal_putentryat('U', vga_entry_color(VGA_COLOR_MAGENTA, VGA_COLOR_BLACK), 4, y);
  terminal_putentryat('G', vga_entry_color(VGA_COLOR_MAGENTA, VGA_COLOR_BLACK), 5, y);
  terminal_putentryat(']', vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK), 6, y);
  terminal_set_coord(8, y);
  printf(msg);
  terminal_putchar('\n');
}
