/*

THIS WAS DONE DURING THE LAB

#include "list.h"
#include "reverse.h"


int main() {
    Node *first, *last;
    first = nullptr;
    last = nullptr;

    createLinkedList(&first, &last);
    printLinkedList(first);
    printf("\n");

    insertFirst(&first, &last, 3);
    printLinkedList(first);
    printf("\n");

    insertLast(&first, &last, 6);
    printLinkedList(first);
    printf("\n");

    insertAfterKey(&first, &last, 1, 4);
    printLinkedList(first);
    printf("\n");

    deleteFirst(&first, &last);
    printLinkedList(first);
    printf("\n");

    deleteLast(&first, &last);
    printLinkedList(first);
    printf("\n");

    deleteKey(&first, &last, 1);
    printLinkedList(first);
    printf("\n");

    return 0;
}

*/

/*
DONE AT HOME

#include <iostream>
#include "vectorList.h"

int main() {
    int capacity, size, choice, key;
    size = 0;

    printf("Enter the capacity of the array: ");
    scanf("%d", &capacity);
    int* arr = (int*)malloc(capacity * sizeof(int));

    // for testing
    arr[0] = 3;
    arr[1] = 2;
    arr[2] = 4;
    arr[3] = 6;
    size = 4;

    print(arr, size);
}
 */
