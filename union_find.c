// Simple implementation of the Union-Find data structure

#include <stdio.h>

void initialize(size_t n, size_t parent[n]);
size_t find(size_t parent[], size_t element);
void find_replace(size_t parent[], size_t element, size_t value);
size_t find_compress(size_t parent[], size_t element);
void union_(size_t parent[], size_t a, size_t b);
void print_parents(size_t n, size_t parent[n]);

int main(void) {
    size_t n = 5;        // number of elements
    size_t parent[n];    // this array stores the parents of each element, indexed by the elements (from 0 to n-1)

    // initialize the data structure
    initialize(n, parent);
    print_parents(n, parent);

    union_(parent, 2, 3);
    print_parents(n, parent);

    union_(parent, 2, 0);
    print_parents(n, parent);

    union_(parent, 1, 4);
    print_parents(n, parent);

    union_(parent, 4, 0);
    print_parents(n, parent);
    printf("root of 3: %lu\n", find(parent, 3));
}

// this functions initializes the data structure by making each element its own parent (a singleton set)
void initialize(size_t n, size_t parent[n]) {
    for (size_t i = 0; i < n; ++i) {
        parent[i] = i;
    }
}

// returns the root of the set this element belongs to
size_t find(size_t parent[], size_t element) {
    size_t i = element;
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

// replaces parents of all the elements on a path to the root (including the root) to a specific value
void find_replace(size_t parent[], size_t element, size_t value) {
    size_t i = element;

    // set all elements on the path to the specific value
    while (parent[i] != i) {
        size_t temp = i;
        i = parent[i];
        parent[temp] = value;
    }
    parent[i] = value;  // set the root to the value
}

// replaces parents of all the elements on a path to the root to the value of the root
size_t find_compress(size_t parent[], size_t element) {
    size_t root = find(parent, element);
    find_replace(parent, element, root);
    return root;
}

// union operation of two elements
void union_(size_t parent[], size_t a, size_t b) {
    size_t root_of_a = find_compress(parent, a);
    find_replace(parent, b, root_of_a);
}

void print_parents(size_t n, size_t parent[n]) {
    printf("parent\t");
    for (size_t i = 0; i < n-1; ++i) {
        printf("%lu ", parent[i]);
    }
    printf("%lu\n", parent[n-1]);

    printf("element\t");
    for (size_t i = 0; i < n-1; ++i) {
        printf("%lu ", i);
    }
    printf("%lu\n\n", n-1);
}