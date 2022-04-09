#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

#include "trie.h"

trieNode* populateTrieFromDictionary(){
    int i;
    trieNode* root = NULL;

    // Populate the trie by reading the .txt file that contains all the words
    if ((root = malloc(sizeof(trieNode))) == NULL){
        printf("The dictionary could not be loaded because there is not enough memory.\n");
    }

    // We start setting all the possible children of the root node as NULL
    for (i = 0; i < 26; i++)
        root->child[i] = NULL;
    root->isEndOfWord = 0;

    int index;
    trieNode* tmp = root;

    // Dictionary file
    FILE* dict_file = fopen("10000_english_words_dataset.txt", "r+");

    // Dictionary file not opened
    if (dict_file == NULL){
        printf("Error opening dictionary");
    }

    // Store words from Dictionary file
    char word[50];

    while ((fscanf(dict_file, "%s", word)) != EOF){
        int wordLength = strlen(word);
        addWordToTrie(root, word, wordLength);
    }
    fclose(dict_file);
    return root;
}

void destroyTrie (trieNode* dictionary){
    trieNode* tmp = dictionary;
    // Recursively freeing allocated memory
    for (int i = 0; i < 52; i++)
        if (tmp->child[i] != NULL)
            destroyTrie (tmp->child[i]);
    free (tmp);
    tmp = NULL;
}

char* searchWord(trieNode *root, char* key){
    trieNode *pCrawl = root;
    for (int i = 0; key[i]!='\0'; i++){
        int index = (int)tolower(key[i]) - 'a';
        if (pCrawl->child[index]==NULL)
            return NULL;
        pCrawl = pCrawl->child[index];
    }

    if((pCrawl->isEndOfWord==1))
        return "IS IN THE PUZZLE";
    else
        return NULL;
}

void addWordToTrieFromUserInput(trieNode* root){

    // Aux variables
    int wordTypeChoiceAux;
    int wordLength;
    char word[50];

    printf("Enter the word to add: ");
    scanf("%s", word);
    wordLength = strlen(word);
    addWordToTrie(root, word, wordLength);
    FILE *dict_file=fopen("10000_english_words_dataset.txt","a");
    fprintf(dict_file,"\n%s ",word);
    fclose(dict_file);
}

void addWordToTrie(trieNode* root, char* word, int wordLength){
    int index;
    trieNode* tmp = root;
    for (int i = 0; i < wordLength; i++){
        index = (int)tolower(word[i]) - 'a';

        // Handle error cases
        if (index > 25 || index < 0)
            continue;

        // Insert character from word read from dictionary into Trie
        if (tmp->child[index] == NULL){
            // Create and initialize new next nodes for subsequent letter
            if ((tmp->child[index] = malloc(sizeof(trieNode))) == NULL)
                printf("Out of memory. Dictionary could not be loaded.\n");
            tmp = tmp->child[index];
            for (int j = 0; j < 26; j++)
                tmp->child[j] = NULL;
            tmp->isEndOfWord = 0;
        }
        else
            tmp = tmp->child[index];

        // If we arrive at the end of the word string, it means that this node needs to have the isEndOfWord flag
        if (i == wordLength - 1)
            tmp->isEndOfWord = 1;
    }
    tmp = root;
}

// Returns 1 if given node has any children
int haveChildren(trieNode* curr){
	for (int i = 0; i < 26; i++)
		if (curr->child[i])
			return 1;	// child found
	return 0;
}


// Helper function to print the word found
void printWord(char* str, int n)
{
   printf("\n");
   for(int i=0; i<n; i++)
   {
      printf("%c",str[i]);
   }
}
// Print all words in Trie
void printAllWords(trieNode* root, char* wordArray, int pos)
{
   if(root == NULL)
      return;
   if(root->isEndOfWord)
   {
      printWord(wordArray, pos);
   }
   for(int i=0; i<26; i++)
   {
      if(root->child[i] != NULL)
      {
         wordArray[pos] = i+'a';
         printAllWords(root->child[i], wordArray, pos+1);
      }
   }
}

// Recursive function to delete a string from the trie
int deleteWordFromTrie(trieNode **curr, char* str){
    // Utilizamos um ponteiro duplo, pois precisamos definir a raiz quando a triade estiver vazia
	// return if Trie is empty
	if (*curr == NULL)
		return 0;

	// if we have not reached the end of the string
	if (*str){
		// recur for the node corresponding to next character in
		// the string and if it returns 1, delete current node
		// (if it is non-leaf)
		if (*curr != NULL && (*curr)->child[*str - 'a'] != NULL &&
			deleteWordFromTrie(&((*curr)->child[*str - 'a']), str + 1) &&
			(*curr)->isEndOfWord == 0)
		{
			if (!haveChildren(*curr))
			{
				free(*curr);
				(*curr) = NULL;
				return 1;
			}
			else {
				return 0;
			}
		}
	}

	// if we have reached the end of the string
	if (*str == '\0' && (*curr)->isEndOfWord){
		// if current node is a leaf node and don't have any children
		if (!haveChildren(*curr)){
			free(*curr); // delete current node
			(*curr) = NULL;
			return 1; // delete non-leaf parent nodes
		}

		// if current node is a leaf node and have children
		else{
			// mark current node as non-leaf node (DON'T DELETE IT)
			(*curr)->isEndOfWord = 0;
			return 0;	   // don't delete its parent nodes
		}
	}
	return 0;
}

