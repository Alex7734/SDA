#ifndef LAB9_GRAPH_H
#define LAB9_GRAPH_H
#include <stdio.h>
#include <stdlib.h>
#include "single_linked_list.h"
#include "stack.h"
#include "queue.h"

#define WHITE 0
#define GREY 1
#define BLACK 2

typedef struct {
    int node;
    SLL_ENTRY entry;
} GraphVertex;

typedef struct {
    int numNodes;
    SL_LIST **adjList;
    int *color;
    int *inDegree;
} Graph;


#endif //LAB9_GRAPH_H
