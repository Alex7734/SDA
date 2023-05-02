#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void afisare(int n, int *vec){
    for (int i = 1; i <= n; i++){
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
    bool valid = false;

    while (pos > 0){

        valid = false;
        while (vec[pos] < k && valid == false){
            vec[pos]++;
            valid = isValid(pos, vec);
        }

        if (valid == false){
            vec[pos] = 0;
            pos--;
        } else {
            if(pos == n){
                afisare(n, vec);
            } else {
                pos++;
            }
        }
    }
}

int main()
{
    int n, k;
    int *vec = NULL;

    scanf("%d %d", &n, &k);

    vec = (int*) calloc(n+1, sizeof(int));
    backtracking(n, k, vec);

    return 0;
}
