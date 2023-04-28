#ifndef GRAF_H_INCLUDED
#define GRAF_H_INCLUDED
#include "../queue/queue.h"
#include "../single_linked_list/single_linked_list.h"

typedef struct {
    int nrNodes;
    SL_LIST **neighbors; // Array of lists
} GRAF;

typedef struct {
    int neighbor;
    SLL_ENTRY entry;
} NEIGHBOR;


#endif // GRAF_H_INCLUDED
