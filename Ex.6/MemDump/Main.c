#include "Prints.h"

int main(void)
{
    //char value = 'A';
    int value = 0x11223344;
    //int value = 10;
    //char *value = "rivki";

    PrintHexBytes(&value, sizeof(value));

    PrintBits(&value, sizeof(value));

    return 0;
}