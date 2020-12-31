/**
 * 基数排序：C 语言
 *
 * 参考博客：https://www.cnblogs.com/skywang12345/p/3603669.html
 *
 * 基本原理就是：先排序好个位，然后排序好十位，如此下去
 * 找一个基数排序动态演示的就明白了
 */

#include <stdio.h>
#include <stdlib.h>

#define LENGTH(array) ((sizeof(array))/(sizeof(array[0])))

int get_max(int a[], int len)
{
    int max = a[0];
    for (int i = 1; i < len; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    return max;
}

void count_sort(int a[], int len, int exp)
{
    int output[len];
    int buckets[10] = {0}; //初始化桶的数量

    //计数
    for (int i = 0; i < len; i++) {
        buckets[ (a[i]/exp)%10 ]++;
    }

    //计算位置
    for (int i = 1; i < 10; i++) {
        buckets[i] += buckets[i-1];
    }

    for (int i = len - 1; i >= 0; i--) { //这个循环暂时不知道为什么必须这么写
        // 以下两行就是桶排序的原理
        output[buckets[ (a[i]/exp)%10 ] - 1] = a[i];
        buckets[ (a[i]/exp)%10 ]--;
    }

    for (int i = 0; i < len; i++) {
        a[i] = output[i];
    }
}

void radix_sort(int a[], int len)
{
    int max = get_max(a, len);
    for (int exp = 1; max/exp > 0; exp *= 10) {
        count_sort(a, len, exp);
    }
}

int main()
{
    int i;
    int a[] = {53, 3, 542, 748, 14, 214, 154, 63, 616};
    int ilen = LENGTH(a);

    printf("before sort:");
    for (i=0; i<ilen; i++)
        printf("%d ", a[i]);
    printf("\n");

    radix_sort(a, ilen);

    printf("after  sort:");
    for (i=0; i<ilen; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}