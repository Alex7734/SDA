#ifndef LAB2_VECTORLIST_H
#define LAB2_VECTORLIST_H

int search(int* arr, int size, int key);
void insertFirst(int** arr, int* size, int* capacity, int key);
void insertLast(int** arr, int* size, int* capacity, int key);
void deleteFirst(int** arr, int* size);
void deleteLast(int** arr, int* size);
void deleteKey(int** arr, int* size, int key);
void print(int* arr, int size);


#endif //LAB2_VECTORLIST_H
