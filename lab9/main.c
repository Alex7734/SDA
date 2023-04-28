#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NODES 100

struct Graph {
    int num_nodes;
    int **adj_matrix;
};

void init_graph(struct Graph *g, int n) {
    if (n > MAX_NODES){
        printf("Too many nodes!");
        return;
    }
    g->num_nodes = n;

    int** matrix = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*) malloc(n * sizeof(int));
    }

    g->adj_matrix = matrix;
    if (g->adj_matrix == NULL){
        printf("Failed to allocate matrix!");
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g->adj_matrix[i][j] = 0;
        }
    }
}

void add_edge(struct Graph *g, int src, int dest) {
    g->adj_matrix[src][dest] = 1;
}

void dfs_recursive(int node, struct Graph *g, int *visited, int *stack, int *stack_top) {
    visited[node] = 1;
    for (int i = 0; i < g->num_nodes; i++) {
        if (g->adj_matrix[node][i] && !visited[i]) {
            dfs_recursive(i, g, visited, stack, stack_top);
        }
    }
    stack[++(*stack_top)] = node;
}

void reverse_graph(struct Graph *g, struct Graph *rev_g) {
    for (int i = 0; i < g->num_nodes; i++) {
        for (int j = 0; j < g->num_nodes; j++) {
            rev_g->adj_matrix[i][j] = g->adj_matrix[j][i];
        }
    }
}

void dfs_scc(int node, struct Graph *g, int *visited, int *scc) {
    visited[node] = 1;
    scc[node] = 1;
    for (int i = 0; i < g->num_nodes; i++) {
        if (g->adj_matrix[node][i] && !visited[i]) {
            dfs_scc(i, g, visited, scc);
        }
    }
}

void kosaraju(struct Graph *graf) {
    int visited[MAX_NODES] = {0};
    int stack[MAX_NODES];
    int scc[MAX_NODES] = {0};
    int scc_count = 0;
    int stack_top = -1;

    for (int i = 0; i < graf->num_nodes; i++) {
        if (!visited[i]) {
            dfs_recursive(i, graf, visited, stack, &stack_top);
        }
    }

    struct Graph rev_graf;
    init_graph(&rev_graf, graf->num_nodes);
    reverse_graph(graf, &rev_graf);

    for (int i = 0; i < graf->num_nodes; i++) {
        visited[i] = 0;
    }

    while (stack_top >= 0) {
        int node = stack[stack_top];
        if (!visited[node]) {
            dfs_scc(node, &rev_graf, visited, scc);
            scc_count++;
        }
        stack_top--;
    }

    printf("Number of strongly connected components: %d\n", scc_count);
}

int main() {
    struct Graph graf;
    int n, m, u, v;
    FILE *f = fopen("input.in", "r");

    fscanf(f, "%d", &n);
    fscanf(f,"%d", &m);
    init_graph(&graf, n);


    for (int i = 0; i < m; i++) {
        fscanf(f, "%d %d", &u, &v);
        add_edge(&graf, u, v);
    }

    kosaraju(&graf);
    fclose(f);
    return 0;
}