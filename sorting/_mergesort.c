#include<stdio.h>
#include<stdlib.h>

void mergeSort(int a[], int beg, int end)
{
    if (beg < end)
    {
        int mid = (beg+end)/2;
        mergeSort(a,beg,mid);
        mergeSort(a,mid+1,end);
        merge(a,mid,beg,end);
    }
}

void merge(int a[], int mid, int beg,int end)
{
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int L[n1], M[n2];

    for(int i = 0; i<n1; i++)
        L[i] = a[beg+i];
    for(int i = 0; i<n2; i++)
        M[i] = a[mid + 1 + i];

    int i=0, j=0, k=beg;
    while(i<n1 && j<n2)
    {
        if(L[i] <= M[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = M[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k] = M[j];
        j++;
        k++;
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
    mergeSort(arr,0, len);
    display(arr, len);
}