#include <stdio.h>

/**
    快速排序
**/

#define SIZE 8

void display(int *arr, int length)
{
    for (int i = 0; i < length; ++i)
    {
        printf("%d, ", arr[i]);
    }

    printf("\n");
}

void quick_sort(int *arr, int left, int right)
{
    if (left >= right)
    {
        return ;
    }

    int i = left;
    int j = right;
    int key = arr[i];
    while(i < j) {
        while(i <j && key <= arr[j]) {
            j--;
        }
        arr[i] = arr[j];

        while(i < j && key >= arr[i]) {
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = key;

    // display(arr, SIZE);
    quick_sort(arr, left, i - 1);
    quick_sort(arr, i + 1, right);
}

int main(int argc, char const *argv[])
{
    int arr[SIZE] = {2, 4, 11, 12, -2, 0, 23, 4};

    printf("%s\n", "sort befort:");
    display(arr, SIZE);

    // printf("%s\n", "srot doing");

    quick_sort(arr, 0, SIZE - 1);
    printf("%s\n", "sort after:");
    display(arr, SIZE);

    return 0;
}