#include <stdio.h>
#include <stdbool.h>

#define MAX 5

//struct
typedef struct {
    int data[MAX];
    int top;
} Stack;

// initialize
void initialize(Stack *s) {
    s->top = -1;
}


bool isFull(Stack *s) {
    return s->top == MAX - 1;
}


bool isEmpty(Stack *s) {
    return s->top == -1;
}


void push(Stack *s, int value) {
    if (!isFull(s)) {
        s->data[++s->top] = value;
    }
}


int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top--];
    }
    return -1;
}


int peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return -1;
}

// top
int top(Stack *s) {
    return s->top;
}

// display
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Empty\n");
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}
