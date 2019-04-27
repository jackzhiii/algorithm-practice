#include <stdio.h>
#include <stdlib.h>


#define SIZE 7
/**
    顺序查找, 找到返回下表， 找不到返回-1
**/
int line_search(int *arr, int length, int value)
{
    for(int i = 0; i < length; i++) {
        if (value == arr[i])
        {
            return i;
        }
    }

    return -1;
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
    int arr[SIZE] = {3, 11, 34, 2, 1, 7, 19};
    int value = 6;
    int offset = line_search(arr, SIZE, value);

    display(arr, SIZE);
    printf("value:%d of offset=%d\n", value, offset);
    return 0;
}