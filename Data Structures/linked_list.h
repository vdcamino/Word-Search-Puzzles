#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

typedef struct NodeLinkedList {
	char word[50];
	struct NodeLinkedList* prev;
	struct NodeLinkedList* next;
} NodeLinkedList;

typedef struct LinkedList {
	struct NodeLinkedList* head;
	int size;
} LinkedList;

// Function that creates a list
LinkedList* createLinkedList();

// Function that destroys a list
void destroyLinkedList(LinkedList* linkedList);

// Function that prints all the nodes of a list
void printLinkedList(LinkedList* linkedList);

// Function that inserts a node at the beginning of a list
void insertStartLinkedList(LinkedList* linkedList, char* word);

// Function that retrieves a node from a list based on the information it stores
NodeLinkedList* findNodeLinkedList(LinkedList* linkedList, char* word);

// Function that removes a node from a list based on the information it stores
int removeNodeLinkedList(LinkedList* linkedList, char* word);

// Function that returns the size of a linked list
int sizeLinkedList(LinkedList* linkedList);

#endif
