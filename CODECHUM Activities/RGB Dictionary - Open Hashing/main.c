#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "dict.c"  // Include dict.c for functions

// Display all colors in the dictionary
void displayDictionary(Dictionary *dict) {
    printf("\n--- Color Dictionary Content ---\n");
    for (int i = 0; i < PALETTE_SIZE; i++) {
        Node *current = dict->buckets[i];
        if (current != NULL) {
            printf("Bucket [%d]: ", i);
            int count = 0;
            while (current != NULL) {
                if (count > 0) printf(" -> ");
                printf("%s (%d,%d,%d)",
                       current->data.colorName,
                       current->data.RGBVal[0],
                       current->data.RGBVal[1],
                       current->data.RGBVal[2]);
                current = current->next;
                count++;
            }
            printf("\n");
        }
    }
    printf("--------------------------------\n");
}

// Free all allocated memory
void destroyDictionary(Dictionary *dict) {
    for (int i = 0; i < PALETTE_SIZE; i++) {
        Node *current = dict->buckets[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
        dict->buckets[i] = NULL;
    }
}

int main() {
    Dictionary colorDict;
    createDictionary(&colorDict);

    // Create colors
    Color red = {"Red", {255, 0, 0}};
    Color green = {"Green", {0, 255, 0}};
    Color blue = {"Blue", {0, 0, 255}};
    Color white = {"White", {255, 255, 255}};
    Color black = {"Black", {0, 0, 0}};
    Color darkGrey = {"Dark Grey", {10, 10, 10}};
    Color darkRed = {"Dark Red", {30, 0, 0}};

    printf("--- Inserting Colors ---\n");
    insertColor(&colorDict, red);
    insertColor(&colorDict, green);
    insertColor(&colorDict, blue);
    insertColor(&colorDict, white);
    insertColor(&colorDict, black);
    insertColor(&colorDict, darkGrey);
    insertColor(&colorDict, darkRed);

    // Collision example
    Color lightGrey = {"Light Grey", {1, 1, 1}};
    Color slightlyRed = {"Slightly Red", {5, 0, 0}};

    printf("\n--- Inserting Colliding Colors ---\n");
    insertColor(&colorDict, lightGrey);
    insertColor(&colorDict, slightlyRed);

    displayDictionary(&colorDict);

    // --- Search Examples ---
    printf("\n--- Search Results ---\n");
    int searchRedRGB[3] = {255, 0, 0};
    Color *foundColor = searchColor(&colorDict, searchRedRGB);
    if (foundColor) printf("SUCCESS: Found Color: %s\n", foundColor->colorName);
    else printf("FAILURE: Color not found.\n");

    int searchSlightlyRed[3] = {5, 0, 0};
    foundColor = searchColor(&colorDict, searchSlightlyRed);
    if (foundColor) printf("SUCCESS: Found Color: %s\n", foundColor->colorName);
    else printf("FAILURE: Color not found.\n");

    int searchOrangeRGB[3] = {255, 165, 0};
    foundColor = searchColor(&colorDict, searchOrangeRGB);
    if (foundColor) printf("SUCCESS: Found Color: %s\n", foundColor->colorName);
    else printf("FAILURE: Color not found.\n");

    destroyDictionary(&colorDict);
    return 0;
}
