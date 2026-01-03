#include <stdio.h>
#include <string.h>

#define MAX 20
#define NONE -1

typedef struct {
    int id;
    char title[65];
    char content[256];
    int next;
} Article;

typedef struct {
    Article nodes[MAX];
    int avail;
} VirtualHeap;

// init heap
void initVH(VirtualHeap *vh) {
    for (int i = 0; i < MAX - 1; i++)
        vh->nodes[i].next = i + 1;
    vh->nodes[MAX - 1].next = NONE;
    vh->avail = 0;
}

// alloc node
int allocNode(VirtualHeap *vh) {
    int idx = vh->avail;
    if (idx != NONE)
        vh->avail = vh->nodes[idx].next;
    return idx;
}

// free node
void freeNode(VirtualHeap *vh, int idx) {
    vh->nodes[idx].next = vh->avail;
    vh->avail = idx;
}

// insert article
void insertArticle(VirtualHeap *vh, int *head, int pos,
                   int id, char title[], char content[]) {
    int newNode = allocNode(vh);
    if (newNode == NONE) return;

    vh->nodes[newNode].id = id;
    strcpy(vh->nodes[newNode].title, title);
    strcpy(vh->nodes[newNode].content, content);

    if (*head == NONE || pos == 0) {
        vh->nodes[newNode].next = *head;
        *head = newNode;
    } else {
        int curr = *head;
        int i = 0;
        while (vh->nodes[curr].next != NONE &&
              (pos == -1 || i < pos - 1)) {
            curr = vh->nodes[curr].next;
            i++;
        }
        vh->nodes[newNode].next = vh->nodes[curr].next;
        vh->nodes[curr].next = newNode;
    }
}

// display list
void displayArticles(VirtualHeap *vh, int head) {
    if (head == NONE) {
        printf("No articles\n");
        return;
    }
    while (head != NONE) {
        printf("[%d] %s\n",
            vh->nodes[head].id,
            vh->nodes[head].title);
        head = vh->nodes[head].next;
    }
}

// search article
void searchArticle(VirtualHeap *vh, int head, int id) {
    while (head != NONE) {
        if (vh->nodes[head].id == id) {
            printf("Title: %s\n", vh->nodes[head].title);
            printf("Content: %s\n", vh->nodes[head].content);
            return;
        }
        head = vh->nodes[head].next;
    }
    printf("Not found\n");
}

// delete article
void deleteArticle(VirtualHeap *vh, int *head, int id) {
    int curr = *head, prev = NONE;

    while (curr != NONE && vh->nodes[curr].id != id) {
        prev = curr;
        curr = vh->nodes[curr].next;
    }

    if (curr == NONE) {
        printf("Not found\n");
        return;
    }

    if (prev == NONE)
        *head = vh->nodes[curr].next;
    else
        vh->nodes[prev].next = vh->nodes[curr].next;

    freeNode(vh, curr);
    printf("Deleted\n");
}

int main() {
    VirtualHeap vh;
    int head = NONE;
    int choice, pos;
    int nextID = 1;
    char title[65], content[256];

    initVH(&vh);

    do {
        printf("\n1 Insert\n2 View\n3 Search\n4 Delete\n5 Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            printf("Title: ");
            fgets(title, 65, stdin);
            title[strcspn(title, "\n")] = 0;

            printf("Content: ");
            fgets(content, 256, stdin);
            content[strcspn(content, "\n")] = 0;

            printf("Position (-1 end): ");
            scanf("%d", &pos);

            insertArticle(&vh, &head, pos, nextID++, title, content);
        }

        else if (choice == 2) {
            displayArticles(&vh, head);
        }

        else if (choice == 3) {
            printf("ID: ");
            scanf("%d", &pos);
            searchArticle(&vh, head, pos);
        }

        else if (choice == 4) {
            printf("ID: ");
            scanf("%d", &pos);
            deleteArticle(&vh, &head, pos);
        }

    } while (choice != 5);

    return 0;
}
