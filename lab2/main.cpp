#include <iostream>
#include <cstdint>
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
