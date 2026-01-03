#include "arrayQueue.h"

int main() {
    Queue* regular;
    Queue* priority;
    int choice;
    int counter = 1;

    // initialize queues
    regular = initialize();
    priority = initialize();

    do {
        printf("\n1 Regular\n2 Priority\n3 Call Next\n4 Display\n5 Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // regular entry
            if (!isFull(regular)) {
                enqueue(regular, counter);
                printf("Regular #%d\n", counter);
                counter++;
            } else {
                printf("Regular full\n");
            }
        }

        else if (choice == 2) {
            // priority entry
            if (!isFull(priority)) {
                enqueue(priority, counter);
                printf("Priority #%d\n", counter);
                counter++;
            } else {
                printf("Priority full\n");
            }
        }

        else if (choice == 3) {
            // call next
            if (!isEmpty(priority)) {
                printf("Serving Priority #%d\n", dequeue(priority));
            } else if (!isEmpty(regular)) {
                printf("Serving Regular #%d\n", dequeue(regular));
            } else {
                printf("No customers\n");
            }
        }

        else if (choice == 4) {
            // display queues
            printf("Priority: ");
            display(priority);
            printf("Regular: ");
            display(regular);
        }

    } while (choice != 5);

    return 0;
}
