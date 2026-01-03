#include <stdio.h>

#define MAX 4

typedef struct {
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
} VHeap;

typedef int List;   // list head index

void initialize(VHeap *V);
int allocSpace(VHeap *V);
void deallocSpace(VHeap *V, int index);

void insertFirst(List *L, VHeap *V, int elem);
void insertLast(List *L, VHeap *V, int elem);
void insertSorted(List *L, VHeap *V, int elem);

void deleteElem(List *L, VHeap *V, int elem);
void display(List L, VHeap V);

// Initialize free list BACKWARDS
void initialize(VHeap *V) {
    int i;
    for (i = MAX - 1; i > 0; i--) {
        V->H[i].next = i - 1;
    }
    V->H[0].next = -1;
    V->avail = MAX - 1;
}

int allocSpace(VHeap *V) {
    int idx = V->avail;
    if (idx != -1) {
        V->avail = V->H[idx].next;
    }
    return idx;
}

void deallocSpace(VHeap *V, int index) {
    V->H[index].next = V->avail;
    V->avail = index;
}

// Insert first
void insertFirst(List *L, VHeap *V, int elem) {
    int idx = allocSpace(V);
    if (idx != -1) {
        V->H[idx].elem = elem;
        V->H[idx].next = *L;
        *L = idx;
    }
}

// Insert end 
void insertLast(List *L, VHeap *V, int elem) {
    int idx = allocSpace(V);
    int *trav = L;

    if (idx != -1) {
        V->H[idx].elem = elem;
        V->H[idx].next = -1;

        while (*trav != -1) {
            trav = &V->H[*trav].next;
        }
        *trav = idx;
    }
}

// Insert  sorted 
void insertSorted(List *L, VHeap *V, int elem) {
    int idx = allocSpace(V);
    int *trav = L;

    if (idx != -1) {
        while (*trav != -1 && V->H[*trav].elem < elem) {
            trav = &V->H[*trav].next;
        }
        V->H[idx].elem = elem;
        V->H[idx].next = *trav;
        *trav = idx;
    }
}

// Delete first occurrence 
void deleteElem(List *L, VHeap *V, int elem) {
    int *trav = L;

    while (*trav != -1 && V->H[*trav].elem != elem) {
        trav = &V->H[*trav].next;
    }

    if (*trav != -1) {
        int temp = *trav;
        *trav = V->H[temp].next;
        deallocSpace(V, temp);
    }
}

// Display list
void display(List L, VHeap V) {
    while (L != -1) {
        printf("%d ", V.H[L].elem);
        L = V.H[L].next;
    }
    printf("\n");
}

int main() {
    VHeap V;
    List L = -1;

    initialize(&V);

    insertFirst(&L, &V, 20);
    insertFirst(&L, &V, 10);
    insertLast(&L, &V, 40);
    insertSorted(&L, &V, 30);

    display(L, V);

    deleteElem(&L, &V, 20);
    display(L, V);

    return 0;
}
