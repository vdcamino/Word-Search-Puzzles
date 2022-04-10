#ifndef _DFS_H_
#define _DFS_H_
#include "trie.h"
#include "puzzle.h"
#include "linked_list.h"

void dfs_lookup(trieNode* node, char** grid, int rowsize, int colsize, int row, int col, char* word, int wordindex, ListaEnc2Plus* result, int* returnsize);

// Driver function for dfs lookup, called from main
void findwords(trieNode* root, Puzzle* puzzle, int* returnsize, ListaEnc2Plus* result);

#endif
