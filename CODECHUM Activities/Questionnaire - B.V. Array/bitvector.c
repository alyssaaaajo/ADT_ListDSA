#include <stdio.h>
#include <stdbool.h>
#include "bitvector.h"

#define QUESTION_COUNT 10

// Set a specific answer (1 for YES, 0 for NO)
void setAnswer(BitVect* profile, int index, int value) {
    if (index >= 0 && index < QUESTION_COUNT)
        profile->answers[index] = value ? 1 : 0;
}

// Get the answer (1 or 0) for a given question
int getAnswer(BitVect profile, int index) {
    if (index >= 0 && index < QUESTION_COUNT)
        return profile.answers[index];
    return 0;
}

// Count how many YES answers
int countYesAnswers(BitVect profile) {
    int count = 0;
    for (int i = 0; i < QUESTION_COUNT; i++) {
        if (profile.answers[i] == 1)
            count++;
    }
    return count;
}

// Print answers as 10-bit binary string (MSB first)
void printAnswers(BitVect profile) {
    for (int i = QUESTION_COUNT - 1; i >= 0; i--) {
        printf("%d", profile.answers[i]);
    }
    printf("\n");
}

// Count how many YES answers both profiles share
int compareProfiles(BitVect a, BitVect b) {
    int matches = 0;
    for (int i = 0; i < 10; i++) {
        if (a.answers[i] == b.answers[i])  // both YES
            matches++;
    }
    return matches;
}

// YES if either answered YES
BitVect unionProfiles(BitVect a, BitVect b) {
    BitVect result = {{0}};
    for (int i = 0; i < QUESTION_COUNT; i++) {
        result.answers[i] = (a.answers[i] || b.answers[i]) ? 1 : 0;
    }
    return result;
}

// YES if both answered YES
BitVect intersectProfiles(BitVect a, BitVect b) {
    BitVect result = {{0}};
    for (int i = 0; i < QUESTION_COUNT; i++) {
        result.answers[i] = (a.answers[i] && b.answers[i]) ? 1 : 0;
    }
    return result;
}

// YES in 'a' but NO in 'b'
BitVect differenceProfiles(BitVect a, BitVect b) {
    BitVect result = {{0}};
    for (int i = 0; i < QUESTION_COUNT; i++) {
        result.answers[i] = (a.answers[i] && !b.answers[i]) ? 1 : 0;
    }
    return result;
}