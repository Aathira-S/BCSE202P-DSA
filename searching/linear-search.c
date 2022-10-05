#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

void linearSearch(struct node * head)
{
    int search, found = 0;
    printf("Enter search element");
    scanf("%d", &search);
    while (head != NULL)
    {
        if (head->data == search)
            found = 1;
        head = head->next;
    }
    if (found ==1)
    printf("Element found");
    else
    printf("Element not found");
}

void createLL(struct node * curr)
{
    int len, data;
    printf("Enter length of linked list");
    scanf("%d", &len);
    printf("Enter data");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &data);
        curr->data = data;
        curr->next = (struct node*)malloc(sizeof(struct node*));
        curr = curr->next;
    }
    curr->next = NULL;
}

void main() 
{
    struct node* head = (struct node*)malloc(sizeof(struct node*));
    createLL(head);
    linearSearch(head);

}