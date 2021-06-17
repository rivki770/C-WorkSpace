#include <stdio.h>
typedef unsigned int size_t;

int sumSum(int arr[], size_t size);

int main()
{
    int arr[] = { 10, 20, 30, 40, 50 };
    size_t size1 = sizeof(arr);
    printf("%s%d%s\n", "Size arr out function: ", size1, " = It's good!");

    size_t size2 = size1 / sizeof(int);

    int sum = sumSum(arr, size2);
    printf("%s%d\n", "Sum is: ", sum);
    return 0;
}

int sumSum(int arr[], size_t size)
{
    int sum = 0;

    size_t size1 = sizeof(arr);
    printf("%s%d%s\n", "Size arr in function: ", size1, " = It's bad!");

    if (arr)
    {
        for (size_t index = 0; index < size; index++)
        {
            sum += arr[index];
        }
    }
    return sum;
}