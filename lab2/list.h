#ifndef LAB2_LIST_H
#define LAB2_LIST_H

typedef struct nodeType{
    int data;
    struct nodeType *next;
} Node;

void createLinkedList(Node** first, Node** last);
void printLinkedList(Node* head);
void insertFirst(Node** first, Node** last, int givenKey);
void insertLast(Node** first, Node** last, int givenKey);
void insertAfterKey(Node** first, Node** last, int afterKey, int givenKey);
void deleteFirst(Node** first, Node** last);
void deleteLast(Node** first, Node** last);
void deleteKey(Node** first, Node** last, int givenKey);
Node* search(Node* first, int givenKey);

#endif //LAB2_LIST_H
