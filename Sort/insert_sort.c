#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void display(int *arr, int length)
{
    for (int i = 0; i < length; ++i)
    {
        printf("%d, ", arr[i]);
    }

    printf("\n");
}

/** 
将第一待排序序列第一个元素看做一个有序序列，把第二个元素到最后一个元素当成是未排序序列。

从头到尾依次扫描未排序序列，将扫描到的每个元素插入有序序列的适当位置。（如果待插入的元素与有序序列中的某个元素相等，则将待插入元素插入到相等元素的后面。）
**/
int * insert_sort(int *arr, int length)
{
    int j; //未排序下标
    int key;
    for (int i = 1; i < length; ++i)
    {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }

    return arr;
}

int main(int argc, char const *argv[])
{
    int arr[SIZE] = {2, 4, 11, 12, -2, 0, 23, 4};
    printf("%s\n", "sort before:");
    display(arr, SIZE);

    int *sort_result = insert_sort(arr, SIZE);

    printf("%s\n", "sort after:");
    display(sort_result, SIZE);
    return 0;
}