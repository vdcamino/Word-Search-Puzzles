#ifndef _TRIE_H_
#define _TRIE_H_

#include "hashmap.h"

typedef struct NodeTrie {
    char letter;
    int isEndOfWord;
    HashMap *children;
} NodeTrie;

// Function that initializes a new trie node
NodeTrie* createNodeTrie(char letter);

// Function that adds a given word to the trie
void addToTrie(NodeTrie* root, char word[]);

// Function that populates a trie based on the words stored in the .txt file
NodeTrie* populateTrieFromDictionary();

// Function that destroys a trie
void destroyTrie (NodeTrie* root);

// Function that adds a given word to the trie based on user input and stores it in the .txt file
void addToTrieFromUserInput(NodeTrie* root);

// Helper function to print the word found
void printWord(char* word);

// Print all words in Trie
void printAllWordsOfTrie(NodeTrie* root, char* wordArray, int index);

// Function that verifies if a node has children or not. It returns 1 if it has; 0 if it does not
int haveChildren(NodeTrie* root);

// Recursive function to delete a string from the trie
int deleteWordFromTrie(NodeTrie* root, char* word);

#endif
