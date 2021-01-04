#include <stdio.h>
#include <stdlib.h>

#define LENGTH(arr) (sizeof(arr)/sizeof(arr[0]))

void countSortNoModify(int arr[], int len);

/**
问题：对于这个桶的选择问题？有什么更好的方式吗
**/

// 一个桶数据结构
typedef struct Bucket
{
    int len; //桶中数据多少
    int arr[]; //定义一个柔性数组
} Bucket;


int min_func(int a, int b)
{
    return a > b ? b : a;
}

int max_func(int a, int b)
{
    return a > b ? a : b;
}

static void bucketSort(int nums[], int length, int result[], int* result_len)
{
    int min = nums[0];
    int max = nums[0];
    for (int i = 0; i < length; i++) {
        min = min_func(min, nums[i]);
        max = max_func(max, nums[i]);
    }

    //计算桶的数量
    int bucket_num = (max-min)/length;
    //对桶进行初始化
    Bucket* buckets[bucket_num + 1];
    for (int i = 0; i <= bucket_num; i++) {
        buckets[i] = malloc(sizeof(struct Bucket));
        buckets[i]->len = 0;
    }

    //将每个元素放入桶
    for (int i = 0; i < length; i++) {
        int index = (nums[i] - min)/length;
        buckets[index]->arr[buckets[index]->len++] = nums[i];
    }

    //对桶中的元素进行排序
    int result_index = 0;
    for (int i = 0; i <= bucket_num; i++) {
        if (buckets[i]->len <= 0) {
            continue;
        }

        countSortNoModify(buckets[i]->arr, buckets[i]->len); // 调用其他排序算法，随便
        for (int j = 0; j < buckets[i]->len; j++) {
            result[result_index++] = buckets[i]->arr[j];
        }
    }

    *result_len = length;
}

int main(void)
{
    int nums[] = {18, 11, 28, 45, 23, 50};

    int result[6];
    int result_len;
    bucketSort(nums, LENGTH(nums), result, &result_len);

    for (int i = 0; i < result_len; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}