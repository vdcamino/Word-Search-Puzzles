#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "puzzle.h"

// Function that creates a puzzle data structure
Puzzle* createPuzzle() {
    Puzzle* puzzle = (Puzzle*)malloc(sizeof(Puzzle));
    puzzle->_2D_Array = NULL;
    return puzzle;
}

// Function that creates a 2D array based on user's input
char** createGrid(int width, int height) {
    int i;
    char **grid = (char**)calloc(height, sizeof(char*));
    for(i = 0; i < height; i++)
        *(grid + i) = (char*)calloc(width, sizeof(char));
    return grid;
}

// Convert a word entered by the user into a row of the grid
void parseInput(char **grid, int row, char *buffer){
    int col = 0;
    while(buffer[col] != '\0'){
        grid[row][col] = (char)buffer[col];
        col++;
    }
}

// Function that randomly populates the char matrix thanks to the rand() function
void populatePuzzleWithRandomCharacters(Puzzle* puzzle) {
    for (int i = 0; i < puzzle ->nbColumns; i++)
        for (int j = 0; j<puzzle->nbRows; j++)
            puzzle->_2D_Array[i][j] = 'a' + (rand() % 26);
}

// Function that populates the char matrix based on user input
void populatePuzzleWithUserInput(Puzzle * puzzle){
    int i, j;
    char buffer[puzzle->nbColumns];
    for(i = 0; i <puzzle->nbRows; i++){
        do{
            printf("\nEnter row #%d of the grid (as a single word of length = %d):", i+1, puzzle->nbColumns);
            fflush(stdin);
            scanf("%s", buffer);
            if(strlen(buffer) != puzzle->nbColumns)
                printf("\nPlease enter word of length = %d (the number of columns)\n", puzzle->nbColumns);
        } while(strlen(buffer) != puzzle->nbColumns);
        parseInput(puzzle->_2D_Array, i, buffer);
    }
}

// Function that prints the 2D array that stores the puzzle
void printPuzzle(Puzzle *puzzle) {
    int i, j;
    for(i=0; i<puzzle->nbRows; i++){
        for(j=0; j<puzzle->nbRows;j++)
            printf("%c ",puzzle->_2D_Array[i][j]);
        printf("\n");
    }
}

// Function that destroys the matrix which stores the puzzle
void destroyPuzzle(Puzzle* puzzle) {
    free(puzzle);
}
