#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write your functions here
void heapify(char *arr[], int n, int i) {
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2; // right child

    // If left child is alphabetically larger than root
    if (left < n && strcmp(arr[left], arr[largest]) > 0)
        largest = left;

    // If right child is alphabetically larger than current largest
    if (right < n && strcmp(arr[right], arr[largest]) > 0)
        largest = right;

    // If largest is not root
    if (largest != i) {
        // Swap arr[i] and arr[largest]
        char *temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort on an array of strings
void heapSort(char *arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i >= 0; i--) {
        // Move current root (max) to the end
        char *temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify reduced heap
        heapify(arr, i, 0);
    }
}