#include <iostream>

void printArray(int * array, int size) {
    for (int i = 0 ; i < size ; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void merge(int * array, int low, int medium, int high);

void mergeSort(int * array, int low, int high) {
    if (low < high) {
        
        int medium = low + (high - low) / 2;

        mergeSort(array, low, medium);
        mergeSort(array, medium + 1, high);

        merge(array, low, medium, high);
    }
}

void merge(int * array, int low, int medium, int high) {
    int i, j, k;
    
    const int size_left = medium - low + 1;
    const int size_right = high - medium;

    int * L = new int[size_left];
    int * R = new int[size_right];

    for (int i = 0 ; i < size_left ; ++i) {
        L[i] = array[low + i];
    }

    
    for (int i = 0 ; i < size_right ; ++i) {
        R[i] = array[medium + 1 + i];
    }

    i = 0;
    j = 0;
    k = 0;
    while(i < size_left && j < size_right) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            ++i;
        }else{
            array[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Check for remaining items;
    while(i < size_left) {
        array[k] = L[i];
        ++k; ++i;
    }

    while(j < size_right) {
        array[k] = R[j];
        ++k; ++j;
    }

    delete [] L;
    delete [] R;
}

int main (void) {
    int arr[] =  {12, 11, 13, 5, 1, 26};
    int arr_size = sizeof(arr)/sizeof(arr[0]); 

    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printArray(arr, arr_size);
}