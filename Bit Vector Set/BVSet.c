#include <stdio.h>
#include <stdbool.h>

#define MAX_BITS (8 * sizeof(unsigned char))

// Initialize by setting all bits to 0
void initialize(unsigned char *set) {
    *set = 0;
}

// Inserts element by setting the corresponding bit
void insert(unsigned char *set, int element) {
    if (element < 0 || element >= MAX_BITS) {
        return;
    }
    *set |= (1 << element);
}

// Deletes element from the set
void delete(unsigned char *set, int element) {
    if (element < 0 || element >= MAX_BITS) {
        return;
    }
    *set &= ~(1 << element);
}

// Checks if element exists in set
bool find(unsigned char set, int element) {
    if (element < 0 || element >= MAX_BITS) {
        return false;
    }
    return (set & (1 << element)) != 0;
}

// Returns union of bitwise OR
unsigned char set_union(unsigned char A, unsigned char B) {
    return A | B;
}

// Return intersection of bitwise AND
unsigned char intersection(unsigned char A, unsigned char B) {
    return A & B;
}

// Return difference of A AND (NOT B)
unsigned char difference(unsigned char A, unsigned char B) {
    return A & (~B);
}

// Display elements
void display(unsigned char set) {
    int first = 1;
    printf("{");
    for (int i = 0; i < MAX_BITS; i++) {
        if (set & (1 << i)) {
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
    unsigned char A, B, C;

    initialize(&A);
    insert(&A, 1);
    insert(&A, 6);
    display(A);

    delete(&A, 6);
    display(A);

    delete(&A, 1);
    display(A);

    A = 66;
    B = 200;

    C = set_union(A, B);
    display(C);

    C = intersection(A, B);
    display(C);

    C = difference(A, B);
    display(C);

    return 0;
}

