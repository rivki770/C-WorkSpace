#include <stdio.h>
#include "Sort.h"

typedef unsigned int size_t;


int main()
{
    int arr[] = { 10, 50, 40, 20, 30 };
    size_t size = sizeof(arr) / sizeof(int);

    printf("Before sort\n");
    toPrint(arr, size);

    sort(arr, size);

    printf("\nAfter sort:\n");
    toPrint(arr, size);

    return 0;
}

void sort(int arr[], size_t size)
{
    int mini;

    if (arr)
    {
        for (size_t i = 0; i < size - 1; i++)
        {
            mini = i;
            for (size_t j = i + 1; j < size; j++)
            {
                if (arr[j] < arr[mini])
                    mini = j;
            }
            swap(&arr[mini], &arr[i]);
        }
    }
}

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void toPrint(int arr[], size_t size)
{
    for (int index = 0; index < size; index++)
    {
        printf("%d ", arr[index]);
    }
    printf("\n");
}