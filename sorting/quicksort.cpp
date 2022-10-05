#include <iostream>

int partition( float *arr, int lower, int upper );
void quick_sort( float *arr, int lower, int upper );


int partition( float *arr, int lower_limit, int upper_limit ) {

    // Considering the last element as the pivot
    // index of the element which is supposed to be placed in its sorted position
    int pivot_index = upper_limit; 
    int i = lower_limit - 1;        // iterator to locate the sorted position of the pivot point

    for ( int j = lower_limit; j <= upper_limit; j++ ) {
        if ( arr[j] < arr[pivot_index] ) {
            i++;
            std::swap( arr[i], arr[j] );
        }
    }

    // Sorted index of pivot = i + 1
    std::swap( arr[i+1], arr[pivot_index] );
    return i+1;
}


void quick_sort( float *arr, int lower_limit, int upper_limit ) {
    if ( lower_limit < upper_limit ) {

        // Element at this index will be in its place
        int sorted_index = partition(arr,lower_limit,upper_limit);

        // Sort subarray to the left hand side of the sorted element
        quick_sort(arr,lower_limit,sorted_index-1);

        // Sort subarray to the right hand side of the sorted element
        quick_sort(arr,sorted_index+1,upper_limit);
    }
}


void printArray(float *arr, int n ) {
    for ( int i = 0; i < n; i++ ) {
        std::cout << arr[i] << " ";
    }
}


int main() {

    int n;
    
    std::cout << "Enter number of elements: " << std::endl;
    std::cin >> n;

    float *array = new float[n];

    std::cout << "Enter array elements:\n";
    for ( int i = 0; i < n; i++ ) {
        std::cin >> array[i]; 
    }

    std::cout << "\nArray before sorting:\n";
    printArray(array,n);

    quick_sort(array,0,n-1);

    std::cout << "\nArray after sorting:\n";
    printArray(array,n);

    delete[] array;

    return 0;
}