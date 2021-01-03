#ifndef _STDIO_H
#define _STDIO_H 1

#include <sys/cdefs.h>
#include <stdint.h>

#define EOF (-1)

#ifdef __cplusplus
extern "C" {
#endif

int printf(const char* __restrict, ...);
int putchar(int);
int puts(const char*);

uint8_t inb (uint16_t port);
void outb (uint16_t port, uint8_t data);

#ifdef __cplusplus
}
#endif

#endif
