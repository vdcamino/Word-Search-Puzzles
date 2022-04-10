#ifndef __PUZZLE_H_
#define __PUZZLE_H_

typedef struct Puzzle {
	int isSolved;
	int nbRows;
	int nbColumns;
	char** _2D_Array;
} Puzzle;


// Function that creates a puzzle data structure
Puzzle* createPuzzle();

// Function that creates a 2D array based on user's input
char** createGrid(int width, int height);

// Function that converts a word entered by the user to a row of the grid
void parseInput(char** grid, int row, char* buffer);

// Function that randomly populates the char matrix thanks to the rand() function
void populatePuzzleWithRandomCharacters(Puzzle* puzzle);

// Function that populates the char matrix based on user input
void populatePuzzleWithUserInput(Puzzle* puzzle);

// Function that prints the 2D array that stores the puzzle
void printPuzzle(Puzzle *puzzle);

// Function that prints the list of words from the .txt dictionary that were found in the grid
//void display_result(char** result, int return_size);

// Function that destroy the 2D array which stores the puzzle
void destroyPuzzle(Puzzle* puzzle);

#endif
