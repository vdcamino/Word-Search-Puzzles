#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "trie.h"
#include "dfs.h"
#include "puzzle.h"
#include "linked_list.h"

#define resultsize 1000

// Function that calls a DFS for each character of the puzzle and store the words found in a linked list
void solvePuzzle(NodeTrie* root, Puzzle* puzzle, LinkedList* result){
    int i, j;
    // Call the recursive function to perform a dfs for each cell of the grid and record the words found in 'result'
    for (i = 0; i < puzzle->nbRows; i++) {
        for (j = 0; j < puzzle->nbColumns; j++) {
            int cap = (puzzle->nbRows * puzzle->nbColumns) + 1;
            char word[cap];
            DFS(root, puzzle->_2D_Array, puzzle->nbRows, puzzle->nbColumns, i, j, word, 0, result);
        }
    }
}

// Recursive function that performs the DFS
void DFS(NodeTrie* node, char** grid, int rowsize, int colsize, int row, int col, char* word, int wordindex, LinkedList* result) {
    char current_char = grid[row][col];
    NodeTrie* child = (NodeTrie*)get(node->children, current_char);
    // Base case of recursion: the grid cell is already explored OR the character is not present in this location of the trie
    if (grid[row][col] == '#' || node->children->count == 0 || child == NULL)
        return;
    // Add current grid character to the word being formed
    word[wordindex] = current_char;
    // If this character marks the end of a word in the trie, it means we have found the word in the grid. Add it to results.
    if (child->isEndOfWord) {
        word[wordindex + 1] = '\0';
        insertStartLinkedList(result, word);
        child->isEndOfWord = 0;
    }
    // Mark this grid cell as visited, so we don't reuse it for the same word.
    grid[row][col] = '#';
    // Call the function recursively on vertically and horizontally adjacent grid cells, if within bounds.
    if (row < rowsize - 1)
        DFS(child, grid, rowsize, colsize, row + 1, col, word, wordindex + 1, result);
    if (row > 0)
        DFS(child, grid, rowsize, colsize, row - 1, col, word, wordindex + 1, result);
    if (col < colsize - 1)
        DFS(child, grid, rowsize, colsize, row, col + 1, word, wordindex + 1, result);
    if (col > 0)
        DFS(child, grid, rowsize, colsize, row, col - 1, word, wordindex + 1, result);
    // Restore the current grid character for the next search.
    grid[row][col] = current_char;
}

