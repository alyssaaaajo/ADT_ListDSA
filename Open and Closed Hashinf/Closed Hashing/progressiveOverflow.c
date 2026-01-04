#include <stdio.h>
#include <string.h>

#define MAX 10
#define PRIMARY_SIZE 5
#define EMPTY ""
#define DELETED "#"
#define MAX_STR 30

typedef struct {
    char elem[MAX_STR];
    int next;
} Node;

typedef struct {
    Node table[MAX];
    int avail;
} Dictionary;

int hash(char *key) {
    int sum = 0;
    while (*key) {
        sum += *key;
        key++;
    }
    return sum % PRIMARY_SIZE;
}

// initialize 
void initialize(Dictionary *D) {
    int i;
    for (i = 0; i < MAX; i++) {
        strcpy(D->table[i].elem, EMPTY);
        D->table[i].next = -1;
    }

    for (i = PRIMARY_SIZE; i < MAX - 1; i++) {
        D->table[i].next = i + 1;
    }
    D->table[MAX - 1].next = -1;
    D->avail = PRIMARY_SIZE;
}

// allocate from secondary area
int allocSpace(Dictionary *D) {
    int idx = D->avail;
    if (idx != -1) {
        D->avail = D->table[idx].next;
    }
    return idx;
}

// insert using progressive overflow
void insert(Dictionary *D, char *key) {
    int h = hash(key);

    if (strcmp(D->table[h].elem, EMPTY) == 0) {
        strcpy(D->table[h].elem, key);
        return;
    }

    int idx = allocSpace(D);
    if (idx == -1) {
        printf("Overflow area full\n");
        return;
    }

    strcpy(D->table[idx].elem, key);
    D->table[idx].next = D->table[h].next;
    D->table[h].next = idx;
}

// display dictionary
void display(Dictionary D) {
    int i;
    printf("PRIMARY AREA\n");
    for (i = 0; i < PRIMARY_SIZE; i++) {
        printf("[%d] %s -> %d\n", i,
               strcmp(D.table[i].elem, EMPTY) == 0 ? "EMPTY" : D.table[i].elem,
               D.table[i].next);
    }

    printf("\nSECONDARY AREA\n");
    for (i = PRIMARY_SIZE; i < MAX; i++) {
        printf("[%d] %s -> %d\n", i,
               strcmp(D.table[i].elem, EMPTY) == 0 ? "EMPTY" : D.table[i].elem,
               D.table[i].next);
    }

    printf("Avail = %d\n", D.avail);
}


int main() {
    Dictionary D;
    initialize(&D);

    insert(&D, "ant");
    insert(&D, "cat");
    insert(&D, "dog");
    insert(&D, "cow");
    insert(&D, "bat");
    insert(&D, "fox");

    display(D);
    return 0;
}
