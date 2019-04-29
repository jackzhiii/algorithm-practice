#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

int *select_sort(int *arr, int length)
{
    int temp;
    int minIndex;
    for(int i = 0; i < length - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    return arr;
}

void display(int *arr, int length)
{
    for (int i = 0; i < length; ++i)
    {
        printf("%d, ", arr[i]);
    }

    printf("\n");
}

int main(int argc, char const *argv[])
{
    int arr[SIZE] = {2, 4, 11, 12, -2, 0, 23, 4};

    int *sort_result = select_sort(arr, SIZE);

    printf("%s\n", "sort before:");
    display(arr, SIZE);

    printf("%s\n", "sort after:");
    display(sort_result, SIZE);

    return 0;
}