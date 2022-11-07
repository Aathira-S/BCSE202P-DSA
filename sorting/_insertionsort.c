#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[], int len)
{
    int temp, curr, j;
    for(int i = 1; i < len; i++)
    {
        curr = arr[i];
        j = i-1;
        while(curr<arr[j] && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
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
    insertionSort(arr, len);
    display(arr, len);
}