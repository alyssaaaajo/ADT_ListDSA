#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

// initVHeap
void initVHeap(VHeap *v) {
    for (int i = 0; i < MAX_SIZE; i++) {
        v->H[i].next = i + 1; 
    }
    v->H[MAX_SIZE - 1].next = -1;  
    v->avail = 0; 
}

// alloc
int alloc(VHeap *v){
    
    if(v->avail == -1){
        
        printf("Error: Heap is full. Cannot insert new article.\n");
        
    }
    
    int index = v->avail;
    v->avail = v->H[index].next;
    return index;
    
}

// dealloc

void dealloc(VHeap *v, int index){
    
    v->H[index].next = v->avail;
    v->avail = index;
    
}

// insertArticle

int insertArticle(VHeap *v, int *L, Article article, int position) {
    int new_index = alloc(v);
    if (new_index == -1) {
        return 0; 
    }

    v->H[new_index].article = article;
    v->H[new_index].next = -1;  

    
    if (position == -1) {
        if (*L == -1) {
            *L = new_index;  
        } else {
            int last = *L;
            while (v->H[last].next != -1) {
                last = v->H[last].next;
            }
            v->H[last].next = new_index; 
        }
    }
    else {
        if (position == 0) {
            v->H[new_index].next = *L;  
            *L = new_index;
        } else {
            int current = *L;
            for (int i = 0; i < position - 1 && current != -1; i++) {
                current = v->H[current].next;
            }
            if (current != -1) {
                int temp = v->H[current].next;
                v->H[current].next = new_index;
                v->H[new_index].next = temp;
            } else {
                printf("Position exceeds the length of the list.\n");
                dealloc(v, new_index);  
                return 0;  
            }
        }
    }

    return 1; 
}
        
        
    
    


// viewArticles

void viewArticles(VHeap v, int L) {
    
    if (L == -1) {
        
        printf("The knowledge base is empty.\n");
        return;
        
    }

    int current = L;
    
       printf("\n--- List of Articles ---\n");
    while (current != -1) {
        
        printf("ID: %d | Title: %s\n", v.H[current].article.id, v.H[current].article.title);
        current = v.H[current].next;  
    }
    printf("------------------------\n\n");
}
    

// searchArticle

void searchArticle(VHeap v, int L, int id){
    
     int current = L;
    while (current != -1) {
        if (v.H[current].article.id == id) {
            
            printf("\n--- Article Found ---\n");
            printf("ID: %d\n", v.H[current].article.id);
            printf("Title: %s\n", v.H[current].article.title);
            printf("Content: %s\n", v.H[current].article.content);
            printf("---------------------\n\n");
            return;
        }
        
        current = v.H[current].next;
    }

    printf("Article with ID %d not found.\n\n", id);
}
    


// deleteArticle

int deleteArticle(VHeap *v, int *L, int id){
    
     if (*L == -1) {
        printf("The knowledge base is empty.\n");
        return 0;
    }

    int current = *L;
    int previous = -1;
    while (current != -1) {
        
        if (v->H[current].article.id == id) {
            
            if (previous == -1) {
                *L = v->H[current].next;  
                
            } else {
                
                v->H[previous].next = v->H[current].next;  
                
            }

            dealloc(v, current); 
            printf("Article with ID %d deleted successfully.\n\n", id);
            return 1;  
        }

        previous = current;
        current = v->H[current].next;
    }

    printf("Article with ID %d not found.\n\n", id);
    return 0;  
}
