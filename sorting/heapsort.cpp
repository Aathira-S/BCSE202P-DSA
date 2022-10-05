#include<iostream>

void build_max_heap( float *arr, int n );
void max_heapify( float *arr, int i, int n );
void heap_sort( float *arr, int n );


void heap_sort( float *arr, int n ) {
    // Convert the initial binary tree to a max heap
    build_max_heap( arr, n );

    for ( int i = n - 1; i > 0; i-- ) {
        // Deletion occurs at the root node 
        std::swap( arr[0], arr[i] );

        // Re-heapify the binary tree
        max_heapify( arr, 0, i );
    }
}


// Converts the binary tree to a max heap in the beginning
void build_max_heap( float *arr, int n ) {
    for ( int i = n/2 - 1; i >= 0; i-- ) {
        max_heapify( arr, i, n );
    }
}


// Max Heapify the binary tree
void max_heapify( float *arr, int i, int n ) {
    
    // indices of left and right children
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;
    int largest = i; // index of root node

    // If a valid left child is greater than the root, mark it as the largest element
    if ( left_child < n && arr[left_child] > arr[largest] ) {
        largest = left_child;
    }
    
    // If a valid right child is greater than the root, mark it as the largest element
    if ( right_child < n && arr[right_child] > arr[largest] ) {
        largest = right_child;
    }

    // If the largest element is not the root (initial assumption), then we need to swap the new largest 
    // element with the old root, and re-heapify
    if ( largest != i ) {
        std::swap( arr[i], arr[largest] );
        max_heapify( arr, largest, n );
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

    heap_sort(array, n);

    std::cout << "\nArray after sorting:\n";
    printArray(array,n);

    delete[] array;

    return 0;
}