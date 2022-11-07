#include<stdio.h>
#include<stdlib.h>

int partition(int arr[], int beg, int end)
{
    int pivot = arr[end];
    int i = beg - 1;
    for (int j = beg; j<end; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = temp;
    return (i+1);
}

void quickSort(int arr[], int beg, int end)
{
    if(beg<end)
    {
        int p = partition(arr,beg, end);
        quickSort(arr, beg, p-1);
        quickSort(arr, p+1, end);
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
    quickSort(arr,0, len - 1);
    display(arr, len);
}