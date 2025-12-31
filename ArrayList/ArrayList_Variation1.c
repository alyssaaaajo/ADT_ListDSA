#include <stdio.h>

#define MAX 10

// List structure using static array
typedef struct {
    int elem[MAX];
    int count;
} List;

// Initialize the list
List initialize(List L) {
    L.count = 0;
    return L;
}

// Insert element at a specific position
List insertPos(List L, int data, int position) {
    if (position < 0 || position > L.count || L.count == MAX) {
        return L;
    }

    for (int i = L.count; i > position; i--) {
        L.elem[i] = L.elem[i - 1];
    }

    L.elem[position] = data;
    L.count++;
    return L;
}

// Delete element at a specific position
List deletePos(List L, int position) {
    if (position < 0 || position >= L.count) {
        return L;
    }

    for (int i = position; i < L.count - 1; i++) {
        L.elem[i] = L.elem[i + 1];
    }

    L.count--;
    return L;
}

// Locate the position of a value in the list
int locate(List L, int data) {
    for (int i = 0; i < L.count; i++) {
        if (L.elem[i] == data) {
            return i;
        }
    }
    return -1;
}

// Insert element in a sorted list
List insertSorted(List L, int data) {
    if (L.count == MAX) {
        return L;
    }

    int i = L.count - 1;
    while (i >= 0 && L.elem[i] > data) {
        L.elem[i + 1] = L.elem[i];
        i--;
    }

    L.elem[i + 1] = data;
    L.count++;
    return L;
}

// Display all elements in the list
void display(List L) {
    for (int i = 0; i < L.count; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}

// Main function to test the operations
int main() {
    List L = initialize(L);

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

    List S = initialize(S);
    S = insertSorted(S, 1);
    S = insertSorted(S, 3);
    S = insertSorted(S, 5);
    S = insertSorted(S, 10);
    S = insertSorted(S, 8);

    display(S);

    return 0;
}
