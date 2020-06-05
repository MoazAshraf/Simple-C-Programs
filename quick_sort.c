#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void print_array(int size, int array[size]);
bool check_arrays_equal(int size, int array_a[size], int array_b[size]);
void swap(int array[], int i, int j);
void quick_sort(int array[], int left, int right);
int partition(int array[], int left, int right);

int main(int argc, char* argv[argc+1]) {
    if (argc == 1) {
        // use simple array if there are no arguments
        int array[] = {1, 5, 3, 9, 2, -2, 6};
        int array_size = sizeof(array) / sizeof(array[0]);

        print_array(array_size, array);

        // sort the array
        quick_sort(array, 0, array_size-1);
        print_array(array_size, array);
        
        // compare the sorted result to the correct solution
        int sorted_array[] = {-2, 1, 2, 3, 5, 6, 9};
        if (check_arrays_equal(array_size, array, sorted_array)) {
            printf("Success!\n");
        } else {
            printf("Failed!\n");
        }
    } else {
        int array_size = argc - 1;
        int array[array_size];

        // get array from arguments
        for (int i = 0; i < array_size; ++i) {
            array[i] = atoi(argv[i+1]);
        }

        print_array(array_size, array);
        
        // sort the array
        quick_sort(array, 0, array_size-1);
        print_array(array_size, array);
    }
    return EXIT_SUCCESS;
}

void quick_sort(int array[], int left, int right) {
    if (left < right) {
        // pick a pivot and put it in the right place
        int pivot_i = partition(array, left, right);

        // quick sort each side of the pivot
        quick_sort(array, left, pivot_i-1);
        quick_sort(array, pivot_i+1, right);
    }
}

int partition(int array[], int left, int right) {
    // pick the pivot to be the last element
    int pivot_i = right;
    int pivot = array[pivot_i];
    int smaller_i = left-1;    // index of element directly smaller than pivot


    // move elements smaller than the pivot the left
    for (int i = left; i < right; ++i) {
        if (array[i] < pivot) {
            smaller_i++;
            swap(array, smaller_i, i);
        }
    }

    // swap the pivot with the element after the smaller elements
    swap(array, pivot_i, smaller_i+1);
    // print_array(7, array);
    return smaller_i+1;
}

void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void print_array(int size, int array[size]) {
    for (int i = 0; i < size-1; ++i) {
        printf("%d, ", array[i]);
    }
    printf("%d\n", array[size-1]);
}

bool check_arrays_equal(int size, int array_a[size], int array_b[size]) {
    for (int i = 0; i < size; ++i) {
        if (array_a[i] != array_b[i]) {
            return false;
        }
    }
    return true;
}