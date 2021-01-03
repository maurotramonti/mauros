#include <cursor.h>
#include <stdio.h>

void update_cursor(int col, int row) {
	uint16_t pos = row * 80 + col;

	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}
