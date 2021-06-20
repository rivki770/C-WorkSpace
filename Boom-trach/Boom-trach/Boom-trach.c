#include "Boom-trach.h"

void boomTrach(size_t choiceNumber)
{
    for (size_t i = 1; i <= choiceNumber; ++i)
    {
        if ((i % (BOOM * TRACH)) == 0)
        {
            printf("%s\n", "Boom-Trach");
        }
        else if ((i % BOOM) == 0)
        {
            printf("%s\n", "Boom");
        }
        else if ((i % TRACH) == 0)
        {
            printf("%s\n", "Trach");
        }
        else
        {
            Move_digits(i);
        }
    }
}

void Move_digits(size_t choiceNumber)
{
    size_t copyNumber = choiceNumber;
    int flagBoom = 0;
    int flagTrach = 0;

    while (copyNumber)
    {
        int help = copyNumber % 10;
        copyNumber /= 10;
        if (help == 3)
        {
            flagBoom = 1;
        }
        else if (help == 5)
        {
            flagTrach = 1;
        }
    }

    if (flagBoom && flagTrach)
    {
        printf("%s\n", "Boom-Trach");
    }
    else if (flagBoom && !flagTrach)
    {
        printf("%s\n", "Boom");
    }
    else if (!flagBoom && flagTrach)
    {
        printf("%s\n", "Trach");
    }
    else
    {
        printf("%d\n", choiceNumber);
    }
}