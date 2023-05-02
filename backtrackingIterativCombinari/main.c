#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void afisare(int n, int *vec, int k){
    for (int i = 1; i <= k; i++){
        printf("%d ", vec[i]);
    }
    printf("\n");
}

bool isValid(int pos, int *vec){
    for (int i = 1; i < pos; i++){
        if (vec[pos] == vec[i]){
            return false;
        }
    }
    return true;
}

void backtracking(int n, int k, int *vec){
    int pos = 1;

    while (pos > 0){
        vec[pos]++;
        if (vec[pos] > n){
            pos--;
        } else if (pos == k){
            afisare(n, vec, k);
        } else {
            pos++;
            vec[pos] = vec[pos-1];
        }
    }
}

int main()
{
    int n, k;
    int *vec = NULL;

    scanf("%d%d", &n, &k);

    vec = (int*) calloc(k+1, sizeof(int));
    backtracking(n, k, vec);

    return 0;
}
