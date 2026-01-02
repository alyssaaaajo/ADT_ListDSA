#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int count;
} List;

List* initialize() {
    List *L = malloc(sizeof(List));
    if (!L) return NULL;
    L->head = NULL;
    L->count = 0;
    return L;
}

void empty(List *list) {
    Node *current = list->head;
    while (current) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    list->count = 0;
}

void insertFirst(List *list, int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = list->head;
    list->head = node;
    list->count++;
}

void insertLast(List *list, int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (!list->head) {
        list->head = node;
    } else {
        Node *current = list->head;
        while (current->next)
            current = current->next;
        current->next = node;
    }
    list->count++;
}

void insertPos(List *list, int data, int index) {
    if (index < 0 || index > list->count) return;
    if (index == 0) { insertFirst(list, data); return; }
    if (index == list->count) { insertLast(list, data); return; }

    Node *node = malloc(sizeof(Node));
    node->data = data;

    Node *current = list->head;
    for (int i = 0; i < index - 1; i++)
        current = current->next;

    node->next = current->next;
    current->next = node;
    list->count++;
}

void deleteStart(List *list) {
    if (!list->head) return;
    Node *temp = list->head;
    list->head = temp->next;
    free(temp);
    list->count--;
}

void deleteLast(List *list) {
    if (!list->head) return;

    if (!list->head->next) {
        free(list->head);
        list->head = NULL;
    } else {
        Node *current = list->head;
        while (current->next->next)
            current = current->next;
        free(current->next);
        current->next = NULL;
    }
    list->count--;
}

void deletePos(List *list, int index) {
    if (index < 0 || index >= list->count) return;
    if (index == 0) { deleteStart(list); return; }

    Node *current = list->head;
    for (int i = 0; i < index - 1; i++)
        current = current->next;

    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    list->count--;
}

int retrieve(List *list, int index) {
    if (index < 0 || index >= list->count) return -1;
    Node *current = list->head;
    for (int i = 0; i < index; i++)
        current = current->next;
    return current->data;
}

int locate(List *list, int data) {
    Node *current = list->head;
    int index = 0;

    while (current) {
        if (current->data == data)
            return index;
        current = current->next;
        index++;
    }
    return -1;
}

void display(List *list) {
    Node *current = list->head;
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    List *L = initialize();

    insertLast(L, 2);
    insertLast(L, 6);
    insertLast(L, 5);
    display(L);

    insertFirst(L, 1);
    display(L);

    insertPos(L, 7, 2);
    display(L);

    deleteStart(L);
    display(L);

    deleteLast(L);
    display(L);

    deletePos(L, 1);
    display(L);

    printf("Value at index 1: %d\n", retrieve(L, 1));
    printf("Index of 6: %d\n", locate(L, 6));

    empty(L);
    display(L);

    free(L);
    return 0;
}
