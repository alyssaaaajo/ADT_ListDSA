//Linear Probing 

#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10
#define MAX_STR 50

#define EMPTY 0
#define OCCUPIED 1
#define DELETED 2

typedef struct {
    char key[MAX_STR];
    int status;
} HashEntry;

HashEntry hashTable[TABLE_SIZE];

int hash(char *key) {
    int sum = 0;
    while (*key) {
        sum += *key;
        key++;
    }
    return sum % TABLE_SIZE;
}

void initialize() {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].status = EMPTY;
    }
}

void insert(char *key) {
    int index = hash(key);
    int start = index;

    while (hashTable[index].status == OCCUPIED) {
        index = (index + 1) % TABLE_SIZE;
        if (index == start) {
            printf("Hash table is full\n");
            return;
        }
    }

    strcpy(hashTable[index].key, key);
    hashTable[index].status = OCCUPIED;
}


int search(char *key) {
    int index = hash(key);
    int start = index;

    while (hashTable[index].status != EMPTY) {
        if (hashTable[index].status == OCCUPIED &&
            strcmp(hashTable[index].key, key) == 0) {
            return 1;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start) {
            break;
        }
    }
    return 0;
}


void delete(char *key) {
    int index = hash(key);
    int start = index;

    while (hashTable[index].status != EMPTY) {
        if (hashTable[index].status == OCCUPIED &&
            strcmp(hashTable[index].key, key) == 0) {
            hashTable[index].status = DELETED;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start) {
            break;
        }
    }
}


void display() {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        if (hashTable[i].status == OCCUPIED) {
            printf("%s\n", hashTable[i].key);
        } else if (hashTable[i].status == DELETED) {
            printf("DELETED\n");
        } else {
            printf("EMPTY\n");
        }
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

    printf("\nSearch grape: %d\n", search("grape"));

    delete("grape");
    display();

    return 0;
}
