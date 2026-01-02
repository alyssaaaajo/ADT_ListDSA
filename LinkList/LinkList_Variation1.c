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

//initialize
List initialize() {
    List L;
    L.head = NULL;
    L.count = 0;
    return L;
}

// clear list
List empty(List list) {
    Node *current = list.head;
    while (current) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    list.head = NULL;
    list.count = 0;
    return list;
}

//insert front 
List insertFirst(List list, int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = list.head;
    list.head = node;
    list.count++;
    return list;
}

//insert end
List insertLast(List list, int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (!list.head) {
        list.head = node;
    } else {
        Node *current = list.head;
        while (current->next)
            current = current->next;
        current->next = node;
    }
    list.count++;
    return list;
}

//insert position
List insertPos(List list, int data, int index) {
    if (index < 0 || index > list.count) return list;
    if (index == 0) return insertFirst(list, data);
    if (index == list.count) return insertLast(list, data);

    Node *node = malloc(sizeof(Node));
    node->data = data;

    Node *current = list.head;
    for (int i = 0; i < index - 1; i++)
        current = current->next;

    node->next = current->next;
    current->next = node;
    list.count++;
    return list;
}

//delete front
List deleteStart(List list) {
    if (!list.head) return list;
    Node *temp = list.head;
    list.head = temp->next;
    free(temp);
    list.count--;
    return list;
}

// delete end
List deleteLast(List list) {
    if (!list.head) return list;

    if (!list.head->next) {
        free(list.head);
        list.head = NULL;
    } else {
        Node *current = list.head;
        while (current->next->next)
            current = current->next;
        free(current->next);
        current->next = NULL;
    }
    list.count--;
    return list;
}

//delete position
List deletePos(List list, int index) {
    if (index < 0 || index >= list.count) return list;
    if (index == 0) return deleteStart(list);

    Node *current = list.head;
    for (int i = 0; i < index - 1; i++)
        current = current->next;

    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    list.count--;
    return list;
}

// retrieve data
int retrieve(List list, int index) {
    if (index < 0 || index >= list.count) return -1;
    Node *current = list.head;
    for (int i = 0; i < index; i++)
        current = current->next;
    return current->data;
}

//locate data
int locate(List list, int data) {
    Node *current = list.head;
    int index = 0;

    while (current) {
        if (current->data == data)
            return index;
        current = current->next;
        index++;
    }
    return -1;
}

//display list 
void display(List list) {
    Node *current = list.head;
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    List L = initialize();

    L = insertLast(L, 2);
    L = insertLast(L, 6);
    L = insertLast(L, 5);

    display(L);

    L = insertPos(L, 7, 2);
    display(L);

    L = deleteStart(L);
    display(L);

    L = empty(L);
    display(L);

    return 0;
}
