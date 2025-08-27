#include <stdio.h>
#include <stdbool.h>
#define MAX 10


typedef struct {
    int elem[MAX];
    int count; 
} List;

List L;

List initialize(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    if (L.count != MAX){ //check if full
        if(position >= 0 && position < L.count){ //position is valid
            if(position != L.count){ 
                for(int i = L.count; i > position; i--){
                        L.elem[i] = L.elem[i - 1];
                }
            }
            L.elem[position] = data;
            L.count++;
        }else{
            printf("Position is not valid.");
        }
    } else {
        printf("List is full.");
    }

    return L;
}

List deletePos(List L, int position){
    if (L.count != 0){//CHECK IF ITS EMPTY
        if(position >= 0 && position <= L.count){
            if(position != L.count){ 
                for(int i = position; i < L.count-1; i++){
                        L.elem[i] = L.elem[i + 1];
                }
            }
            L.count--;
        }else{
            printf("Position is not valid.");
        }
    }else{
        printf("List is empty.");
    }
}

int locate(List L, int data){

}

int main(){
    
}