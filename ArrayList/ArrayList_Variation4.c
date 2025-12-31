#include <stdio.h>
#include <stdlib.h>

#define LENGTH 4

//struct
typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

// Initialize
void initialize(List *L) {
    L->elemPtr = (int *)malloc(sizeof(int) * LENGTH);
    L->max = LENGTH;
    L->count = 0;
}

// Resize list when full
void resize(List *L) {
    L->max = L->max * 2;
    L->elemPtr = (int *)realloc(L->elemPtr, sizeof(int) * L->max);
}

// Insert element at a specific position
void insertPos(List *L, int data, int position) {
    if (position < 0 || position > L->count) {
        return;
    }

    if (L->count == L->max) {
        resize(L);
    }

    for (int i = L->count; i > position; i--) {
        L->elemPtr[i] = L->elemPtr[i - 1];
    }

    L->elemPtr[position] = data;
    L->count++;
}

// Delete element at a specific position
void deletePos(List *L, int position) {
    if (position < 0 || position >= L->count) {
        return;
    }

    for (int i = position; i < L->count - 1; i++) {
        L->elemPtr[i] = L->elemPtr[i + 1];
    }

    L->count--;
}

// Locate value
int locate(List *L, int data) {
    for (int i = 0; i < L->count; i++) {
        if (L->elemPtr[i] == data) {
            return i;
        }
    }
    return -1;
}

// Retrieve element at a given position
int retrieve(List *L, int position) {
    if (position < 0 || position >= L->count) {
        return -1;
    }
    return L->elemPtr[position];
}

// Insert sorted 
void insertSorted(List *L, int data) {
    if (L->count == L->max) {
        resize(L);
    }

    int i = L->count - 1;
    while (i >= 0 && L->elemPtr[i] > data) {
        L->elemPtr[i + 1] = L->elemPtr[i];
        i--;
    }

    L->elemPtr[i + 1] = data;
    L->count++;
}

// Display all elements
void display(List *L) {
    for (int i = 0; i < L->count; i++) {
        printf("%d ", L->elemPtr[i]);
    }
    printf("\n");
}

// Free
void makeNULL(List *L) {
    free(L->elemPtr);
    L->elemPtr = NULL;
    L->count = 0;
    L->max = 0;
}

int main() {
    List L;

    initialize(&L);

    insertPos(&L, 1, 0);
    insertPos(&L, 3, 1);
    insertPos(&L, 2, 2);
    insertPos(&L, 5, 3);

    display(&L);

    insertPos(&L, 4, 2);
    display(&L);

    deletePos(&L, 1);
    display(&L);

    int pos = locate(&L, 5);
    printf("Position of 5: %d\n", pos);

    int value = retrieve(&L, 2);
    printf("Retrieved value: %d\n", value);

    List S;
    initialize(&S);

    insertSorted(&S, 1);
    insertSorted(&S, 3);
    insertSorted(&S, 5);
    insertSorted(&S, 10);
    insertSorted(&S, 8);

    display(&S);

    makeNULL(&L);
    makeNULL(&S);

    return 0;
}
