#include <stdlib.h>
#include <stdio.h>

#define SIZE 8

void swap(int *arr, int j, int i)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int * hill_sort(int *arr, int length)
{
    for (int gap = length/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < length; i++)
        {
            int j = i;
            while(j-gap >= 0 && arr[j] < arr[j - gap]) {
                swap(arr, j, j - gap);
                j -= gap;
            }
        }
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

    printf("%s\n", "sort before:");
    display(arr, SIZE);
    
    int *sort_result = hill_sort(arr, SIZE);

    printf("%s\n", "sort after:");
    display(sort_result, SIZE);

    return 0;
}