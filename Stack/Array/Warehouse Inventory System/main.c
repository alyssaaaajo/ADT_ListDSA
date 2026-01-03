#include "arrayStack.h"

int main() {
    Stack stacks[3];
    int choice, id;

    // initialize stacks
    for (int i = 0; i < 3; i++) {
        initialize(&stacks[i]);
    }

    do {
        printf("\n1 Add\n2 Remove\n3 Search\n4 Display\n5 Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // add container
            printf("ID: ");
            scanf("%d", &id);

            int added = 0;
            for (int i = 0; i < 3; i++) {
                if (!isFull(&stacks[i])) {
                    push(&stacks[i], id);
                    printf("Added to Stack %d\n", i + 1);
                    added = 1;
                    break;
                }
            }
            if (!added) {
                printf("All stacks full\n");
            }
        }

        else if (choice == 2) {
            // remove container
            int removed = 0;
            for (int i = 2; i >= 0; i--) {
                if (!isEmpty(&stacks[i])) {
                    printf("Removed %d from Stack %d\n", pop(&stacks[i]), i + 1);
                    removed = 1;
                    break;
                }
            }
            if (!removed) {
                printf("All stacks empty\n");
            }
        }

        else if (choice == 3) {
            // search container
            printf("ID: ");
            scanf("%d", &id);

            int found = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j <= stacks[i].top; j++) {
                    if (stacks[i].data[j] == id) {
                        printf("Found in Stack %d\n", i + 1);
                        found = 1;
                        break;
                    }
                }
            }
            if (!found) {
                printf("Not found\n");
            }
        }

        else if (choice == 4) {
            // display stacks
            for (int i = 0; i < 3; i++) {
                printf("Stack %d: ", i + 1);
                display(&stacks[i]);
            }
        }

    } while (choice != 5);

    return 0;
}
