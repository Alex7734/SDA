#include <stdlib.h>
#include <stdio.h>
#define MAX_NODES 1000
#define MAX_EDGES 10000
#define INF 10000000

typedef struct edge {
    int start_node, end_node, weight;
    int next_edge;
} Edge;

typedef struct node {
    int node_id;
    int distance;
} Node;

typedef struct graph {
    int num_nodes, num_edges;
    int first_edge[MAX_NODES];
    Edge edges[MAX_EDGES];
} Graph;

typedef struct heap{
    int heap_size;
    Node heap_nodes[MAX_EDGES];
    int node_positions[MAX_EDGES];
} Heap;

void initializeGraph(Graph* graph, int num_nodes){
    graph->num_nodes = num_nodes;
    graph->num_edges = 0;
    for (int i=0; i<num_nodes; i++){
        graph->first_edge[i] = -1;
    }
}

void addEdgeToGraph(Graph *graph, int start_node, int end_node, int weight) {
    int edge_index = graph->num_edges++;
    graph->edges[edge_index].start_node = start_node;
    graph->edges[edge_index].end_node = end_node;
    graph->edges[edge_index].weight = weight;
    graph->edges[edge_index].next_edge = graph->first_edge[start_node];
    graph->first_edge[start_node] = edge_index;
}

int getParent(int i){
    return (i - 1) / 2;
}

int getLeftChild(int i) {
    return (2*i + 1);
}

int getRightChild(int i) {
    return (2*i + 2);
}

void initializeHeap(Heap *heap) {
    heap->heap_size = 0;
}

void pushNodeToHeap(Heap *heap, Node node){
    int child_index = heap->heap_size++;
    while (child_index > 0){
        int parent_index = getParent(child_index);
        if (heap->heap_nodes[parent_index].distance <= node.distance){
            break;
        }
        heap->heap_nodes[child_index] = heap->heap_nodes[parent_index];
        heap->node_positions[heap->heap_nodes[child_index].node_id] = child_index;
        child_index = parent_index;
    }
    heap->heap_nodes[child_index] = node;
    heap->node_positions[node.node_id] = child_index;
}

Node popNodeFromHeap(Heap *heap){
    Node result_node = heap->heap_nodes[0];
    heap->heap_size--;
    Node last_node = heap->heap_nodes[heap->heap_size];
    int parent_index = 0;
    while (getLeftChild(parent_index) < heap->heap_size){
        int left_child_index = getLeftChild(parent_index);
        int right_child_index = getRightChild(parent_index);
        int smallest_child_index = left_child_index;
        if (right_child_index < heap->heap_size && heap->heap_nodes[right_child_index].distance < heap->heap_nodes[left_child_index].distance){
            smallest_child_index = right_child_index;
        }
        if (heap->heap_nodes[smallest_child_index].distance >= last_node.distance){
            break;
        }
        heap->heap_nodes[parent_index] = heap->heap_nodes[smallest_child_index];
        heap->node_positions[heap->heap_nodes[parent_index].node_id] = parent_index;
        parent_index = smallest_child_index;
    }
    heap->heap_nodes[parent_index] = last_node;
    heap->node_positions[last_node.node_id] = parent_index;
    return result_node;
}

// Other functions remain unchanged ...

void prim(Graph *graph, int start_node, int *distances, int *parents) {
    Heap heap;
    initializeHeap(&heap);
    for (int i = 0; i < graph->num_nodes; i++) {
        distances[i] = INF;
        parents[i] = -1;
    }
    distances[start_node] = 0;
    pushNodeToHeap(&heap, (Node) {start_node, 0});
    while (heap.heap_size > 0) {
        Node current_node = popNodeFromHeap(&heap);
        if (distances[current_node.node_id] != current_node.distance) {
            continue;
        }
        for (int i = graph->first_edge[current_node.node_id]; i != -1; i = graph->edges[i].next_edge) {
            // Changed loop condition and iteration to use the 'next_edge' field
            Edge edge = graph->edges[i];
            int neighbor_node = edge.end_node;
            if (distances[neighbor_node] > edge.weight) {
                distances[neighbor_node] = edge.weight;
                parents[neighbor_node] = i;
                pushNodeToHeap(&heap, (Node) {neighbor_node, distances[neighbor_node]});
            }
        }
    }
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Failed to open input file\n");
        return 1;
    }
    int num_nodes, num_edges;
    fscanf(input_file, "%d %d", &num_nodes, &num_edges);
    Graph graph;
    initializeGraph(&graph, num_nodes);
    for (int i = 0; i < num_edges; i++) {
        int start_node, end_node, weight;
        fscanf(input_file, "%d %d %d", &start_node, &end_node, &weight);
        addEdgeToGraph(&graph, start_node, end_node, weight);
        addEdgeToGraph(&graph, end_node, start_node, weight);
    }
    fclose(input_file);


    int distances[num_nodes], parents[num_nodes];
    prim(&graph, 0, distances, parents);

    printf("Minimum Spanning Tree:\n");
    for (int i = 1; i < num_nodes; i++) {
        int parent_edge = parents[i];
        printf("%d - %d (%d)\n", graph.edges[parent_edge].start_node, graph.edges[parent_edge].end_node, graph.edges[parent_edge].weight);
    }

    return 0;
}