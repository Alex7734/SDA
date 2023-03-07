#include "list.h"
#include <iostream>

Node* createNode(int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = nullptr;
    return new_node;
}

void createLinkedList(Node** first, Node** last) {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &(new_node->data));
        new_node->next = nullptr;

        if (*first == nullptr) {
            *first = new_node;
            *last = new_node;
        } else {
            (*last)->next = new_node;
            *last = new_node;
        }
    }
}

void printLinkedList(Node* head) {
    for (Node* current = head; current != nullptr; current=current->next){
        printf("%d ", current->data);
    }
}

Node* search(Node* first, int givenKey) {
    printf("\n");
    Node* searcher = first;
    while (searcher != nullptr){
        if (searcher->data == givenKey){
            printf("found %d at %X", givenKey, searcher);
            return searcher;
        }
        else searcher = searcher->next;
    }
    return nullptr;
}

void insertFirst(Node** first, Node** last, int givenKey){
    Node* newNode = createNode(givenKey);
    if (*first != nullptr){
        newNode->next = *first;
        *first = newNode;
    }
}

void insertLast(Node** first, Node** last, int givenKey){
    Node* newNode = createNode(givenKey);
    if (*last != nullptr){
        (*last)->next = newNode;
        *last = newNode;
    }
}


void insertAfterKey(Node** first, Node** last, int afterKey, int givenKey) {
    Node* current = *first;
    while (current != nullptr) {
        if (current->data == afterKey) {
            Node* new_node = createNode(givenKey);
            new_node->next = current->next;
            current->next = new_node;
            if (new_node->next == nullptr) {
                *last = new_node;
            }
            return;
        }
        current = current->next;
    }
    printf("Error: key not found.\n");
}

void deleteFirst(Node** first, Node** last){
    Node *p;
    if ( *first != nullptr ){
        p = *first;
        *first = (*first)->next;
        free( p );
        if ( *first == nullptr )
            *last = nullptr;
    }
}

void deleteLast(Node** first, Node** last){
    Node *q, *q1;
    q1 = nullptr;
    q = *first;

    if ( q != nullptr ){
        while ( q != *last ){
            q1 = q;
            q = q->next;
        }
        if ( q == *first ){
            *first = *last = nullptr;
        }
        else{
            q1->next = nullptr;
            *last = q1;
        }
        free(q);
    }
}

void deleteKey(Node** first, Node** last, int givenKey){
    Node *q, *q1;
    q1 = nullptr;
    q = *first;

    while ( q != nullptr ){
        if ( q->data == givenKey )
            break;
        q1 = q;
        q = q->next;
    }
    if ( q != nullptr ){
        if ( q == *first ){
            *first = (*first)->next;
            free( q );
            if ( *first == nullptr )
                *last = nullptr;
        }
        else{
            q1->next = q->next;
            if (q == *last)
                *last = q1;
            free(q);
        }
    }
}