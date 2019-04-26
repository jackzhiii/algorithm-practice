#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

/**
    从小到大
**/
int * bubble_sort(int *arr, int length)
{
    if (length <= 1)
    {
        return arr;
    }

    int temp, i, j;
    for(i = 0; i < length - 1; i++) {
        for (j = i + 1; j < length; j++) {
            if (arr[i] > arr[j])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
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
    int origin_arr[SIZE] = {2, 4, 11, 12, -2, 0, 23, 4};

    int *sort_arr;
    sort_arr = bubble_sort(origin_arr, SIZE);

    printf("%s\n", "sort bufort:");
    display(origin_arr, SIZE);

    printf("%s\n", "after sort");
    display(sort_arr, SIZE);
    
    return 0;
}