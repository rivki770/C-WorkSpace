#ifndef _PRINTS
#define _PRINTS

#include <stdio.h>
#include <limits.h>

typedef unsigned int size_t;

void PrintHexBytes(void *ptr, size_t size);

void PrintBits(void *ptr, size_t size);

#endif // !_PRINTS

