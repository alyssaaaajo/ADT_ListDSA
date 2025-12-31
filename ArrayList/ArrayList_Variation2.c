#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Struct
typedef struct {
    int elem[MAX];
    int count;
} Etype, *EPtr;

// Initialize list 
void initialize(EPtr L) {
    L->count = 0;
}

// Insert element at a specific position
void insertPos(EPtr L, int data, int position) {
    if (position < 0 || position > L->count || L->count == MAX) {
        return;
    }

    for (int i = L->count; i > position; i--) {
        L->elem[i] = L->elem[i - 1];
    }

    L->elem[position] = data;
    L->count++;
}

// Delete element at a specific position
void deletePos(EPtr L, int position) {
    if (position < 0 || position >= L->count) {
        return;
    }

    for (int i = position; i < L->count - 1; i++) {
        L->elem[i] = L->elem[i + 1];
    }

    L->count--;
}

// Locate position of a value
int locate(EPtr L, int data) {
    for (int i = 0; i < L->count; i++) {
        if (L->elem[i] == data) {
            return i;
        }
    }
    return -1;
}

// Retrieve element at a given position
int retrieve(EPtr L, int position) {
    if (position < 0 || position >= L->count) {
        return -1;
    }
    return L->elem[position];
}

// Insert element in a sorted list
void insertSorted(EPtr L, int data) {
    if (L->count == MAX) {
        return;
    }

    int i = L->count - 1;
    while (i >= 0 && L->elem[i] > data) {
        L->elem[i + 1] = L->elem[i];
        i--;
    }

    L->elem[i + 1] = data;
    L->count++;
}

// Display all elements
void display(EPtr L) {
    for (int i = 0; i < L->count; i++) {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

// Free the allocated memory
void makeNULL(EPtr L) {
    free(L);
}

int main() {
    EPtr L = (EPtr)malloc(sizeof(Etype));

    initialize(L);

    insertPos(L, 1, 0);
    insertPos(L, 3, 1);
    insertPos(L, 2, 2);
    insertPos(L, 5, 3);

    display(L);

    insertPos(L, 4, 2);
    display(L);

    deletePos(L, 1);
    display(L);

    int pos = locate(L, 5);
    printf("Position of 5: %d\n", pos);

    int value = retrieve(L, 2);
    printf("Retrieved value: %d\n", value);

    EPtr S = (EPtr)malloc(sizeof(Etype));
    initialize(S);

    insertSorted(S, 1);
    insertSorted(S, 3);
    insertSorted(S, 5);
    insertSorted(S, 10);
    insertSorted(S, 8);

    display(S);

    makeNULL(L);
    makeNULL(S);

    return 0;
}
