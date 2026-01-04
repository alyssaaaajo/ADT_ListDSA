#ifndef SET_H
#define SET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SPELL_LENGTH 30
typedef char String[MAX_SPELL_LENGTH];

// Node structure
typedef struct Node {
    String spell;
    struct Node* next;
} Node;

// Set structure
typedef struct {
    Node* head;
    int size;
} Set;

// Function prototypes
Set* createSet();
bool addSpell(Set* set, String spell);
bool removeSpell(Set** setPtr, String spell);
bool containsSpell(Set* set, String spell);
void printSet(Set* set);
void destroySet(Set* set);
Set* unionSets(Set* set1, Set* set2);
Set* intersectSets(Set* set1, Set* set2);

#endif // SET_H
