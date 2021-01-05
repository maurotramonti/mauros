#include <debug.h>
#include <kernel/tty.h>
#include <stdio.h>

void put_int(const char* msg) {
  size_t y;
  y = terminal_get_coord(1);

  terminal_putentryat('[', vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK), 0, y);
  terminal_putentryat('I', vga_entry_color(VGA_COLOR_LIGHT_RED, VGA_COLOR_BLACK), 1, y);
  terminal_putentryat('N', vga_entry_color(VGA_COLOR_LIGHT_RED, VGA_COLOR_BLACK), 2, y);
  terminal_putentryat('T', vga_entry_color(VGA_COLOR_LIGHT_RED, VGA_COLOR_BLACK), 3, y);
  terminal_putentryat(']', vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK), 4, y);
  terminal_set_coord(6, y);
  printf(msg);
}
