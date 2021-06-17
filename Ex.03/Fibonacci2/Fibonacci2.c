#include <stdio.h>
#include <stdlib.h>

typedef unsigned int size_t;

void fib1(size_t n);

void toPrint(int arr[], size_t size);

int main()
{
    int n;

    printf("Enter the number:\n");
    scanf_s("%d", &n);
    printf("\nFIBONACCI SERIES: \n");
    fib1(n);

    return 0;
}

void fib1(size_t n)
{
    int *aray = (int *) malloc((n + 2) * sizeof(int));

    aray[0] = -1;
    aray[1] = 1;

    for (size_t k = 2; k < n + 2; k++)
    {
        aray[k] = aray[k - 1] + aray[k - 2];
    }
    toPrint(aray, n);
    free(aray);
}

void toPrint(int arr[], size_t size)
{
    for (size_t index = 2; index < size + 2; index++)
    {
        printf("%ld ", arr[index]);
    }
    printf("\n");
}