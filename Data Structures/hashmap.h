#ifndef HASHMAP_H_
#define HASHMAP_H_ "hashmap.h"
typedef struct NodeHashMap{
    char key;
    void* val;
    struct NodeHashMap *next;
} NodeHashMap;

typedef struct HashMap{
    int size;
    int count;
    NodeHashMap **array;
}HashMap;

// Function that creates a new hash table
HashMap* createHashMap(int size);

// Function that gets the value for the given key from the hashmap
// It returns values of any type
void* get(HashMap *map, char key);

// Function that adds a new (key, value) pair to the hash table
void add(HashMap* map, char key, void* value);

#endif
