#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct PriorityQueue {
    int heap[MAX];
    int size;
} PriorityQueue;

void initQueue(PriorityQueue* pq) {
    pq->size = 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueue* pq, int index) {
    if (index == 0) return;
    int parent = (index - 1) / 2;
    if (pq->heap[index] > pq->heap[parent]) {
        swap(&pq->heap[index], &pq->heap[parent]);
        heapifyUp(pq, parent);
    }
}

void insert(PriorityQueue* pq, int value) {
    if (pq->size == MAX) {
        printf("Priority Queue is full!\n");
        return;
    }
    pq->heap[pq->size] = value;
    heapifyUp(pq, pq->size);
    pq->size++;
}

void heapifyDown(PriorityQueue* pq, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->heap[left] > pq->heap[largest])
        largest = left;
    if (right < pq->size && pq->heap[right] > pq->heap[largest])
        largest = right;

    if (largest != index) {
        swap(&pq->heap[index], &pq->heap[largest]);
        heapifyDown(pq, largest);
    }
}

int extractMax(PriorityQueue* pq) {
    if (pq->size <= 0) return -1;
    int max = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
    return max;
}

int main() {
    PriorityQueue pq;
    initQueue(&pq);

    insert(&pq, 40);
    insert(&pq, 20);
    insert(&pq, 50);
    insert(&pq, 10);
    insert(&pq, 60);

    printf("Extracted elements in priority order: ");
    while (pq.size > 0) {
        printf("%d ", extractMax(&pq));
    }
    printf("\n");

    return 0;
}
