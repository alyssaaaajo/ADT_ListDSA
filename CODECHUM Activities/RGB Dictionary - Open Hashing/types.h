#ifndef TYPES_H
#define TYPES_H

#define PALETTE_SIZE 64       // Size of hash table
#define MAX_NAME_LENGTH 50    // Max length for color name

typedef char String[MAX_NAME_LENGTH];

// Color structure
typedef struct {
    String colorName;
    int RGBVal[3]; // RGB values
} Color;

// Node for linked list (chaining)
typedef struct Node {
    Color data;
    struct Node *next;
} Node;

// Dictionary (hash table)
typedef struct {
    Node *buckets[PALETTE_SIZE];
} Dictionary;

// Function prototypes
int hashFunction(int rgb[3]);
void createDictionary(Dictionary *dict);
Node* createNode(Color newColor);
void insertColor(Dictionary *dict, Color newColor);
Color* searchColor(Dictionary *dict, int rgb[3]);

#endif
