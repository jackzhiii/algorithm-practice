#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

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
    return 0;
}