/*
Members: Caio França and João Victor Deppermann
Project: Word Search
Main data structures and algorithms: Trie (a type of tree), Array-2D, doubly linked list and DFS

Description:
- The program aims to solve word search problems
- Problems can be user-supplied or randomly generated with the help of rand() function

When running the program, the following workflow is executed:

1st step -> We create the structures that we will use
2nd step -> We read a dictionary (around 10,000 words) through a .txt file and insert each word in the trie
3rd step -> The dimensions of the wordsearch (from the char array) are requested from the user
4th step -> Next, two options are offered to the user:
    Option 1:
        -> The user generates the word search, that is, fills the char array and the program solves the problem by printing the words it found in the array
    Option 2:
        -> The program generates the wordsearch, that is, it fills the char array with the rand() function and then checks which and how many words are in the wordsearch. If there is no dictionary word in the array, a new array is generated and the process repeats until we have at least 1 word to be found.
        -> Once a word is found, we insert it into a doubly linked list.
        -> At the end we print the word search and a count saying "Number of words to find = X" (it will be the number of elements of the doubly linked list)
        -> User has 2 options:
            2.1 -> "Check found word" which checks if the word it found is in the linked list
            2.2 -> "Solve the word search for me" which prints the doubly linked list indicating eventually (depending on the time we have) the coordinates of the initial letter of each word (row ... column ... of the matrix)
5th step -> Destroy the dynamically allocated structures
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
    int actionChoice, gameChoice, intAux, nbRowsPuzzle, nbColumnsPuzzle, wordsLeftTofind, intRemoveWord;
    char wordAux[50];   // Used to print all the words in the trie and to delete a word from the trie

    // Linked list in which we store the words that can be found in the puzzle
    LinkedList* wordsFoundInThePuzzle;
    wordsFoundInThePuzzle = createLinkedList();

    // Puzzle that contains the 2D-array of chars
    Puzzle* puzzle;
    puzzle = createPuzzle();

    // Puzzle that contains all the words from the .txt file
    NodeTrie* trie;
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

    switch (gameChoice){
        case 1:
            populatePuzzleWithUserInput(puzzle);
            break;

        case 2:
            populatePuzzleWithRandomCharacters(puzzle);
            break;
    }

    printPuzzle(puzzle);
    solvePuzzle(trie, puzzle, wordsFoundInThePuzzle);
    wordsLeftTofind  = sizeLinkedList(wordsFoundInThePuzzle);

    do{

        printf("\nWords left to be found = %d\n", wordsLeftTofind);
        printf("----- What do you want to do? -----\n");
        printf("1: Print words contained in the puzzle\n");
        printf("2: Verify if I got a word right\n");
        printf("3: Print all the words of the dictionary\n");
        printf("4: Remove a word from the dictionary\n");
        printf("5: Print puzzle\n");
        printf("6: QUIT\n");
        printf("Select your choice: ");
        scanf("%d", &actionChoice);

        switch(actionChoice){
            case 1:
                printf("----------------------------------------------\n");
                printf("1: Print words contained in the puzzle\n");
                printLinkedList(wordsFoundInThePuzzle);
                printf("----------------------------------------------\n");
                break;

            case 2:
                printf("----------------------------------------------\n");
                printf("2: Verify if I got a word right\n");
                printf("Type the word you want to check: ");
                getchar();
                fgets(wordAux, 50, stdin);
                wordAux[strlen(wordAux)-1] = '\0';
                intAux = removeNodeLinkedList(wordsFoundInThePuzzle, wordAux);
                if (intAux)
                    printf("Yes, you have got it right!\n");
                else
                    printf("Sorry, this word is not in our dictionary :(\n");
                wordsLeftTofind  = sizeLinkedList(wordsFoundInThePuzzle);
                break;

            case 3:
                printf("----------------------------------------------\n");
                printf("3: Print all the words of the dictionary\n");
                printAllWordsOfTrie(trie, wordAux, 0);
                printf("\n----------------------------------------------\n");
                break;

            case 4:
                printf("----------------------------------------------\n");
                printf("4: Remove a word from the dictionary\n");
                printf("Type the word you want to delete: ");
                getchar();
                fgets(wordAux, 50, stdin);
                wordAux[strlen(wordAux) - 1] = '\0';
                intAux = deleteWordFromTrie(trie, wordAux);
                if (intAux){
                    printf("Word successfully removed from the trie!\n");
                    intRemoveWord = removeNodeLinkedList(wordsFoundInThePuzzle, wordAux);
                    wordsLeftTofind  = sizeLinkedList(wordsFoundInThePuzzle);
                }
                else
                    printf("Error when removing the word from the trie :(\n");
                printf("\n----------------------------------------------\n");
                break;

            case 5:
                printf("\n");
                printPuzzle(puzzle);
                break;

            case 6:
                break;

            default:
                printf("\nSorry, I didn't get it:(\n");
                break;
        }

    } while(actionChoice != 6);

    // We shall free memory that was allocated dynamically
    destroyPuzzle(puzzle);
    destroyLinkedList(wordsFoundInThePuzzle);
    destroyTrie(trie);

    return 0;
}
