#include "Prints.h"

//little
void PrintHexBytes(void *ptr, size_t size)
{
    printf("%s\n", "The memory in hex:");
    unsigned char *p = (unsigned char *) ptr;
    for (size_t index = size; index > 0; --index)
    {
        printf("%2X \n", p[index - 1]);
    }
    printf("\n");
}

//big
//void PrintHexBytes(void *ptr, size_t size)
//{
//    printf("%s\n", "The memory in hex:");
//    unsigned char *p = (unsigned char *) ptr;
//    for (size_t index = 0; index < size; ++index)
//    {
//        printf("%0X \n", p[index]);
//    }
//    printf("\n");
//}

void PrintBits(void * ptr, size_t size)
{
    printf("%s\n", "The memory in binary:");
    unsigned char *b = (unsigned char *) ptr;
    unsigned char byte;

    for (int i = (size - 1); i >= 0; i--)
    {
        for (size_t j = 1; j <= CHAR_BIT; ++j)
        {
            byte = (b[i] >> CHAR_BIT - j) & 1;
            if (j == CHAR_BIT / 2 + 1)
            {
                printf(" ");
            }
            printf("%d", byte);
        }
        printf("\n");
    }
    printf("\n");
}

//void PrintBits(void *ptr, size_t size)
//{
//    printf("%s\n", "The memory in binary:");
//
//    for (int byteCount = size - 1; byteCount >= 0; byteCount--)
//    {
//        unsigned char byte = *((unsigned char *) ptr + byteCount);
//        char byteString[CHAR_BIT + 2];
//        byteString[CHAR_BIT + 1] = '\0';
//
//        for (size_t bitCount = 0; bitCount < CHAR_BIT + 2; ++bitCount)
//        {
//            if (bitCount == CHAR_BIT / 2 - 1)
//            {
//                byteString[CHAR_BIT - bitCount - 1] = ' ';
//            }
//            else
//            {
//                byteString[CHAR_BIT - bitCount - 1] = ((byte >> bitCount) & 1) ? '1' : '0';
//            }
//        }
//        printf("%s\n", byteString);
//    }
//}