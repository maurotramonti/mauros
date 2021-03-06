#ifndef _STRING_H
#define _STRING_H 1

#include <sys/cdefs.h>

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int memcmp(const void*, const void*, size_t);
void* memcpy(void* __restrict, const void* __restrict, size_t);
void* memmove(void*, const void*, size_t);
void* memset(void*, int, size_t);

size_t strlen(const char*);

void strempty(char* str);

char* itoa(int n);
uint32_t atoi(const char*);

char* strcpy(char* dest, const char* src);
char* strncpy(char* dest, const char* src, size_t n);

int strcmp(const char* s1, const char* s2);
int strncmp(const char* s1, const char* s2, int n);

#ifdef __cplusplus
}
#endif

#endif
