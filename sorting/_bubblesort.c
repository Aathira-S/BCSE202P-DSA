#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int arr[], int len)
{
    int temp;
    for(int i = 0; i < len - 1; i++)
        for(int j = 0; j < len - 1; j++)
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

void display(int arr[], int len)
{
    for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);
}

void main()
{
    int len, arr[100];
    printf("enter number of elements");
    scanf("%d", &len);
    printf("enter unsorted elements");
    for(int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, len);
    display(arr, len);
}