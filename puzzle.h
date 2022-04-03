#ifndef __PUZZLE_H_
#define __PUZZLE_H_

typedef struct Puzzle {
	int isSolved;
	int nbRows;
	int nbColumns;
	char* _2D_Array;
} Puzzle;


// Function that creates a 2D array based on user's input
char* generateMatrix(int width, int height);

void populatePuzzleWithRandomCharacters(Puzzle* puzzle);

void populatePuzzleWithUserInput(Puzzle * puzzle);

void printPuzzle(Puzzle puzzle);

// Function that creates a puzzle
Puzzle* createPuzzle();

// Function that destroy the matrix which stores the puzzle
void destroyPuzzle(Puzzle* puzzle);

#endif
