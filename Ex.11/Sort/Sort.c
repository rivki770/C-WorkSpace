#include "sort.h"

void toPrint(Dog dogArr[], size_t size)
{
    for (size_t index = 0; index < size; index++)
    {
        printf("Dog %d: Name = %s, Kg = %d \n", index + 1, dogArr[index].name, dogArr[index].kg);
    }
    printf("\n");
}

int sortByName(const void *a, const void *b) {

    Dog *dog_1 = (Dog *) a;
    Dog *dog_2 = (Dog *) b;
    return strcmp(dog_1->name, dog_2->name);
}

int sortByAge(const void *a, const void *b) {

    Dog *dog_1 = (Dog *) a;
    Dog *dog_2 = (Dog *) b;
    return (dog_1->kg - dog_2->kg);
}

//int findDogByName(const void *a, const void *b)
//{
//    const Dog *dog_1 = (Dog **) a;
//    const Dog *dog_2 = (Dog **) b;
//    return strcasecmp(dog_1->name, dog_2->name);
//}
//
//int findDogByAge(const void *a, const void *b)
//{
//    const Dog *dog_1 = (Dog **) a;
//    const Dog *dog_2 = (Dog **) b;
//    return strcasecmp(dog_1->kg, dog_2->kg);
//}