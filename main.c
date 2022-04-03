/*
Victor Da Camino
Matrícula: 00275734
03/04/2022

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

int main() {

    srand(time(NULL)); // Used when filling the matrix with random characters

    int gameChoice;
    int retornoAux;
    int nbRowsPuzzle;
    int nbColumnsPuzzle;
    char identificadorAux;
    
    Puzzle *puzzle;
    puzzle = createPuzzle();

    printf("-----------------------------------------------------------\n");
    printf("                                                           \n");
    printf("         __   __   __     ___  ___     _     __  ___       \n");
    printf(" |    | |  | |__| |  \    |    |      / \   |__| |    |   |\n");
    printf(" | /\ | |  | | \  |   |   |--| |---  /---\  | \  |    |---|\n");
    printf(" |/  \| |__| |  \ |__/    ___| |___ /     \ |  \ |___ |   |\n");
    printf("                                                           \n");
    printf("___________________________________________________________\n");

    printf("Let's define the dimensions of our word search puzzle!\n");
    printf("Number of rows: ");
    scanf("%d", &puzzle->nbRows);
    printf("Number of columns: ");
    scanf("%d", &puzzle->nbColumns);
    
    // Declare the 2D array we are going to use to store our puzzle 
    // Alocate it dynamically because do know the size it will have
    puzzle->_2D_Array = generateMatrix(puzzle->nbRows, puzzle->nbColumns);

    printf("Choose the type of game you want to play:\n");
    printf("1. YOU create the word search puzzle and I solve it in 3s\n");
    printf("2. I create a word search puzzle and YOU solve it\n");
    scanf("%d", &gameChoice);

    switch (gameChoice) {
        case 1:
            humanCreate_MachineSolve(puzzle);
            break;

        case 2:
            machineCreate_HumanSolve(puzzle);
            break;
    }

    destroyPuzzle(puzzle);   // We shall free puzzle's memory since it was allocated dynamically

    return 0;
}
