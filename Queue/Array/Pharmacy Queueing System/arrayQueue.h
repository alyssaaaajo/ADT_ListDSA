#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

// initialize
Queue* initialize() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    return q;
}


bool isFull(Queue* q) {
    return q->rear == MAX - 1;
}


bool isEmpty(Queue* q) {
    return q->front > q->rear;
}


void enqueue(Queue* q, int value) {
    if (!isFull(q)) {
        q->data[++q->rear] = value;
    }
}


int dequeue(Queue* q) {
    if (!isEmpty(q)) {
        return q->data[q->front++];
    }
    return -1;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}
