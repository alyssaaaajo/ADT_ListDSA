#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

// Simple hash function using weighted RGB sum
int hashFunction(int rgb[3]) {
    int weightedSum = (rgb[0] * 3) + (rgb[1] * 5) + (rgb[2] * 7);
    return weightedSum % PALETTE_SIZE;
}

// Initialize dictionary (all buckets NULL)
void createDictionary(Dictionary *dict) {
    for (int i = 0; i < PALETTE_SIZE; i++) {
        dict->buckets[i] = NULL;
    }
}

// Create a linked list node
Node* createNode(Color newColor) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newNode->data.colorName, newColor.colorName);
    newNode->data.RGBVal[0] = newColor.RGBVal[0];
    newNode->data.RGBVal[1] = newColor.RGBVal[1];
    newNode->data.RGBVal[2] = newColor.RGBVal[2];
    newNode->next = NULL;
    return newNode;
}

// Insert color into dictionary
void insertColor(Dictionary *dict, Color newColor) {
    int index = hashFunction(newColor.RGBVal);
    Node *newNode = createNode(newColor);

    // Insert at head of linked list
    newNode->next = dict->buckets[index];
    dict->buckets[index] = newNode;

    printf("-> Inserted '%s' (RGB: %d, %d, %d) into bucket [%d].\n",
           newColor.colorName,
           newColor.RGBVal[0],
           newColor.RGBVal[1],
           newColor.RGBVal[2],
           index);
}

// Search for a color by RGB
Color* searchColor(Dictionary *dict, int rgb[3]) {
    int index = hashFunction(rgb);
    printf("Searching for RGB (%d, %d, %d) in bucket [%d]...\n",
           rgb[0], rgb[1], rgb[2], index);

    Node *current = dict->buckets[index];
    while (current != NULL) {
        if (current->data.RGBVal[0] == rgb[0] &&
            current->data.RGBVal[1] == rgb[1] &&
            current->data.RGBVal[2] == rgb[2]) {
            return &current->data;
        }
        current = current->next;
    }
    return NULL; // Not found
}
