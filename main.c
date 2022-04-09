/*
Victor Da Camino
Matrícula: 00275734
09/04/2022

Project description: X
- X
- X
- X
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "puzzle.h"
#include "trie.h"

int main() {

    srand(time(NULL)); // Used when filling the matrix with random characters

    int gameChoice;
    int retornoAux;
    int nbRowsPuzzle;
    int nbColumnsPuzzle;
    char wordAux[50];   // Used to print all the words in the trie
    int initialPositionWordStringAux = 0; // Used to print all the words in the trie
    char identificadorAux;

    Puzzle* puzzle;
    puzzle = createPuzzle();

    trieNode* trie;
    trie = populateTrieFromDictionary();

    printf("--------------------------------------------------------------------------------\n");
    printf("                                                                                \n");
    printf("            __    ___    __       ___     ___     _     ___   ____        \n");
    printf(" ||    || ||  || ||__| ||  \\    ||      ||       / \\   ||__| ||    ||   ||\n");
    printf(" || /\\ || ||  || || \\  ||   |   ||==||  ||===   /===\\  || \\  ||    ||===||\n");
    printf(" ||/  \\|| ||__|| ||  \\ ||__/     ___||  ||___  /     \\ ||  \\ ||___ ||   ||\n");
    printf("                                                                                \n");
    printf("________________________________________________________________________________\n");

    printf("Let's define the dimensions of our word search puzzle!\n");
    printf("Number of rows: ");
    scanf("%d", &puzzle->nbRows);
    printf("Number of columns: ");
    scanf("%d", &puzzle->nbColumns);

    // Declare the 2D array we are going to use to store our puzzle
    // Allocate it dynamically because we don't know the size it will have
    puzzle->_2D_Array = generateMatrix(puzzle->nbRows, puzzle->nbColumns);

    printf("Choose the type of game you want to play:\n");
    printf("1. YOU create the word search puzzle and I solve it\n");
    printf("2. I create a word search puzzle and YOU solve it\n");
    scanf("%d", &gameChoice);

    switch (gameChoice) {
        case 1:
            populatePuzzleWithUserInput(puzzle);
            printPuzzle(puzzle);
            //SOLVE PUZZLE
            // GIVE OPTIONS WITH COUNTER
            // IF 2 PRESSDE -> VERIFY IF THE ANSWER REALLY IS IN THE PUZZLE
            // IF 1 PRESSED -> PRINT ANSWERS
            break;

        case 2:
            populatePuzzleWithRandomCharacters(puzzle);
            printf("Please find the 5 remaining words contained in this puzzle:\n");
            printPuzzle(puzzle);
            printAllWords(trie, wordAux, initialPositionWordStringAux);
            break;
    }

    destroyPuzzle(puzzle);   // We shall free puzzle's memory since it was allocated dynamically

    return 0;
}
