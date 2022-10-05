#include<stdio.h>

void binarySearch(int *arr, int search, int beg, int end)
{
    if (beg > end)
    {

        printf("Element not found");
        return;
    }
    int mid = (beg + end) / 2;
    if (arr[mid] == search)
    {
        printf("element found at index %d", mid);
        return;
    }
    if (arr[mid] > search)
    return binarySearch(arr, search, beg, mid - 1);
    else
    return binarySearch(arr, search, mid + 1, end);
    
}

void main()
{   
    int arr[100];
    int len;
    printf("Enter length of array");
    scanf("%d", &len);

    printf("Enter sorted data");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }
    int search;
    printf("Enter search element");
    scanf("%d", &search);
    binarySearch(arr, search, 0, len-1);
}