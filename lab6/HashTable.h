#ifndef LAB6_HASHTABLE_H
#define LAB6_HASHTABLE_H
#include "stdbool.h"
#define M 100 // max has size

typedef struct _hash HASH_T;
typedef int (*hashFunction)(HASH_T *hash, int key);
typedef int (*probingFunction)(HASH_T *hash, int key, int attempt);

typedef struct _hash{
    int modulo;
    int table[M];
    int size;
    hashFunction h_func;
    probingFunction p_func;
} HASH_TABLE;

typedef struct NodeT {
    int key;
    struct NodeT* next;
} NodeT;

int initHashTable(HASH_TABLE *hash);
int hashInsert(HASH_TABLE *hash, int key);
bool hashSearch(HASH_TABLE *hash, int key);
int hashDelete(HASH_TABLE *hash, int key);


/*
    With chaining
void insertElement(NodeT* hTable[M], int key);
NodeT* findElement(NodeT* hTable[M], int key);
void deleteElement(NodeT* hTable[M], int key);
*/


#endif //LAB6_HASHTABLE_H
