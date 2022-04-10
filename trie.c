#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

#include "trie.h"

// Initialize a new trie node
trieNode* inittrienode(char ch){
    trieNode *node = (trieNode*) malloc(sizeof(trieNode));
    node->ch = ch;
    node->children = inithashmap(26);
    node->endofword = false;
}

trieNode* populateTrieFromDictionary(){
    // Add all words to be found into the trie
    trieNode *root = inittrienode('*');
    // Dictionary file
    FILE* dict_file = fopen("10000_english_words_dataset.txt", "r+");

    // Dictionary file not opened
    if (dict_file == NULL) {
        printf("Error opening dictionary");
    }
    // Store words from Dictionary file
    char wordZ[50];
    while ((fscanf(dict_file, "%s", wordZ)) != EOF) {
        addtotrie(root, wordZ);
    }
    fclose(dict_file);
    return root;
}

void destroyTrie (trieNode* dictionary){
    /*
    trieNode* tmp = dictionary;
    // Recursively freeing allocated memory
    for (int i = 0; i < 26; i++)
        if (tmp->children[i] != NULL)
            destroyTrie (tmp->children[i]);
    free (tmp);
    tmp = NULL;
    */
}

/*
char* searchWord(trieNode *root, char* key){
    trieNode *pCrawl = root;
    for (int i = 0; key[i]!='\0'; i++){
        int index = (int)tolower(key[i]) - 'a';
        if (pCrawl->children[index]==NULL)
            return NULL;
        pCrawl = pCrawl->children[index];
    }

    if((pCrawl->isEndOfWord==1))
        return "IS IN THE PUZZLE";
    else
        return NULL;
}
*/
/*
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
*/

// Add given word to the trie
void addtotrie(trieNode* root, char word[]){
    trieNode *curr, *child;
    int i = 0;
    curr = root;
    while (word[i] != '\0'){
        trieNode *node = (trieNode*)get(curr->children, word[i]);

        if(node == NULL){
            trieNode *newnode = inittrienode(word[i]);
            add(curr->children, word[i], newnode);
            curr = newnode;
        }
        else{
            curr = node;
        }
        i++;
    }
    curr->endofword = true;
}

/*
// Returns 1 if given node has any children
int haveChildren(trieNode* curr){
	for (int i = 0; i < 26; i++)
		if (curr->children[i])
			return 1;	// child found
	return 0;
}
*/


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
void printAllWords(trieNode* root, char* wordArray, int pos){
    if(root == NULL)
        return;

    // If this character marks the end of a word in the trie, it means we have found the word in the grid. Add it to results.
    if (root->endofword) {
        wordArray[pos + 1] = '\0';
        printWord(wordArray, pos);
        root->endofword = false;
    }
    for(int i=0; i<26; i++){
        char current_char = i+'a';
        trieNode* child = (trieNode*)get(root->children, current_char);

        // Add current grid character to the word being formed
        if (child != NULL){
            wordArray[pos] = current_char;
            printAllWords((trieNode*)get(root->children, current_char), wordArray, pos+1);
        }
    }
}


/*
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
*/
