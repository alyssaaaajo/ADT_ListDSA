#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 8


typedef bool Set[ARRAY_SIZE];

// Initialize
void initialize(Set set) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        set[i] = false;
    }
}

// Inserts element
void insert(Set set, int element) {
    if (element < 0 || element >= ARRAY_SIZE) {
        return;
    }
    set[element] = true;
}

// Delete element
void delete(Set set, int element) {
    if (element < 0 || element >= ARRAY_SIZE) {
        return;
    }
    set[element] = false;
}

// Checks if element exists 
bool find(Set set, int element) {
    if (element < 0 || element >= ARRAY_SIZE) {
        return false;
    }
    return set[element];
}

// Computes the union of two sets
void set_union(Set A, Set B, Set C) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] || B[i];
    }
}

// Computes intersection of two sets
void intersection(Set A, Set B, Set C) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] && B[i];
    }
}

// Computes difference of two sets 
void difference(Set A, Set B, Set C) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] && !B[i];
    }
}

// Displays elements 
void display(Set set) {
    int first = 1;
    printf("{");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (set[i]) {
            if (!first) {
                printf(", ");
            }
            printf("%d", i);
            first = 0;
        }
    }
    printf("}\n");
}

int main() {
    Set A, B, C;

    initialize(A);
    insert(A, 0);
    insert(A, 2);
    insert(A, 7);
    display(A);

    delete(A, 0);
    delete(A, 7);
    display(A);

    initialize(A);
    initialize(B);

    insert(A, 0);
    insert(A, 2);
    insert(A, 7);

    insert(B, 2);
    insert(B, 4);
    insert(B, 5);

    set_union(A, B, C);
    display(C);

    intersection(A, B, C);
    display(C);

    difference(A, B, C);
    display(C);

    return 0;
}
