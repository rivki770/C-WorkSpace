#ifndef _SORT
#define _SORT

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned int size_t;

typedef struct Dog_t
{
    char name[20];
    size_t kg;

} Dog;

void toPrint(Dog dogArr[], size_t size);

int sortByName(const void *a, const void *b);

int sortByAge(const void *a, const void *b);
//
//int findDogByName(const void *a, const void *b);
//
//int findDogByAge(const void *a, const void *b);

#endif // !_SORT
