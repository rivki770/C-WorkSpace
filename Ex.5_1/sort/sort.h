#ifndef _SORT
#define _SORT

#include <stdio.h>
#include <string.h>

typedef unsigned int size_t;

typedef struct Dog_t
{
    char name[20];
    size_t kg;

} Dog;

void toPrint(Dog dogArr[], size_t size);

void sortByName(Dog *dogArr, size_t size);

void sortByKg(Dog *dogArr, size_t size);

void swap(Dog *dog1, Dog *dog2);

#endif // !_SORT
