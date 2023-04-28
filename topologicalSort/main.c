#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int count;
    int *items;
} Stack;

Stack *initStack(int numVertices) {
    Stack *newStack = malloc(sizeof (Stack));
    newStack->count = 0;
    newStack->items = malloc(numVertices * sizeof(int));
    return newStack;
}

void push(Stack *stack, int value) {
    stack->items[stack->count++] = value;
}

int pop(Stack *stack) {
    if (stack->count == 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[--stack->count];
}

int isEmpty(Stack *stack) {
    return stack->count == 0;
}

int **initMatrix(int numVertices){
    int** newMatrix = malloc(sizeof (int *) * numVertices);
    for (int i = 0; i < numVertices; i++){
        newMatrix[i] = calloc(numVertices, sizeof (int));
    }
    return newMatrix;
}

void readAdjMatrixFromFile(FILE* inputFile, int numEdges, int** adjMatrix){
    int u, v;
    for (int i = 0; i < numEdges; i++) {
        fscanf(inputFile, "%d %d", &u, &v);
        adjMatrix[u][v] = 1;
    }
}

void printMatrix(int numVertices, int **adjMatrix) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}


void dfs(int v, int numVertices, int **adjMatrix, int *visited, Stack* stack){
    if (v == 0)
        printf("DFS:\n");

    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < numVertices; i++){
        if (adjMatrix[v][i] == 1 && visited[i] == 0){
            dfs(i, numVertices, adjMatrix, visited, stack);
        }
    }

    push(stack, v);
}

void topologicalSort(int numVertices, int **adjMatrix){
    int *visited = calloc(numVertices, sizeof (int));
    Stack *stack = initStack(numVertices);

    for (int i = 0; i < numVertices; i++){
        if (visited[i] == 0){
            dfs(i, numVertices, adjMatrix, visited, stack);
        }
    }

    printf("\nTopological sort:\n");
    while(!isEmpty(stack)){
        printf("%d ", pop(stack));
    }
    printf("\n");

}

int main() {
    int numVertices, numEdges;

    FILE *inputFile = fopen("input.in", "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }
    fscanf(inputFile, "%d %d", &numVertices, &numEdges);

    int **adjMatrix = initMatrix(numVertices);
    readAdjMatrixFromFile(inputFile, numEdges, adjMatrix);

    printMatrix(numVertices, adjMatrix);
    printf("\n");
    topologicalSort(numVertices, adjMatrix);

    fclose(inputFile);
    return 0;
}

