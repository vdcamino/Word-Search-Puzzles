#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "trie.h"

// Function that initializes a new trie node
NodeTrie* createNodeTrie(char letter){
    NodeTrie *node = (NodeTrie*) malloc(sizeof(NodeTrie));
    node->letter = letter;
    node->children = createHashMap(26); // 26 because the English alphabet has 26 letters and we are dealing only with lowercase letters
    node->isEndOfWord = 0;
}

// Function that adds a given word to the trie
void addToTrie(NodeTrie* root, char word[]){
    NodeTrie *curr = root;
    int i = 0;
    while (word[i] != '\0'){    // We go through all the characters of the strings we want to store in the trie
        NodeTrie *node = (NodeTrie*)get(curr->children, word[i]);   // We verify if the current node already has a child corresponding to the current letter we want to add
        if(node == NULL){   // If it does not exist, we add it to the trie
            NodeTrie *newNode = createNodeTrie(word[i]);
            add(curr->children, word[i], newNode);  // Add the new node as a child of the current node (it will then be accessible via the hash table)
            curr = newNode;
        } else
            curr = node;    // If it already exists, we continue to explore this branch of the trie
        i++;
    }
    curr->isEndOfWord = 1;  // Once we have finished inserting all the nodes/letters of the word in the trie, we set a flag indicating that this last node is the end of a word
}

// Function that populates a trie based on the words stored in the .txt file
NodeTrie* populateTrieFromDictionary(){
    NodeTrie *root = createNodeTrie('*'); // The first node of the trie can contain no matter what symbol/letter
    FILE* dict_file = fopen("10000_english_words_dataset.txt", "r+");   // Try to open the dictionary file
    if (dict_file == NULL)  // In case dictionary file could not be opened
        printf("Error opening dictionary");
    char word[50];  // Temporary string to retrieve words from the file and then add it to the trie
    while ((fscanf(dict_file, "%s", word)) != EOF)  // Parse the whole dictionary
        addToTrie(root, word);
    fclose(dict_file);  // Close dictionary
    return root;    // Return the trie's head node
}

// Function that destroys a trie
void destroyTrie (NodeTrie* root){
    NodeTrie* tmp = root;
    char current_char;
    for (int i = 0; i < 26; i++){   // Recursively freeing allocated memory
        current_char = i + 'a';
        if (get(tmp->children, current_char) != NULL) // Verify if this node has children
            destroyTrie (get(tmp->children, current_char));
    }
    free(tmp);
}

// Function that adds a given word to the trie based on user input and stores it in the .txt file
void addToTrieFromUserInput(NodeTrie* root){
    char word[50];
    printf("Enter the word to add: ");
    scanf("%s", word);
    addToTrie(root, word);
    FILE *dict_file=fopen("10000_english_words_dataset.txt","a");
    fprintf(dict_file,"\n%s ",word);
    fclose(dict_file);
}

// Helper function to print the word found
void printWord(char* word){
    printf("\n");
    for(int i = 0; i < strlen(word); i++)
        printf("%c", word[i]);
}

// Print all words in Trie
void printAllWordsOfTrie(NodeTrie* root, char* wordArray, int index){
    if (root == NULL)
        return;
    if (root->isEndOfWord) {
        wordArray[index + 1] = '\0';
        printWord(wordArray);
        root->isEndOfWord = 0;
    }
    char current_char;
    for (int i = 0; i < 26; i++){
        current_char = i + 'a';
        NodeTrie* child = (NodeTrie*)get(root->children, current_char);
        if (child != NULL){
            wordArray[index] = current_char;
            printAllWordsOfTrie((NodeTrie*)get(root->children, current_char), wordArray, index + 1);
        }
    }
}

// Function that verifies if a node has children or not. It returns 1 if it has; 0 if it does not
int haveChildren(NodeTrie* root){
    char current_char;
    for (int i = 0; i < 26; i++){
        current_char = i + 'a';
        NodeTrie* possibleChild = (NodeTrie*)get(root->children, current_char);
        if (possibleChild != NULL)
            return 1;
    }
    return 0;   // If any of the alphabet letters is child of the node, we return 0 indicating it has not any child
}

// Recursive function to delete a string from the trie
int deleteWordFromTrie(NodeTrie* root, char word[]){
    int lastIndexBeforeEndOfWord = strlen(word);
    int i = 0;
    NodeTrie *curr = root;
    while (word[i] != '\0'){    // We go through all the characters of the strings we want to store in the trie
        NodeTrie *node = (NodeTrie*)get(curr->children, word[i]);   // We verify if the current node already has a child corresponding to the current letter we want to add
        curr = node;
        if(curr->isEndOfWord && i < strlen(word))
            lastIndexBeforeEndOfWord = i;
        i++;
    }
    i = 0;  // Reset the counting because this time we know where to stop
    curr = root;
    NodeTrie *aux;
    while (word[i] != '\0'){    // We go through all the characters of the strings we want to store in the trie
        aux = (NodeTrie*)get(curr->children, word[i]);   // We verify if the current node already has a child corresponding to the current letter we want to add
        if (aux == NULL)
            return 0;   // Treats error if we could not access the node
        if(i > lastIndexBeforeEndOfWord)
            free(curr);
        curr = aux;
        i++;
    }
    return 1;
}

