#include <stdio.h>
#include "types.h"

// Initialize the priority queue
void initQueue(PriorityQueue *pq) {
    pq->size = 0;
    pq->capacity = MAX_PROCESSES;
    printf("\n--- Scheduler Queue initialized with capacity %d. ---\n", pq->capacity);
}

// Swap two processes
void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

// Restores the Max Heap property (used after removing the root)
void heapifyDown(PriorityQueue *pq, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->heap[left].priority > pq->heap[largest].priority)
        largest = left;

    if (right < pq->size && pq->heap[right].priority > pq->heap[largest].priority)
        largest = right;

    if (largest != index) {
        swap(&pq->heap[index], &pq->heap[largest]);
        heapifyDown(pq, largest);
    }
}

// Adds a process and maintains Max Heap order
void insertProcess(PriorityQueue *pq, Process newProcess) {
    if (pq->size == pq->capacity) {
        printf("Queue full! Cannot insert process %d.\n", newProcess.pid);
        return;
    }

    // Insert at end
    int i = pq->size++;
    pq->heap[i] = newProcess;

    // Sift up (heapify up)
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (pq->heap[parent].priority < pq->heap[i].priority) {
            swap(&pq->heap[parent], &pq->heap[i]);
            i = parent;
        } else break;
    }

    printf("-> ENQUEUED: Process ID %d (Priority: %d)\n", newProcess.pid, newProcess.priority);
}

// Extracts the process with the highest priority (root)
Process extractMax(PriorityQueue *pq) {
    Process dummy = { .pid = -1, .priority = -1 };

    if (pq->size == 0) {
        printf("Queue empty. No process to schedule.\n");
        return dummy;
    }

    Process root = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;

    heapifyDown(pq, 0);

    return root;
}