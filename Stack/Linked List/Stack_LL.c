#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

// initialize
Stack* initialize() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

// check if full
bool isFull(Stack* s) {
    return false;
}

// check if empty
bool isEmpty(Stack* s) {
    return s->top == NULL;
}


void push(Stack* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}


int pop(Stack* s) {
    if (isEmpty(s)) {
        return -1;
    }

    Node* temp = s->top;
    int value = temp->data;
    s->top = temp->next;
    free(temp);
    return value;
}


int peek(Stack* s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s->top->data;
}

// display
void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Empty\n");
        return;
    }

    Node* temp = s->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack* S;
    int choice, value;

    // initialize 
    S = initialize();

    do {
        printf("\n1 Push\n2 Pop\n3 Peek\n4 Display\n5 Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Value: ");
            scanf("%d", &value);
            push(S, value);
        }

        else if (choice == 2) {
            value = pop(S);
            if (value == -1)
                printf("Empty\n");
            else
                printf("Popped %d\n", value);
        }

        else if (choice == 3) {
            value = peek(S);
            if (value == -1)
                printf("Empty\n");
            else
                printf("Top %d\n", value);
        }

        else if (choice == 4) {
            display(S);
        }

    } while (choice != 5);

    return 0;
}
