#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <cursor.h>
#include <kernel/tty.h>

#include "vga.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

static size_t terminal_row;
static size_t terminal_column;
static uint8_t terminal_color;
static uint16_t* terminal_buffer;

void terminal_initialize(void) {
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = VGA_MEMORY;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

static void scroll() {

       // Move the current text chunk that makes up the screen
       // back in the buffer by a line
       int i;
       for (i = 0; i < 24*80; i++)
       {
           terminal_buffer[i] = terminal_buffer[i+80];
       }

       // The last line should now be blank. Do this by writing
       // 80 spaces to it.
       for (i = 24*80; i < 25*80; i++)
       {
           terminal_buffer[i] = vga_entry(' ', terminal_color);
       }
       // The cursor should now be on the last line.
       terminal_row = 24;

}

void terminal_setcolor(uint8_t color) {
	terminal_color = color;
}

void terminal_putentryat(unsigned char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_putchar(char c) {
	unsigned char uc = c;
	if (uc == '\n') {
    if (++terminal_row == VGA_HEIGHT) {
			scroll();
		}
    terminal_column = 0;
    return;
  }

	if (uc == '\b') {
		if (--terminal_column == 0) {
			terminal_column = VGA_WIDTH;
			terminal_row--;
		}

		terminal_putentryat(' ', terminal_color, terminal_column, terminal_row);
		return;
	}
	if (terminal_column == 80) {
		terminal_putchar('\n');
	}
	terminal_putentryat(uc, terminal_color, terminal_column, terminal_row);
	if (++terminal_column == VGA_WIDTH) {
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT)
			scroll();
	}
	update_cursor(terminal_column, terminal_row);
}

void terminal_write(const char* data, size_t size) {
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}

void terminal_writestring(const char* data) {
	terminal_write(data, strlen(data));
}