#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 100
#define SIZE 8

void display(int *arr, int length)
{
    for (int i = 0; i < length; ++i)
    {
        printf("%d, ", arr[i]);
    }

    printf("\n");
}

void count_sort(int *arr, int length, int maxnum)
{
    int *sort_result = (int*)malloc(sizeof(int)*length);
    int *count = (int*)malloc(sizeof(int)*maxnum);
    int i;
    //init count
    for(i = 0; i < maxnum; i++) {
        count[i] = 0;
    }

    //count num
    for(i = 0; i < length; i++) {
        count[arr[i]]++;
    }

    // confirm offset
    for(i = 1; i < maxnum; i++) {
        count[i] += count[i-1];
    }

    // sort result
    for(i = length - 1; i >=0; i--) {
        sort_result[count[arr[i]] - 1] = arr[i];
        count[arr[i]] -= 1;
    }

    for (i = 0; i < length; i++)
        arr[i] = sort_result[i];
}

int main(int argc, char const *argv[])
{
    int arr[SIZE] = {2, 4, 11, 12, 12, 0, 23, 4};
    printf("%s\n", "sort before:");
    display(arr, SIZE);

    count_sort(arr, SIZE, MAXNUM);
    printf("%s\n", "sort after:");
    display(arr, SIZE);
    return 0;
}