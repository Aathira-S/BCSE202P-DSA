#include<stdio.h>
#include<stdlib.h>

void selectionSort(int arr[], int len)
{
    int minpos,temp,i,j;
    for(i = 0; i < len - 1; i++)
    {
        minpos = i;
        for(j = i+1 ; j < len; j++)
        {
            if (arr[minpos]>arr[j])
                minpos = j;
        }
        if (minpos != i)
        {
            temp = arr[minpos];
            arr[minpos] = arr[i];
            arr[i] = temp;
        }  
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
    selectionSort(arr, len);
    display(arr, len);
}