#include <iostream>

int search(const int* arr, int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

void insertFirst(int** arr, int* size, int* capacity, int key) {
    if (*size == *capacity) {
        *capacity *= 2;
        *arr = (int*) realloc(*arr, sizeof(int) * (*capacity));
    }
    int i;
    for (i = *size - 1; i >= 0; i--) {
        (*arr)[i + 1] = (*arr)[i];
    }
    (*arr)[0] = key;
    (*size)++;
}

void insertLast(int** arr, int* size, int* capacity, int key) {
    if (*size == *capacity) {
        *capacity *= 2;
        *arr = (int*)realloc(*arr, (*capacity) * sizeof(int));
    }
    (*arr)[*size] = key;
    (*size)++;
}

void deleteFirst(int** arr, int* size) {
    if (*size == 0) {
        printf("The array is empty\n");
        return;
    }
    for (int i = 0; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }
    (*size)--;
}

void deleteLast(int** arr, int* size) {
    if (*size == 0) {
        printf("The array is empty\n");
        return;
    }
    (*size)--;
}

void deleteKey(int** arr, int* size, int key) {
    int* new_arr = nullptr;
    int new_size = 0;
    for (int i = 0; i < *size; i++) {
        if ((*arr)[i] != key) {
            new_arr = (int*) realloc(new_arr, sizeof(int) * (new_size + 1));
            new_arr[new_size] = (*arr)[i];
            new_size++;
        }
    }
    free(*arr);
    *arr = new_arr;
    *size = new_size;
}

void print(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}