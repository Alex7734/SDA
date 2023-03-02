#include <iostream>
using namespace std;

/*
 . Se citesc de la tastatura 2 numere, CAPACITY ³i SIZE. Sa se aloce dinamic un sir de CAPACITY elemente
reale. Sa se scrie o functie care adauga un element in sir, pe prima pozitie a sirului (cea cu indicele 0).
Folosind functia creata sa se insereze in sir SIZE numere. Ce se intampla daca CAP ACIT Y ≥ SIZE si
daca CAP ACIT Y < SIZE. Asati sirul de numere dupa ecare inserare
 */

void writeArr(int size, double* arr){
    for (int j = 0; j < size; j++){
        printf("%lf ", arr[j]);
    }
    printf("\n");
}

double* initArr(int size){
    double* arr = (double*) calloc(size,sizeof(double));
    return arr;
}

void addElement(double** arr, int* capacity,  int* size, double element){
    if (*size == *capacity){
        *capacity *= 2;
        double* newArr = (double*) realloc(*arr, (*capacity) * sizeof(double));
        if (newArr == NULL){
            printf("Error: Memory allocation failed");
            exit(1);
        }
        *arr = newArr;
    }

    // Well all I had to change is this, now the addition is in O(n) not O(1)
    for (int i=*size; i>=1; i--){
        (*arr)[i] = (*arr)[i-1]; // Error to remember:
    }
    *arr[0] = element;
    (*size)++; // stupid error ( maybe tierd or just blind )
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
    It does not run and I do not understand the error:( not good enough to debug it
 */