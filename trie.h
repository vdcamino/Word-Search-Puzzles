#ifndef _TRIE_H_
#define _TRIE_H_

#define NUM_CHARACTERS 26   // 26 the English alphabet has 26 letters and we are dealing only with lowercase letters

#include "hashmap.h"
#include <stdbool.h>

typedef struct trieNode {
    char ch;
    bool endofword;
    hashmap *children;
} trieNode;

trieNode* inittrienode(char);

void addtotrie(trieNode*, char[]);

trieNode* populateTrieFromDictionary();

void destroyTrie (trieNode* dictionary);

char* searchWord(trieNode *root, char* key);

void addWordToTrie(trieNode* root, char *word, int wordLength);

void addWordToTrieFromUserInput(trieNode* root);

int haveChildren(trieNode* curr);

int deleteWordFromTrie(trieNode **curr, char* str);

void printAllWords(trieNode* root, char* wordArray, int pos);

void printWord(char* str, int n);

#endif
