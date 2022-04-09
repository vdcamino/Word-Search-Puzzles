#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "puzzle.h"

// Function that creates a 2D array based on user's input
char* generateMatrix(int width, int height) {
    char* matrix = malloc((width * height) * sizeof(char));
    return matrix;
}

void populatePuzzleWithRandomCharacters(Puzzle* puzzle) {
    for (int i = 0; i < puzzle->nbRows * puzzle->nbColumns; i++)
        puzzle->_2D_Array[i] = 'A' + (rand() % 26);
}

void populatePuzzleWithUserInput(Puzzle * puzzle) {
    char userInputString[puzzle->nbColumns];
    for (int i = 0; i < puzzle->nbRows; i++) {
        printf("Row %d: ", i + 1);
        getchar();
        fgets(userInputString, puzzle->nbColumns, stdin);
        for (int j = 0; j < strlen(userInputString); j ++)
            puzzle->_2D_Array[i * puzzle->nbColumns + j] = userInputString[i * puzzle->nbColumns + j];
    }
}

void printPuzzle(Puzzle *puzzle) {
    for (int i = 0; i < puzzle->nbRows; i++) {
        for (int j = 0; j < puzzle->nbColumns; j++)
            printf(" %c", puzzle->_2D_Array[i * puzzle->nbColumns + j]);
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
