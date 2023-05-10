#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int start, finish;
    char name[33];
} activitate;

void readActivitati(int* n, activitate* v){
    for (int i = 0; i < *n; i++){
        scanf("%d %d %s", &v[i].start, &v[i].finish, v[i].name);
    }
}

int compare(const void* a, const void* b){
    return ((activitate*)a)->finish - ((activitate*)b)->finish;
}


void planificare_activitati(activitate activitati[], int n) {
    qsort(activitati, n, sizeof(activitate), compare);

    printf("Activitati selectate:\n");
    activitate ultima_activitate = activitati[0];
    printf("%s\n", ultima_activitate.name);

    for (int i = 1; i < n; ++i) {
        if (activitati[i].start >= ultima_activitate.finish) {
            printf("%s\n", activitati[i].name);
            ultima_activitate = activitati[i];
        }
    }
}

int plan() {
    int n;
    printf("Introdu numarul de activitati:");
    scanf("%d", &n);
    printf("\n");

    activitate *v = malloc(sizeof(activitate) * n);
    readActivitati(&n, v);
    planificare_activitati(v, n);

    free(v);
    return 0;
}
