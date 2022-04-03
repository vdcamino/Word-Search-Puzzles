#include <stdio.h>
#include <string.h>
#include <time.h>
#include "matrix.h"

// Function that creates a 2D array based on user's input
char* generateMatrix(int width, int height) {
    char* matrix = malloc((width * height) * sizeof(char));
    return matrix;
}

void populatePuzzleWithRandomCharacters(Puzzle* puzzle) {
    for (int i = 0; i < puzzle->nbRows * puzzle->nbColumns; i++) {
        puzzle->_2D_Array[i]) = 'A' + (rand() % 26);
        if (i % puzzle->nbColumns == 0 && i != 0)
            printf("\n");
        else
            printf(" ");
}

void populatePuzzleWithUserInput(Puzzle* puzzle) {
    char userInputString[puzzle->nbColumns*2];
    for (int i = 0; i < puzzle->nbRows; i++){
        getchar();
        fgets(userInputString, puzzle->nbColumns, stdin);
        userInputString[strcspn(userInputString, "\n")] = 0;
        for (int j = 0; j < puzzle->strlen(userInputString); j+=2)
            puzzle->_2D_Array[i] = userInputString[j];
    }
}

void printPuzzle(Puzzle puzzle) {
    for (int i = 0; i < puzzle.nbRows; i++) {
        for (int j = 0; j < puzzle.nbColumns; j++)
            printf("%c ", puzzle._2D_Array[i * puzzle.nbColumns + j]);
        printf("\n");
    }
}

// Function that creates a puzzle
Puzzle* createPuzzle() {
    Puzzle* puzzle = (Puzzle*)malloc(sizeof(Puzzle));
    puzzle->_2D_Array = NULL;
    return puzzle;
}

// Function that destroy the matrix which stores the puzzle
void destroyPuzzle(Puzzle* puzzle) {
    free(puzzle);
}