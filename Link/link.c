#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

/** 
    尾插法， 线性表--链表实现
**/

typedef struct Link
{
    int element;
    struct Link *next;
} link;

link * initLink()
{
    link *head = (link*)malloc(sizeof(link));
    link *temp = (link*)malloc(sizeof(link));
    temp->element = 1;
    temp->next = NULL;
    head->next = temp;

    for(int i = 2; i <= SIZE; i++) {
        link *body = (link*)malloc(sizeof(link));
        body->element = i;
        body->next = NULL;
        temp->next = body;
        temp = temp->next;
    }

    return head;
}

void insert(link *head, int offset, int value)
{
    if (offset < 1)
    {
        printf("%s\n", "insert offset error");
        exit(0);
    }

    link *temp = head;
    for (int i = 1; i < offset; ++i)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("%s\n", "insert offset error");
            exit(0);
        }
    }

    link *body = (link*)malloc(sizeof(link));
    body->element = value;
    body->next = temp->next;

    temp->next = body;
}

void delete(link *head, int offset)
{
    if (offset < 1)
    {
        printf("%s\n", "delete offset error");
        exit(0);
    }
    link *temp = head;
    for (int i = 1; i < offset; ++i)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("%s\n", "delete offset error");
            exit(0);
        }
    }
    link *body = temp->next;
    temp->next = body->next;
    free(body);
}

void edit(link *head, int offset, int value)
{
    if (offset < 1)
    {
        printf("%s\n", "edit offset error");
        exit(0);
    }

    link *temp = head;
    for (int i = 1; i <= offset; ++i)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("%s\n", "edit offset error");
            exit(0);
        }
    }

    temp->element = value;
}

int select(link *head, int value)
{
    link *temp = head;
    int i = 1;

    while(temp->next != NULL) {
        if (temp->next->element == value)
        {
            return i;
        }

        temp = temp->next;
        i++;
    }

    return -1;
}

void display(link *head)
{
    link *temp = head;
    while(temp->next) {
        printf("%d, ", temp->next->element);
        temp = temp->next;
    }

    printf("\n");
}

int main(int argc, char const *argv[])
{
    link *head = initLink();
    display(head);

    insert(head, 6, 114);
    display(head);

    delete(head, 3);
    display(head);

    edit(head, 3, 55);
    display(head);

    int value = 114;
    int offset = select(head, value);
    printf("value=%d, offset=%d\n", value, offset);

    return 0;
}