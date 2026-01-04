#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10
#define BUCKET_SIZE 2
#define MAX_STR 30
#define EMPTY ""


char table[TABLE_SIZE][MAX_STR];

// hash adjusted to bucket range
int hash(char *key) {
    int sum = 0;
    while (*key) {
        sum += *key;
        key++;
    }
    return (sum % (TABLE_SIZE / BUCKET_SIZE)) * BUCKET_SIZE;
}

// Initialize
void initialize() {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        strcpy(table[i], EMPTY);
    }
}

// insert using bucket range
void insert(char *key) {
    int index = hash(key);
    int i;

    for (i = index; i < index + BUCKET_SIZE; i++) {
        if (strcmp(table[i], EMPTY) == 0) {
            strcpy(table[i], key);
            return;
        }
    }
    printf("Bucket overflow for key %s\n", key);
}

// display table
void display() {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: %s\n", i,
               strcmp(table[i], EMPTY) == 0 ? "EMPTY" : table[i]);
    }
}

int main() {
    initialize();

    insert("cat");
    insert("dog");
    insert("ant");
    insert("cow");
    insert("bat");
    insert("fox");

    display();
    return 0;
}
