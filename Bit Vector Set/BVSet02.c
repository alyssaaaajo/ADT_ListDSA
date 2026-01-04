#include <stdio.h>
#include <stdbool.h>

#define MAX_BITS 8


typedef struct {
    unsigned int field : 8;
} Set;

// Initialize by clearing all bitss
void initialize(Set *set) {
    set->field = 0;
}

// Inserts an element into the set
void insert(Set *set, int element) {
    if (element < 0 || element >= MAX_BITS) {
        return;
    }
    set->field |= (1 << element);
}

// Deletes element from the set 
void delete(Set *set, int element) {
    if (element < 0 || element >= MAX_BITS) {
        return;
    }
    set->field &= ~(1 << element);
}

// Checks if element exists
bool find(Set set, int element) {
    if (element < 0 || element >= MAX_BITS) {
        return false;
    }
    return (set.field & (1 << element)) != 0;
}

// Returns union of two sets
Set set_union(Set A, Set B) {
    Set C;
    C.field = A.field | B.field;
    return C;
}

// Returns intersection of two sets
Set intersection(Set A, Set B) {
    Set C;
    C.field = A.field & B.field;
    return C;
}

// Returns difference of two sets
Set difference(Set A, Set B) {
    Set C;
    C.field = A.field & (~B.field);
    return C;
}

// Displays elements
void display(Set set) {
    int first = 1;
    printf("{");
    for (int i = 0; i < MAX_BITS; i++) {
        if (set.field & (1 << i)) {
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

    initialize(&A);
    insert(&A, 0);
    insert(&A, 4);
    insert(&A, 5);
    display(A);

    delete(&A, 5);
    delete(&A, 4);
    display(A);

    A.field = 49;
    B.field = 36;

    C = set_union(A, B);
    display(C);

    C = intersection(A, B);
    display(C);

    C = difference(A, B);
    display(C);

    return 0;
}
