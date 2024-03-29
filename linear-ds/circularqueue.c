// Circular Queue implementation in C
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int items[SIZE];
int front = -1, rear = -1;

// Check if the queue is full
int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}

// Check if the queue is empty
int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

// Adding an element
void enQueue(int element) {
  if (isFull())
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\n Inserted -> %d\n" , element);
  }
}
// Removing an element
int deQueue() {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");     return (-1);
  } else {
    element = items[front];
    if (front == rear)    /*  one element */
  {
      front = -1;     // Q has only one element, so we reset the queue
      rear = -1;      //  after dequeing it.
    } 
else 
      { front = (front + 1) % SIZE; }
     printf("\n Deleted element -> %d \n", element);
    return (element);    
}  }
// Display the queue
void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Rear -> %d \n", rear);
  }
}
int main() {
  int choice;
    while (1)
    {   printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                int element;
                printf("Enter element to be queued ");
                scanf("%d", &element);
           		enQueue(element); break;
            case 2:
         		 deQueue(); break;
            case 3:
        	     display(); break;
            case 4:
            	exit(1); break;
            default:
           	 printf("Wrong choice \n");
        } /* End of switch */
    }
}
