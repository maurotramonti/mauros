#include <stdio.h>
#include <stdint.h>

void outb (uint16_t port, uint8_t data) {
    asm volatile("out %%al, %%dx" : : "a" (data), "d" (port));
}
