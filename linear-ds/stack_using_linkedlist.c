#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *stack;

void enqueue(int item)
{
    struct Node *itemNode = (struct Node *)malloc(sizeof(struct Node));
    itemNode->data = item;
    itemNode->next = stack->next;
    stack->next = itemNode;
}

void dequeue()
{
    if (stack == NULL)
    {
        printf("Stack is empty");
        return;
    }
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp = stack->next;
    stack->next = temp ->next;
    free(temp);
}

void display()
{
    if (stack->next ==NULL)
    {
        printf("stack is empty");
        return;
    }
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp = stack->next;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    stack = (struct Node *)malloc(sizeof(struct Node));
    stack->next = NULL;
    printf("START\n");
    enqueue(1);
    enqueue(2);
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    return 0;
}