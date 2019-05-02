#include <stdio.h>

#define SIZE 8
int temp[SIZE]; //申请空间

void merge_sort(int *arr, int left, int right)
{
    if (left == right)
    {
        return ;
    }

    int mid = (left + right)/2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    int i = left;
    int j = mid + 1;
    int len = 0;
    while(i <= mid && j <= right) {
        if (arr[i] < arr[j])
        {
            temp[len] = arr[i];
            len++;
            i++;
        } else {
            temp[len] = arr[j];
            len++;
            j++;
        }
    }

    for (;i<=mid;i++) //下面几个for循环把排序好的数记录下来 
    { 
        temp[len] = arr[i]; 
        len++; //挨个赋值 
    } 

    for (;j<=right;j++) { 
        temp[len] = arr[j]; 
        len++; 
    } 

    for (int ii = left; ii <= right ;ii++) 
        arr[ii] = temp[ii - left];
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

    merge_sort(arr, 0, SIZE - 1);
    printf("%s\n", "sort after:");
    display(arr, SIZE);

    return 0;
}