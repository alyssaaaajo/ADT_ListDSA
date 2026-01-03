#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

// initialize
Queue* initialize() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// check if full
bool isFull(Queue* q) {
    return false;
}

// check if empty
bool isEmpty(Queue* q) {
    return q->front == NULL;
}

// add last
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// remove first
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        return -1;
    }

    Node* temp = q->front;
    int value = temp->data;
    q->front = temp->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}


int front(Queue* q) {
    if (isEmpty(q)) {
        return -1;
    }
    return q->front->data;
}

// display
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Empty\n");
        return;
    }

    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* Q;
    int choice, value;

    // initialize
    Q = initialize();

    do {
        printf("\n1 Enqueue\n2 Dequeue\n3 Front\n4 Display\n5 Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Value: ");
            scanf("%d", &value);
            enqueue(Q, value);
        }

        else if (choice == 2) {
            value = dequeue(Q);
            if (value == -1)
                printf("Empty\n");
            else
                printf("Removed %d\n", value);
        }

        else if (choice == 3) {
            value = front(Q);
            if (value == -1)
                printf("Empty\n");
            else
                printf("Front %d\n", value);
        }

        else if (choice == 4) {
            display(Q);
        }

    } while (choice != 5);

    return 0;
}
