#include "sort.h"

//#define typeSort sortByName
#define typeSort sortByAge

int main()
{
    Dog dogArr[] = { {"Mush", 50}, {"Kika", 32}, {"Bobi", 48}, {"Luna", 15} };
    size_t size = sizeof(dogArr) / sizeof(dogArr[0]);
    toPrint(dogArr, size);

    qsort(dogArr, size, sizeof(Dog), typeSort);
    toPrint(dogArr, size);

    Dog *item;
    Dog inputDog;

    if (typeSort == sortByName)
    {
        printf("Input name to be searched: ");
        scanf_s("%s", inputDog.name, sizeof(inputDog.name));
        inputDog.name[0] = toupper(inputDog.name[0]);
        item = (Dog*)bsearch(&inputDog, dogArr, size, sizeof(Dog), typeSort);
        if (item != NULL) {
            printf("\n--- The age of %s dog: %d ---\n", inputDog.name, item->kg);
            return 0;
        }
        printf("\n--- The name %s does not exist ---\n", inputDog.name);
    }
    else
    {
        printf("Input age to be searched: ");
        scanf_s("%d", &inputDog.kg);
        item = (Dog *) bsearch(&inputDog, dogArr, size, sizeof(Dog), typeSort);
        if (item != NULL) {
            printf("\n--- The name dog of age %d: %s ---\n", inputDog.kg, item->name);
            return 0;
        }
        printf("\n--- The age %d does not exist ---\n", inputDog.kg);
    }
    return 0;
}