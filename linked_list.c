#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function that creates a list
LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

// Function that destroys a list
void destroyLinkedList(LinkedList* linkedList){
    NodeLinkedList* aux = linkedList->head;
    while (aux != NULL) {
        NodeLinkedList* tmp = aux->next;
        free(aux);
        aux = tmp;
    }
    free(linkedList);
}

// Function that prints all the nodes of a list
void printLinkedList(LinkedList* linkedList){
    NodeLinkedList* aux;
    printf("-----------------------------------------\n");
    for (aux = linkedList->head; aux != NULL; aux = aux->next)
        printf("(%s)\n", aux->word);
    printf("-----------------------------------------\n");
}

// Function that inserts a node at the beginning of a list
void insertStartLinkedList(LinkedList* linkedList, char* word){
    NodeLinkedList* newNode = (NodeLinkedList*)malloc(sizeof(NodeLinkedList));
    strcpy(newNode->word, word);
    newNode->prev = NULL;
    newNode->next = linkedList->head;
    if (linkedList->head != NULL)
        linkedList->head->prev = newNode;
    linkedList->head = newNode;
    linkedList->size += 1;
}

// Function that retrieves a node from a list based on the information it stores
NodeLinkedList* findNodeLinkedList(LinkedList* linkedList, char* word){
    NodeLinkedList* aux;
    for (aux = linkedList->head; aux != NULL; aux = aux->next)
        if (strcmp(aux->word, word))
            return aux;
    return NULL;
}

// Function that removes a node from a list based on the information it stores
int removeNodeLinkedList(LinkedList* linkedList, char word[]){
   NodeLinkedList *aux = linkedList->head;
   while(aux != NULL && strcmp(aux->word, word))
      aux = aux->next;
   if (aux != NULL){
      if (aux->prev == NULL){
         linkedList->head = aux->next;
         if (aux->next != NULL)
            aux->next->prev = NULL;
      }else{
         aux->prev->next = aux->next;
         if (aux->next != NULL)
            aux->next->prev = aux->prev;
      }
      free(aux);
      linkedList->size -= 1;
      return 1;
   }
   return 0; // Node was not found
}

// Function that returns the size of a linked list
int sizeLinkedList(LinkedList* linkedList) {
    return linkedList->size;
}
