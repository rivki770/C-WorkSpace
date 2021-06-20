#include "Boom-trach.h"

/**
* @brief The function main that get input-number from the user.
* @see boomTrach(size_t choiceNumber).
*/
int main(void)
{
    size_t choiceNumber;
    printf("Please choose number\n");
    scanf_s("%d", &choiceNumber);
    printf("\n");
    boomTrach(choiceNumber);
    return 0;
}