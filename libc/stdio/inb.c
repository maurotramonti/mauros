#include <stdio.h>
#include <stdint.h>


uint8_t inb (uint16_t port) {
    uint8_t result;
    asm("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}
