#include "Sort.h"

void toPrint(Dog dogArr[], size_t size)
{
    for (size_t index = 0; index < size; index++)
    {
        printf("Dog %d: Name = %s, Kg = %d \n", index + 1, dogArr[index].name, dogArr[index].kg);
    }
    printf("\n");
}

void sortByName(Dog *dogArr, size_t size)
{
    //Dog temp;
    size_t i, changed;
    do
    {
        changed = 0;
        for (i = 0; i < size - 1; ++i)
        {
            if (strcmp(dogArr[i].name, dogArr[i + 1].name) > 0)
            {
                swap(&dogArr[i], &dogArr[i + 1]);
                changed = 1;
            }
        }
    } while (changed != 0);
}

void sortByKg(Dog *dogArr, size_t size)
{
    size_t mini;

    if (dogArr)
    {
        for (size_t i = 0; i < size - 1; i++)
        {
            mini = i;
            for (size_t j = i + 1; j < size; j++)
            {
                if (dogArr[j].kg < dogArr[mini].kg)
                    mini = j;
            }
            swap(&dogArr[mini], &dogArr[i]);
        }
    }
}

void swap(Dog *dog1, Dog *dog2)
{
    Dog temp = *dog1;
    *dog1 = *dog2;
    *dog2 = temp;
}