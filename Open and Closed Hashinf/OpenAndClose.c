#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// CLOSED HASHING ---------

int closedHash[TABLE_SIZE];

// Hash function
int hash(int key) {
    return key % TABLE_SIZE;
}

// Initialize closed hash table
void initClosedHash() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        closedHash[i] = -1;
    }
}

// Insert linear probing
void closedInsert(int key) {
    int index = hash(key);

    while (closedHash[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    closedHash[index] = key;
}

// Search key  closed hashing
int closedSearch(int key) {
    int index = hash(key);
    int start = index;

    while (closedHash[index] != -1) {
        if (closedHash[index] == key) {
            return index;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start) {
            break;
        }
    }
    return -1;
}

// Display closed hash table
void displayClosedHash() {
    printf("Closed Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (closedHash[i] == -1) {
            printf("[%d] -> EMPTY\n", i);
        } else {
            printf("[%d] -> %d\n", i, closedHash[i]);
        }
    }
}

// OPEN HASHING -------

// Node for chaining
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *openHash[TABLE_SIZE];

// Initialize open hash table
void initOpenHash() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        openHash[i] = NULL;
    }
}

// Insert using chaining
void openInsert(int key) {
    int index = hash(key);

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = key;
    newNode->next = openHash[index];
    openHash[index] = newNode;
}

// Search key open hashing
int openSearch(int key) {
    int index = hash(key);
    Node *temp = openHash[index];

    while (temp != NULL) {
        if (temp->data == key) {
            return index;
        }
        temp = temp->next;
    }
    return -1;
}

// Display open hash table
void displayOpenHash() {
    printf("Open Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d] -> ", i);
        Node *temp = openHash[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int keys[] = {23, 43, 13, 27, 15, 33};
    int n = sizeof(keys) / sizeof(keys[0]);

    initClosedHash();
    for (int i = 0; i < n; i++) {
        closedInsert(keys[i]);
    }
    displayClosedHash();

    printf("\n");

    initOpenHash();
    for (int i = 0; i < n; i++) {
        openInsert(keys[i]);
    }
    displayOpenHash();

    return 0;
}
