#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100

int adj_matrix[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int queue[MAX_NODES];

int n;

void bfs(int start) {
    int front = 0, rear = -1;
    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear) {
        int current = queue[front++];
        printf("%d ", current+1);
        for (int i = 0; i < n; i++) {
            if (adj_matrix[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    FILE *f = fopen("graf.txt", "r");
    fscanf(f, "%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(f, "%d", &adj_matrix[i][j]);
        }
    }
    fclose(f);

    int start;
    printf("Introduceti nodul de start: ");
    scanf("%d", &start);

    bfs(start-1);

    printf("\n");

    return 0;
}

