#ifndef _TRIE_H_
#define _TRIE_H_

#define NUM_CHARACTERS 26   // 26 the English alphabet has 26 letters and we are dealing only with lowercase letters

typedef struct trieNode {
    struct trieNode* child[26];
    int isEndOfWord;
    int isInThePuzzle;
} trieNode;

trieNode* populateTrieFromDictionary();

void destroyTrie (trieNode* dictionary);

char* searchWord(trieNode *root, char* key);

void view();

void add(trieNode* root);

void addWordToTrie(trieNode* root, char *word, int wordLength);

void addWordToTrieFromUserInput(trieNode* root);

int haveChildren(trieNode* curr);

int deleteWordFromTrie(trieNode **curr, char* str);

void printAllWords(trieNode* root, char* wordArray, int pos);

void printWord(char* str, int n);

#endif
