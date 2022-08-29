#include<stdio.h>
#include<stdlib.h>
#include "hashmap.h"

// Function that creates a new hash table
HashMap* createHashMap(int size){
    HashMap *map = (HashMap*) malloc(sizeof(HashMap));
    map->array = (NodeHashMap**) calloc(size, sizeof(NodeHashMap*));
    int i;
    for(i = 0; i < size; i++){
        map->array[i] = (NodeHashMap*)malloc(sizeof(NodeHashMap));
        map->array[i]->key = '\0';
        map->array[i]->val = NULL;
        map->array[i]->next = NULL;
    }
    map->size = size;
    map->count = 0;
    return map;
}

// Helper function that provides a hash code corresponding to a given key
int getHashCode(char key, int size){
    int primeNumber = 47;
    return ((int) key + primeNumber) % size;
}

// Function that finds whether the given (key, value) pair exists in the map
NodeHashMap* findNodeHashMap(NodeHashMap** array, char key, int index){
    NodeHashMap *current = array[index];
    while(current!=NULL){
        if(current->key == key)
            return current;
        current = current->next;
    }
    return NULL;
}

// Function that gets the value for the given key from the hash table
// It returns values of any type
void* get(HashMap *map, char key){
    NodeHashMap *current;
    int index = getHashCode(key, map->size);
    current = (NodeHashMap*)findNodeHashMap(map->array, key, index);
    if(current == NULL)
        return NULL;
    return current->val;
}

// Function that adds a new (key, value) pair to the hash table
void add(HashMap* map, char key, void* value){
    int index = getHashCode(key, map->size);
    NodeHashMap* curr = findNodeHashMap(map->array, key, index);
    if (curr == NULL){
        NodeHashMap *newnode, *head;
        head = map->array[index];
        newnode = (NodeHashMap*) malloc(sizeof(NodeHashMap));
        newnode->key = key;
        newnode->val = value;
        newnode->next = head->next;
        head->next = newnode;
        map->count++;
    } else
        curr->val = value;
}
