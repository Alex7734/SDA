//#include <stdio.h>
//#include <stdio.h>
//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//#include "single_linked_list.h"
//#include "stack.h"
//#include "int_stack.h"
//#include "double_linked_list.h"
//
//typedef struct{
//    int node;
//    DLL_ENTRY dll_entry;
//} GRAPH_VERTEX;
//
//typedef struct{
//    int nrNodes;
//    DL_LIST **neighbors; // Pointer to a list of lists
//    int *visited;
//    int *piVector; // vector of parents
//} GRAPH;
//
//typedef enum {
//    GRAPH_COLOR_WHITE,
//    GRAPH_COLOR_GREY,
//    GRAPH_COLOR_BLACK
//} GRAPH_COLORS;
//
//GRAPH* createGraph(int nrNodes){
//    GRAPH *graph = (GRAPH*) malloc(sizeof (GRAPH));
//
//    if (graph){
//        graph->nrNodes = nrNodes;
//        graph->neighbors = (DL_LIST **) malloc(sizeof (DL_LIST *) * nrNodes);
//        if (graph->neighbors != NULL){
//            for (int i = 0; i < nrNodes ; i++){
//                graph->neighbors[i] = dll_create_list();
//            }
//        }
//
//        graph->visited = (int *) malloc(sizeof (int) * nrNodes);
//        if (graph->visited != NULL){
//            memset(graph->visited, GRAPH_COLOR_WHITE, nrNodes*sizeof(int));
//        }
//
//        graph->piVector = (int *) malloc(sizeof(int) * nrNodes);
//        if (graph->piVector != NULL){
//            memset(graph->piVector, -1, sizeof(int) * nrNodes);
//        }
//    }
//
//    return graph;
//}
//
//GRAPH_VERTEX *createVertex(int value){
//    GRAPH_VERTEX *vertex = (GRAPH_VERTEX *) malloc(sizeof (GRAPH_VERTEX));
//
//    if (vertex != NULL){
//        memset(vertex, 0, sizeof (GRAPH_VERTEX));
//        vertex->node = value;
//    }
//
//    return vertex;
//}
//
//void graphAddEdge(GRAPH *graph, int x, int y){
//    if (graph == NULL){
//        return;
//    }
//
//    GRAPH_VERTEX *neighborOfX = createVertex(y);
//    GRAPH_VERTEX *neighborOfY = createVertex(x);
//    dll_insert_first(graph->neighbors[x], &neighborOfX->dll_entry);
//    dll_insert_first(graph->neighbors[y], &neighborOfY->dll_entry);
//
//}
//
//void graphAddArc(GRAPH *graph, int x, int y){
//    if (graph == NULL){
//        return;
//    }
//
//    GRAPH_VERTEX *neighborOfX = createVertex(y);
//    dll_insert_first(graph->neighbors[x], &neighborOfX->dll_entry);
//}
//
//void graphDFS_iterative(GRAPH *graph, int start){
//    GRAPH_VERTEX *neighbors = NULL;
//    DLL_ENTRY *entry = NULL;
//    STACK *stack = create_stack();
//    int node;
//
//    graph->piVector[start] = -1; // Set the start node's dad as -1
//
//    push_int(stack, start);
//    while (stack_get_size(stack) != 0){
//        node = pop_int(stack);
//        if (graph->visited[node] == GRAPH_COLOR_WHITE){
//            graph->visited[node] = GRAPH_COLOR_GREY;
//            printf("%d ", node);
//            graph->visited[node] = GRAPH_COLOR_BLACK;
//
//            entry = dll_get_last(graph->neighbors[node]);
//            while (entry != NULL){
//
//                neighbors = CONTAINING_RECORD(entry, GRAPH_VERTEX, dll_entry);
//                if (graph->visited[neighbors->node] == GRAPH_COLOR_WHITE){
//                    graph->piVector[neighbors->node] = node;
//                    push_int(stack, neighbors->node);
//                }
//
//                entry = entry->prev;
//            }
//        }
//    }
//}
//
//
//void printPiVector(GRAPH *graph){
//    for (int i = 0; i < graph->nrNodes; i++){
//        printf("%d ", graph->piVector[i]);
//    }
//}
//
//int main() {
//    GRAPH *graph = NULL;
//    int nrNodes, nrEdges;
//
//    FILE *fin = NULL;
//    fin = fopen("input.in", "r");
//    if (fin == NULL){
//        perror("Error file open");
//        return -1;
//    }
//
//    fscanf(fin, "%d %d", &nrNodes, &nrEdges);
//    graph = createGraph(nrNodes);
//
//
//
//
//    for (int i = 0; i < nrEdges ; i++){
//        int x, y;
//        fscanf(fin, "%d %d", &x, &y);
//        graphAddEdge(graph, x, y);
//    }
//
//    graphDFS_iterative(graph, 1);
//    printf("\n");
//    printPiVector(graph);
//
//    return 0;
//}
