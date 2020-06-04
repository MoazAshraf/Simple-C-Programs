#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void merge_sort(int array[], size_t left, size_t right);
void merge(int array[], size_t left, size_t middle, size_t right);
void print_array(size_t size, int array[size]);
bool check_arrays_equal(size_t size, int array_a[size], int array_b[size]);

int main(int argc, char* argv[argc+1]) {
    if (argc == 1) {
        // use simple array if there are no arguments
        int array[] = {1, 5, 3, 9, 2, -2, 6};
        size_t array_size = sizeof(array) / sizeof(array[0]);

        print_array(array_size, array);

        // sort the array
        merge_sort(array, 0, array_size-1);
        print_array(array_size, array);
        
        // compare the sorted result to the correct solution
        int sorted_array[] = {-2, 1, 2, 3, 5, 6, 9};
        if (check_arrays_equal(array_size, array, sorted_array)) {
            printf("Success!\n");
        } else {
            printf("Failed!\n");
        }
        
    } else {
        size_t array_size = argc - 1;
        int array[array_size];

        // get array from arguments
        for (size_t i = 0; i < array_size; ++i) {
            array[i] = atoi(argv[i+1]);
        }

        print_array(array_size, array);
        
        // sort the array
        merge_sort(array, 0, array_size-1);
        print_array(array_size, array);
    }
    return EXIT_SUCCESS;
}

void merge_sort(int array[], size_t left, size_t right) {
    if (right > left) {
        // calculate the middle
        size_t middle = left + (right - left) / 2;
        
        // sort each half
        merge_sort(array, left, middle);
        merge_sort(array, middle+1, right);

        // merge the two sorted halves
        merge(array, left, middle, right);
    }
}

void merge(int array[], size_t left, size_t middle, size_t right) {
    int sorted[right-left+1];       // holds sorted array
    size_t left_i = left;           // index in left subarray
    size_t right_i = middle+1;      // index in right half array
    size_t sorted_i = 0;            // index in sorted array

    // loop through the left and right subarrays and store the smaller number in "sorted"
    for ( ; left_i <= middle && right_i <= right; ++sorted_i) {
        if (array[left_i] <= array[right_i]) {
            sorted[sorted_i] = array[left_i];
            left_i++;
        } else {
            sorted[sorted_i] = array[right_i];
            right_i++;
        }
    }

    if (left_i <= middle) {
        // copy the rest of the left
        for ( ; left_i <= middle; ++left_i, ++sorted_i) {
            sorted[sorted_i] = array[left_i];
        }
    } else if (right_i <= right) {
        // copy the rest of the right array
        for ( ; right_i <= right; ++right_i, ++sorted_i) {
            sorted[sorted_i] = array[right_i];
        }
    }

    // copy the sorted array into the original array
    for (sorted_i = 0; sorted_i < right-left+1; ++sorted_i) {
        array[sorted_i+left] = sorted[sorted_i];
    }
}

void print_array(size_t size, int array[size]) {
    for (size_t i = 0; i < size-1; ++i) {
        printf("%d, ", array[i]);
    }
    printf("%d\n", array[size-1]);
}

bool check_arrays_equal(size_t size, int array_a[size], int array_b[size]) {
    for (size_t i = 0; i < size; ++i) {
        if (array_a[i] != array_b[i]) {
            return false;
        }
    }
    return true;
}