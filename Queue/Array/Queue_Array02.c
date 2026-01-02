#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Initialize
Queue* initialize() {
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->front = 1;
    Q->rear = 0;
    return Q;
}

// Check empty
bool isEmpty(Queue* q) {
    return q->front == (q->rear + 1) % MAX;
}

// Check full
bool isFull(Queue* q) {
    return q->front == (q->rear + 2) % MAX;
}

// Insert element
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
}

// Remove element
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    return value;
}

// Peek front
int frontElement(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->items[q->front];
}

// Display elements
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (i != (q->rear + 1) % MAX) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}


int main() {
    Queue* Q = initialize();  

    enqueue(Q, 10);  
    enqueue(Q, 20);  
    enqueue(Q, 30);  

    display(Q);      

    printf("Dequeued: %d\n", dequeue(Q)); 
    printf("Front element: %d\n", frontElement(Q));  

    enqueue(Q, 40);  
    enqueue(Q, 50);  

    display(Q);     

    
    enqueue(Q, 60);
    enqueue(Q, 70);
    enqueue(Q, 80);
    enqueue(Q, 90);
    enqueue(Q, 100);  

    display(Q);      // Display final queue

    return 0;
}
