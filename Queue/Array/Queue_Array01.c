#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int count;
} List;

typedef struct {
    List list;
    int front;
    int rear;
} Queue;

// Initialize the queue
Queue* initialize() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->list.count = 0;
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is full
bool isFull(Queue* q) {
    return q->list.count == MAX;
}

// Check if the queue is empty
bool isEmpty(Queue* q) {
    return q->list.count == 0;
}

// Add element to the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d.\n", value);
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }

    q->list.items[q->rear] = value;
    q->list.count++;
    printf("%d enqueued to queue.\n", value);
}

// Remove element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }

    int value = q->list.items[q->front];

    if (q->list.count == 1) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }

    q->list.count--;
    return value;
}

// Get the front element
int frontValue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No front element.\n");
        return -1;
    }
    return q->list.items[q->front];
}

// Display all elements in the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    int i = q->front;
    int c = 0;
    while (c < q->list.count) {
        printf("%d ", q->list.items[i]);
        i = (i + 1) % MAX;
        c++;
    }
    printf("\n");
}

// Main function to test the queue
int main() {
    Queue* q = initialize();
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front element\n");
        printf("4. Display queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                value = dequeue(q);
                if (value != -1) printf("Dequeued: %d\n", value);
                break;
            case 3:
                value = frontValue(q);
                if (value != -1) printf("Front element: %d\n", value);
                break;
            case 4:
                display(q);
                break;
            case 5:
                free(q);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
