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
List initialize(List L) {
    L.elemPtr = (int *)malloc(sizeof(int) * LENGTH);
    L.max = LENGTH;
    L.count = 0;
    return L;
}

// resize list when full
List resize(List L) {
    L.max = L.max * 2;
    L.elemPtr = (int *)realloc(L.elemPtr, sizeof(int) * L.max);
    return L;
}

// Insert element at a specific position
List insertPos(List L, int data, int position) {
    if (position < 0 || position > L.count) {
        return L;
    }

    if (L.count == L.max) {
        L = resize(L);
    }

    for (int i = L.count; i > position; i--) {
        L.elemPtr[i] = L.elemPtr[i - 1];
    }

    L.elemPtr[position] = data;
    L.count++;
    return L;
}

// Delete element at a specific position
List deletePos(List L, int position) {
    if (position < 0 || position >= L.count) {
        return L;
    }

    for (int i = position; i < L.count - 1; i++) {
        L.elemPtr[i] = L.elemPtr[i + 1];
    }

    L.count--;
    return L;
}

// Locate value
int locate(List L, int data) {
    for (int i = 0; i < L.count; i++) {
        if (L.elemPtr[i] == data) {
            return i;
        }
    }
    return -1;
}

// Insert sorted 
List insertSorted(List L, int data) {
    if (L.count == L.max) {
        L = resize(L);
    }

    int i = L.count - 1;
    while (i >= 0 && L.elemPtr[i] > data) {
        L.elemPtr[i + 1] = L.elemPtr[i];
        i--;
    }

    L.elemPtr[i + 1] = data;
    L.count++;
    return L;
}

// Display all elements
void display(List L) {
    for (int i = 0; i < L.count; i++) {
        printf("%d ", L.elemPtr[i]);
    }
    printf("\n");
}


int main() {
    List L;
    L = initialize(L);

    L = insertPos(L, 1, 0);
    L = insertPos(L, 3, 1);
    L = insertPos(L, 2, 2);
    L = insertPos(L, 5, 3);

    display(L);

    L = insertPos(L, 4, 2);
    display(L);

    L = deletePos(L, 1);
    display(L);

    int pos = locate(L, 5);
    printf("Position of 5: %d\n", pos);

    List S;
    S = initialize(S);

    S = insertSorted(S, 1);
    S = insertSorted(S, 3);
    S = insertSorted(S, 5);
    S = insertSorted(S, 10);
    S = insertSorted(S, 8);

    display(S);

    free(L.elemPtr);
    free(S.elemPtr);

    return 0;
}
