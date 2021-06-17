#include <stdio.h>
#include <string.h>
#include "Calculator.h"

int main() {

    Number n1, n2, result;
    char typeNumber1, typeNumber2, sign;
    boolean flag = T;

    printf("Hi!\n");
    while (flag)
    {
        printf("\nPlease enter the type for first number:\n'c' for ConplexNumber,\n'r' for RealNumber,\n'e' for Exit.\n");
        scanf_s(" %c", &typeNumber1, sizeof(char));
        if (typeNumber1 == 'e')
        {
            printf("\nGoodBye!!\n");
            return 0;
        }
        Creat_number(&n1, typeNumber1);

        printf("\nEnter the sign operator (+, -, *, / or e [to EXIT]:\n");
        scanf_s(" %c", &sign, sizeof(char));
        if (sign == 'e')
        {
            printf("\nGoodBye!!\n");
            return 0;
        }

        printf("\nPlease enter the type for second number:\n'c' for ConplexNumber,\n'r' for RealNumber,\n'e' for Exit.\n");
        scanf_s(" %c", &typeNumber2, sizeof(char));
        if (typeNumber1 == 'e')
        {
            printf("\nGoodBye!!\n");
            return 0;
        }
        Creat_number(&n2, typeNumber2);

        Result(&n1, &n2, sign, &result);

        PrintFormat(&n1, &n2, sign, &result);
    }
    return 0;
}