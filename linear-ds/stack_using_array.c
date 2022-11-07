#include<stdio.h>
#define N 5

struct Stack
{
    int top;
    int items[N];
} stack;

void push(int item)
{
    if (stack.top >= N-1)
    {
       printf("Stack is full\n"); 
    }
    else
    {
        stack.top += 1;
        stack.items[stack.top] = item;
    }
}

void pop()
{
    if (stack.top == -1)
    {
        printf("stack is empty\n");
    }
    else
    {
        stack.top -= 1;
    }
}

void peek()
{
    if (stack.top == -1)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("%d", stack.items[stack.top]);
    }
}
void display()
{
    printf("top:%d\nitems: ",stack.top);
    if (stack.top == -1)
    {
        printf("Stack is empty\n");
    }
    else 
    {
        
        for(int i = stack.top; i>=0; i--)
        {
            printf("%d ", stack.items[i]);
        }
        printf("\n");
    }
}
void create()
{
    int n, item;
    printf("Enter number of items in stack");
    scanf("%d", &n);
    printf("Enter items\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &item);
        push(item);
    }
}
void main()
{
    printf("%d", N);
    stack.top = -1;
    create();
    display();
    push(20);
    push(30);
    push(40);
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
}