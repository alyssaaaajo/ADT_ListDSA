#include<stdio.h>
#include<string.h>
#include "cldi.h"

String genreTable[16] = {
    "Ballad", "Pop Rock", "Pop", "R&B", "Rock", "Country Pop", "J-Pop", "K-Pop",
    "Classical", "Theater", "EDM", "OPM", "Reggae", "Dance", "Jazz", "Indie"
};

#define GENRE_COUNT 16

// Helper: Allocate and Free
int allocSpace(VirtualHeap *VH) {
    int temp = VH->avail;
    if (temp != -1) VH->avail = VH->H[temp].next;
    return temp;
}

void freeSpace(VirtualHeap *VH, int index) {
    VH->H[index].next = VH->avail;
    VH->avail = index;
}

// 🔹 HASH FUNCTION
int hash(String genre) {
    for (int i = 0; i < GENRE_COUNT; i++) {
        if (strcmp(genreTable[i], genre) == 0) return i;
    }
    return GENRE_COUNT - 1; // Default to last if unknown
}

// 🔹 INSERT FUNCTION
void insert(VirtualHeap *VH, Song song) {
    int index = hash(song.genre);

    // Empty slot
    if (strcmp(VH->H[index].elem.genre, "Empty") == 0 ||
        strcmp(VH->H[index].elem.genre, "Deleted") == 0) {
        VH->H[index].elem = song;
        VH->H[index].next = -1;
        return;
    }

    // Chain insertion
    int newNode = allocSpace(VH);
    if (newNode != -1) {
        VH->H[newNode].elem = song;
        VH->H[newNode].next = -1;

        int trav = index;
        while (VH->H[trav].next != -1) trav = VH->H[trav].next;
        VH->H[trav].next = newNode;
    } else {
        printf("⚠️ No space available for %s\n", song.songName);
    }
}

// 🔹 DELETE FUNCTION
void deleteMember(VirtualHeap *VH, Song song) {
    int index = hash(song.genre);

    // Head node
    if (strcmp(VH->H[index].elem.songName, song.songName) == 0 &&
        strcmp(VH->H[index].elem.genre, song.genre) == 0) {

        if (VH->H[index].next == -1) {
            strcpy(VH->H[index].elem.genre, "Empty");
            VH->H[index].elem.songName[0] = '\0';
            VH->H[index].elem.singer[0] = '\0';
        } else {
            int temp = VH->H[index].next;
            VH->H[index].elem = VH->H[temp].elem;
            VH->H[index].next = VH->H[temp].next;
            freeSpace(VH, temp);
        }
        return;
    }

    // Traverse chain
    int prev = index;
    int curr = VH->H[index].next;
    while (curr != -1) {
        if (strcmp(VH->H[curr].elem.songName, song.songName) == 0) {
            VH->H[prev].next = VH->H[curr].next;
            freeSpace(VH, curr);
            return;
        }
        prev = curr;
        curr = VH->H[curr].next;
    }
}

// 🔹 SEARCH FUNCTION
int search(VirtualHeap VH, Song song) {
    int index = hash(song.genre);

    if (strcmp(VH.H[index].elem.songName, song.songName) == 0 &&
        strcmp(VH.H[index].elem.genre, song.genre) == 0)
        return 1;

    int trav = VH.H[index].next;
    while (trav != -1) {
        if (strcmp(VH.H[trav].elem.songName, song.songName) == 0)
            return 1;
        trav = VH.H[trav].next;
    }
    return 0;
}