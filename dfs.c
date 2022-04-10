#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "trie.h"
#include "dfs.h"
#include "puzzle.h"
#include "linked_list.h"

#define resultsize 1000

// Driver function for dfs lookup, called from main. It stores all the words found in a doubly linked list
void findwords(trieNode* root, Puzzle* puzzle, int* returnsize, ListaEnc2Plus* result) {
    *returnsize = 0;
    int i, j;
    /*
    // Allocating a high amount of memory for number of results, can be modified to use realloc depending on number of words found
    char** result = calloc(resultsize, sizeof * result);
    for (int i = 0; i < resultsize; i++) {
        // Allocating the max possible length for each word
        result[i] = calloc(puzzle->nbRows * puzzle->nbColumns + 1, sizeof(char));
    }
    */

    // Call the recursive function to perform a dfs for each cell of the grid and record the results in 'result'
    for (i = 0; i < puzzle->nbRows; i++) {
        for (j = 0; j < puzzle->nbColumns; j++) {
            int cap = (puzzle->nbRows * puzzle->nbColumns) + 1;
            char word[cap];
            dfs_lookup(root, puzzle->_2D_Array, puzzle->nbRows, puzzle->nbColumns, i, j, word, 0, result, returnsize);
        }
    }
}

// Recursive function which performs the dfs
void dfs_lookup(trieNode* node, char** grid, int rowsize, int colsize, int row, int col, char* word, int wordindex, ListaEnc2Plus* result, int* returnsize) {

    char current_char = grid[row][col];
    trieNode* child = (trieNode*)get(node->children, current_char);

    // Base case of recursion: the grid cell is already explored OR the character is not present in this location of the trie
    if (grid[row][col] == '#' || node->children->count == 0 || child == NULL) {
        return;
    }

    // Add current grid character to the word being formed
    word[wordindex] = current_char;

    // If this character marks the end of a word in the trie, it means we have found the word in the grid. Add it to results.
    if (child->endofword) {
        word[wordindex + 1] = '\0';
        insereInicioLista(result, word);
        child->endofword = false;
    }

    // Mark this grid cell as visited, so we don't reuse it for the same word.
    grid[row][col] = '#';

    // Call the function recursively on vertically and horizontally adjacent grid cells, if within bounds.
    if (row < rowsize - 1)
        dfs_lookup(child, grid, rowsize, colsize, row + 1, col, word, wordindex + 1, result, returnsize);
    if (row > 0)
        dfs_lookup(child, grid, rowsize, colsize, row - 1, col, word, wordindex + 1, result, returnsize);
    if (col < colsize - 1)
        dfs_lookup(child, grid, rowsize, colsize, row, col + 1, word, wordindex + 1, result, returnsize);
    if (col > 0)
        dfs_lookup(child, grid, rowsize, colsize, row, col - 1, word, wordindex + 1, result, returnsize);

    // Restore the current grid character for the next search.
    grid[row][col] = current_char;
}

