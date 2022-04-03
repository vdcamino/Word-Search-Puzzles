/*
#ifndef _TRIE_H_
#define _TRIE_H_

#define NUM_CHARACTERS 52   // 26 * 2 because to deal with uppercase letters as well as lowercase letters

typedef struct trieNode {
    struct trieNode* child[52];
    int isEndOfWord;
    int isInThePuzzle;
    char meaning[300];
} trieNode;

trieNode* load();

void unload_rec(trieNode* dict_rem);

char* search(trieNode* root, char* key);

void view();

void add(trieNode* root);

int haveChildren(trieNode* curr);

int deletion(trieNode** curr, char* str);

#endif

*/
