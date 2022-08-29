#ifndef _DFS_H_
#define _DFS_H_
#include "trie.h"
#include "puzzle.h"
#include "linked_list.h"

// Recursive function that performs the DFS
void DFS(NodeTrie* node, char** grid, int rowsize, int colsize, int row, int col, char* word, int wordindex, LinkedList* result);

// Function that calls a DFS for each character of the puzzle and store the words found in a linked list
void solvePuzzle(NodeTrie* root, Puzzle* puzzle, LinkedList* result);

#endif
