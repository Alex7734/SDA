#include <iostream>
using namespace std;

void writeArr(int size, double* arr){
    for (int j = 0; j < size; j++){
        printf("%lf ", arr[j]);
    }
    printf("\n");
}

double* initArr(int size){
    double* arr = (double*) malloc(size * sizeof(double));
    return arr;
}

void addElement(double** arr, int* capacity, int* size, double element){
    if (*size == *capacity){
        *capacity *= 2;
        double* newArr = (double*) realloc(*arr, (*capacity) * sizeof(double));
        if (newArr == NULL){
            printf("Error: Memory allocation failed");
            exit(1);
        }
        *arr = newArr;
    }

    (*arr)[(*size)++] = element;
}

int main(){
    int currSize, capacity, size;
    currSize = 0;

    printf("Capacity: ");
    scanf("%d", &capacity);

    printf("Size: ");
    scanf("%d", &size);

    double* arr = initArr(capacity);
    for (int i = 0; i < size; i++){
        double element;
        printf("Enter element %d: ", i+1);
        scanf("%lf", &element);

        addElement(&arr, &capacity, &currSize, element);
        writeArr(currSize, arr);
    }

    free(arr);
    return 0;
}

/*
    What is there to observe?
        Firs of all when the cap>=size the dinamic arr will not change it's cap during the execution as the if block on
        the line 17. Whereas when the cap<size the cap of the arr changes accordingly.

 */