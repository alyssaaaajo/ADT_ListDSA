#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

// initialize stack
Stack* initialize() {
    Stack *s = malloc(sizeof(Stack));
    if (!s) return NULL;
    s->top = MAX;
    return s;
}

// check full
bool isFull(Stack *s) {
    return s->top == 0;
}

// check empty
bool isEmpty(Stack *s) {
    return s->top == MAX;
}

// push value
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->top--;
    s->items[s->top] = value;
}

// pop value
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf(" Underflow\n");
        return -1;
    }
    int value = s->items[s->top];
    s->top++;
    return value;
}

// peek value
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Empty\n");
        return -1;
    }
    return s->items[s->top];
}

// get top index
int top(Stack *s) {
    return s->top;
}

// display stack
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }

    printf("\nStack\n");
    printf("---------------------\n");
    for (int i = s->top; i < MAX; i++) {
        if (i == s->top)
            printf("| %d |  <- TOP\n", s->items[i]);
        else
            printf("| %d |\n", s->items[i]);
    }
    printf("---------------------\n");
}

int main() {
    Stack *S = initialize();

    push(S, 1);
    push(S, 3);
    push(S, 2);
    push(S, 5);

    display(S);

    push(S, 4);
    display(S);

    printf("\nPopped value: %d\n", pop(S));
    display(S);

    printf("\nPeek value: %d\n", peek(S));
    printf("Top index: %d\n", top(S));

    free(S);
    return 0;
}
