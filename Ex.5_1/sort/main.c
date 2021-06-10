#include "sort.h"

int main()
{
    Dog dogArr[] = { {"Mush", 50}, {"Kika", 32}, {"Bobi", 48}, {"Luna", 15} };
    size_t size = sizeof(dogArr) / sizeof(dogArr[0]);
    toPrint(dogArr, size);

    sortByName(dogArr, size);
    toPrint(dogArr, size);

    sortByKg(dogArr, size);
    toPrint(dogArr, size);
    return 0;
}