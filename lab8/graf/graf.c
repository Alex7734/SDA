#include "graf.h"
#include "stdlib.h"
#include "string.h"
#include "../single_linked_list/single_linked_list.h"
#include "../queue/queue.h"

GRAF *createGraf(int nrNodes){
    GRAF *graf = (GRAF *) malloc(sizeof(GRAF));

    if (graf != NULL){
        graf->nrNodes = nrNodes;
        graf->neighbors =(SL_LIST**) malloc(nrNodes* sizeof(SL_LIST *));
        if (graf->neighbors != NULL){
            for (int i = 0; i < nrNodes; i++){
                graf->neighbors = sll_create_list();
            }
        }
    }

    return graf;
}

NEIGHBOR *createNeighbor(int neighbor){
    NEIGHBOR *node = (NEIGHBOR*) malloc(sizeof(NEIGHBOR));

    if (node != NULL){
        memset(node, 0, sizeof(NEIGHBOR));

        node->neighbor = neighbor;
    }

    return node;
}

void grafAddEdge(GRAF *graf, int x, int y){
    if (graf == NULL){
        return;
    }

    NEIGHBOR *first = createNeighbor(x);
    NEIGHBOR *last = createNeighbor(y);

    sll_create_list(graf->neighbors[x], &last->entry);
    sll_create_list(graf->neighbors[y], &first->entry);
}




