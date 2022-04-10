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
#include "dfs.h"
#include "linked_list.h"

int main() {

    srand(time(NULL)); // Used when filling the matrix with random characters
    int x = 0;
    int opcao;
    int gameChoice;
    int retornoAux;
    int nbRowsPuzzle;
    int nbColumnsPuzzle;
    char wordAux[50];   // Used to print all the words in the trie
    int initialPositionWordStringAux = 0; // Used to print all the words in the trie
    char identificadorAux;

    ListaEnc2Plus* result;
    result = criaLista();

    Puzzle* puzzle;
    puzzle = createPuzzle();

    trieNode* trie;
    trie = populateTrieFromDictionary();

    printf("------Word Search------\n");
    printf("Let's define the dimensions of our word search puzzle!\n");
    printf("Number of rows: ");
    scanf("%d", &puzzle->nbRows);
    fflush(stdin);
    printf("Number of columns: ");
    scanf("%d", &puzzle->nbColumns);

    // Declare the 2D array we are going to use to store our puzzle
    // Allocate it dynamically because we don't know the size it will have
    puzzle->_2D_Array = createGrid(puzzle->nbRows, puzzle->nbColumns);

    printf("Choose the type of game you want to play:\n");
    printf("1. YOU create the word search puzzle and I solve it\n");
    printf("2. I create a word search puzzle and YOU solve it\n");
    scanf("%d", &gameChoice);

    int row, col, numwords, returnsize;

    switch (gameChoice) {
        case 1:
            populatePuzzleWithUserInput(puzzle);
            break;

        case 2:
            populatePuzzleWithRandomCharacters(puzzle);
            break;
    }
    printPuzzle(puzzle);
    findwords(trie, puzzle, &returnsize, result);
    int wordSLeftTofind = tamanhoLista(result);

    do{
        printf("Words left to be found = %d\n", wordSLeftTofind);
        printf("-----Opcoes-----\n");
        printf("1: Print words contained in the puzzle\n");
        printf("2: Verify if I got a word right\n");
        printf("3: Print all the words of the dictionary\n");
        printf("4: END\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

      switch(opcao){
        case 1:
            printf("----------------------------------------------\n");
            printf("1: Print words contained in the puzzle\n");
            imprimeLista(result);
            printf("----------------------------------------------\n");
            break;

        case 2:
            printf("----------------------------------------------\n");
            printf("2: Remove nodo\n");
            /*
            printf("Digite o identificador do nodo a ser removido: ");
            scanf(" %c", &identificadorAux);
            retornoAux = removeInfoABP(arvoreBinariaDePesquisa, identificadorAux);
            if (retornoAux == 1)
                printf("Nodo removido com sucesso!\n");
            else
                printf("Erro ao remover o nodo da arvore!\n");
            printf("----------------------------------------------\n");
            */
            break;

        case 3:
            printf("----------------------------------------------\n");
            printf("3: Print all the words of the dictionary\n");
            printAllWords(trie, wordAux, initialPositionWordStringAux);
            printf("\n----------------------------------------------\n");
        }
    } while(opcao != 4);

    //display_result(result, returnsize);

    destroyPuzzle(puzzle);   // We shall free puzzle's memory since it was allocated dynamically
    destroiLista(result);

    return 0;
}
