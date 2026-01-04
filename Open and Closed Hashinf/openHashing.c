#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define MAX_STR 50

typedef struct Node {
    char key[MAX_STR];
    struct Node *next;
} Node;

Node *hashTable[TABLE_SIZE];

//HASH FUNCTION
int hash(char *key) {
    int sum = 0;
    while (*key) {
        sum += *key;
        key++;
    }
    return sum % TABLE_SIZE;
}

//INITIALIZE TABLE 
void initialize() {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

void insert(char *key) {
    int index = hash(key);
    Node *newNode = (Node *)malloc(sizeof(Node));

    strcpy(newNode->key, key);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int search(char *key) {
    int index = hash(key);
    Node *trav = hashTable[index];

    while (trav != NULL) {
        if (strcmp(trav->key, key) == 0) {
            return 1;
        }
        trav = trav->next;
    }
    return 0;
}


void delete(char *key) {
    int index = hash(key);
    Node *trav = hashTable[index];
    Node *prev = NULL;

    while (trav != NULL && strcmp(trav->key, key) != 0) {
        prev = trav;
        trav = trav->next;
    }

    if (trav != NULL) {
        if (prev == NULL) {
            hashTable[index] = trav->next;
        } else {
            prev->next = trav->next;
        }
        free(trav);
    }
}

//DISPLAY
void display() {
    int i;
    Node *trav;

    for (i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        trav = hashTable[i];
        while (trav != NULL) {
            printf("%s -> ", trav->key);
            trav = trav->next;
        }
        printf("NULL\n");
    }
}

int main() {
    initialize();

    insert("apple");
    insert("banana");
    insert("grape");
    insert("orange");
    insert("melon");

    display();

    printf("\nSearch banana: %d\n", search("banana"));

    delete("banana");
    display();

    return 0;
}
