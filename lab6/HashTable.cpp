#include "HashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h" // for memset
#include "stdbool.h"
#define EMPTY (-1)
#define DELETED (-2)

int h_func(HASH_TABLE *hash, int key){
    return key & hash->modulo;
}

int p_func(HASH_TABLE *hash, int key, int attempt){
    return (hash->h_func(hash, key) + attempt) % hash->modulo;
}

int initHashTable(HASH_TABLE *hash){
    memset(hash, 0 , sizeof(HASH_TABLE));
    hash->modulo = M;
    hash->h_func = h_func;
    hash->p_func = p_func;
    memset(hash->table, EMPTY, sizeof(hash->table));
    return 0;
}

int hashInsert(HASH_TABLE *hash, int key){
    int pos;

    for (int att = 0; att<M ; att++){
        pos = hash->p_func(hash, key, att);

        if (hash->table[pos] == EMPTY || hash->table[pos] == DELETED){
            hash->table[pos] = key;
            return 0;
        }
    }

    return -1;
}

// 1 - found
// 0 - not found
bool hashSearch(HASH_TABLE *hash, int key){
    int pos;

    for (int att = 0; att<M ; att++){
        pos = hash->p_func(hash, key, att);

        if (hash->table[pos] == EMPTY){
            return false;
        }

        if (hash->table[pos] == key){
            return true;
        }
    }

    return false;
}

int hashDelete(HASH_TABLE *hash, int key){
    int pos;

    for (int att = 0; att<M ; att++){
        pos = hash->p_func(hash, key, att);

        if (hash->table[pos] == EMPTY){
            break;
        }

        if (hash->table[pos] == key){
            hash->table[pos] = DELETED;
            break;
        }
    }

    return 0;
}



/*
    With chaining
void insertElement(NodeT* hTable[M], int key) {
    int index = key % M;
    NodeT* newNode = (NodeT*) malloc(sizeof(NodeT));
    newNode->key = key;
    newNode->next = hTable[index];
    hTable[index] = newNode;
}

NodeT* findElement(NodeT* hTable[M], int key) {
    int index = key % M;
    NodeT* node = hTable[index];
    while (node != NULL) {
        if (node->key == key) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void deleteElement(NodeT* hTable[M], int key) {
    int index = key % M;
    NodeT* node = hTable[index];
    NodeT* prev = NULL;
    while (node != NULL) {
        if (node->key == key) {
            if (prev == NULL) {
                hTable[index] = node->next;
            } else {
                prev->next = node->next;
            }
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}
*/
