#include <stdlib.h>
#include <stdio.h>

/**
    线性表--顺序表
**/
#define SIZE 5

typedef struct Table {
    int *arr; // table array
    int length; // table length
    int size; // table size
} table;

/**
    初始化线性表
**/
void initTable(table *head) 
{
    head->arr = (int*)malloc(SIZE * sizeof(int));
    if (!head->arr)
    {
        printf("%s\n", "init table error");
        exit(1);
    }

    head->length = 0;
    head->size = SIZE;
}

/**
    增加元素
**/
void insertEle(table *head, int offset, int value)
{
    if (offset < 1 || offset > (head->size + 1))
    {
        printf("%s\n", "insert offset error");
        exit(0);
    }

    if (offset == head->size + 1)
    {
        head->arr = (int*)realloc(head->arr, sizeof(int) * (head->size + 1));
        head->size++;
    }

    for(int i = head->length; i >= offset; i--) {
        head->arr[i] = head->arr[i-1];
    }

    head->arr[offset - 1] = value;
    head->length++;
}

/**
    删除元素
**/
void deleteEle(table *head, int offset)
{
    if (offset < 1 || offset > head->length)
    {
        printf("%s\n", "delete offset error");
        exit(1);
    }

    for(int i = offset; i < head->length; i++) {
        head->arr[i-1] = head->arr[i];
    }

    head->length--;
}

/**
    修改元素
**/
void editEle(table *head, int offset, int value)
{
    if (offset < 1 || offset > head->length)
    {
        printf("%s\n", "edit offset error");
        exit(1);
    }

    head->arr[offset - 1] = value;
}

/**
    查找元素
**/
int selectEle(table *head, int value)
{
    for(int i = 0; i < head->length; i++) {
        if (head->arr[i] == value)
        {
            return i + 1;
        }
    }

    return -1;
}

void display(table *head) 
{
    for (int i = 0; i < head->length; ++i)
    {
        printf("%d, ", head->arr[i]);
    }

    printf("\n");
}

int main(int argc, char *argv[])
{
    table head;
    initTable(&head);

    for (int i = 0; i < head.size; ++i)
    {
        head.arr[i] = i;
        head.length++;
    }

    display(&head);

    insertEle(&head, 6, 11);
    display(&head);

    deleteEle(&head, 1);
    display(&head);

    editEle(&head, 2, 33);
    display(&head);

    int offset = selectEle(&head, 4);
    printf("offset=%d\n", offset);
}