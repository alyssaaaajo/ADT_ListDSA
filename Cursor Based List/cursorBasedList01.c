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

typedef int List;   // stores index 


void initialize(VHeap *V);
int  allocSpace(VHeap *V);
void deallocSpace(VHeap *V, int index);

void insertFirst(List *L, VHeap *V, int elem);
void insertLast(List *L, VHeap *V, int elem);
void insertPos(List *L, VHeap *V, int elem, int pos);
void insertSorted(List *L, VHeap *V, int elem);

void deleteElem(List *L, VHeap *V, int elem);
void deleteAllOccurrence(List *L, VHeap *V, int elem);

void display(List L, VHeap V);

void initialize(VHeap *V) {
    int i;
    for (i = 0; i < MAX - 1; i++) {
        V->H[i].next = i + 1;
    }
    V->H[MAX - 1].next = -1;
    V->avail = 0;
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

void insertFirst(List *L, VHeap *V, int elem) {
    int idx = allocSpace(V);
    if (idx != -1) {
        V->H[idx].elem = elem;
        V->H[idx].next = *L;
        *L = idx;
    }
}

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

void insertPos(List *L, VHeap *V, int elem, int pos) {
    int idx = allocSpace(V);
    int *trav = L;
    int i = 1;

    if (idx != -1) {
        while (*trav != -1 && i < pos) {
            trav = &V->H[*trav].next;
            i++;
        }
        V->H[idx].elem = elem;
        V->H[idx].next = *trav;
        *trav = idx;
    }
}

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

void deleteAllOccurrence(List *L, VHeap *V, int elem) {
    int *trav = L;

    while (*trav != -1) {
        if (V->H[*trav].elem == elem) {
            int temp = *trav;
            *trav = V->H[temp].next;
            deallocSpace(V, temp);
        } else {
            trav = &V->H[*trav].next;
        }
    }
}

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

    insertFirst(&L, &V, 10);
    insertLast(&L, &V, 30);
    insertPos(&L, &V, 20, 2);
    insertSorted(&L, &V, 25);

    display(L, V);

    deleteElem(&L, &V, 20);
    display(L, V);

    deleteAllOccurrence(&L, &V, 30);
    display(L, V);

    return 0;
}
