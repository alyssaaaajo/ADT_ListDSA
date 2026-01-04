#include "set.h"

// Create empty set
Set* createSet() {
    Set* set = (Set*)malloc(sizeof(Set));
    set->head = NULL;
    set->size = 0;
    return set;
}

// Check if spell exists
bool containsSpell(Set* set, String spell) {
    Node* current = set->head;
    while (current != NULL) {
        if (strcmp(current->spell, spell) == 0)
            return true;
        current = current->next;
    }
    return false;
}

// Add spell (no duplicates)
bool addSpell(Set* set, String spell) {
    if (containsSpell(set, spell))
        return false;

    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->spell, spell);
    newNode->next = set->head;
    set->head = newNode;
    set->size++;
    return true;
}

// Remove spell
bool removeSpell(Set** setPtr, String spell) {
    if (*setPtr == NULL || (*setPtr)->head == NULL)
        return false;

    Set* set = *setPtr;
    Node* current = set->head;
    Node* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->spell, spell) == 0) {
            if (prev == NULL)
                set->head = current->next;
            else
                prev->next = current->next;
            free(current);
            set->size--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

// Print all spells
void printSet(Set* set) {
    Node* current = set->head;
    int index = 1;
    while (current != NULL) {
        printf("  %d. %s\n", index, current->spell);
        current = current->next;
        index++;
    }
}

// Destroy set
void destroySet(Set* set) {
    Node* current = set->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(set);
}

// Union of two sets
Set* unionSets(Set* set1, Set* set2) {
    Set* result = createSet();
    Node* current = set1->head;
    while (current != NULL) {
        addSpell(result, current->spell);
        current = current->next;
    }
    current = set2->head;
    while (current != NULL) {
        addSpell(result, current->spell);
        current = current->next;
    }
    return result;
}

// Intersection of two sets
Set* intersectSets(Set* set1, Set* set2) {
    Set* result = createSet();
    Node* current = set1->head;
    while (current != NULL) {
        if (containsSpell(set2, current->spell))
            addSpell(result, current->spell);
        current = current->next;
    }
    return result;
}
