#include "doubleLinkedLists.h"
#include <cstdlib>
#include <iostream>

// Function to create a new node
Node* createNode(int givenKey) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->key = givenKey;
    new_node->prev = nullptr;
    new_node->next = nullptr;
    return new_node;
}

// Function to insert a node at the beginning of the list
void insertFirst(listHeader *L, int givenKey) {
    Node *new_node = createNode(givenKey);
    if(L->first == nullptr) {
        L->first = new_node;
        L->last = new_node;
    }
    else {
        new_node->next = L->first;
        L->first->prev = new_node;
        L->first = new_node;
    }
}

// Function to insert a node at the end of the list
void insertLast(listHeader *L, int givenKey) {
    Node *new_node = createNode(givenKey);
    if(L->last == nullptr) {
        L->first = new_node;
        L->last = new_node;
    }
    else {
        new_node->prev = L->last;
        L->last->next = new_node;
        L->last = new_node;
    }
}

// Function to insert a node after a given key
void insertAfterKey(listHeader *L, int afterKey, int givenKey) {
    Node *new_node = createNode(givenKey);
    Node *current = L->first;
    while(current != nullptr && current->key != afterKey) {
        current = current->next;
    }
    if(current == nullptr) {
        printf("Key not found in the list.\n");
        return;
    }
    if(current == L->last) {
        L->last = new_node;
    }
    new_node->prev = current;
    new_node->next = current->next;
    if(current->next != nullptr) {
        current->next->prev = new_node;
    }
    current->next = new_node;
}

// Function to print the list from the beginning
void printForward(listHeader *L) {
    Node *current = L->first;
    while(current != nullptr) {
        printf("%d ", current->key);
        current = current->next;
    }
    printf("\n");
}

// Function to print the list in reverse order
void printBackward(listHeader *L) {
    Node *current = L->last;
    while(current != nullptr) {
        printf("%d ", current->key);
        current = current->prev;
    }
    printf("\n");
}

// Function to search for a node with a given key
Node* search(listHeader *L, int givenKey) {
    Node *current = L->first;
    while(current != nullptr && current->key != givenKey) {
        current = current->next;
    }
    return current;
}

// Function to delete the first node
void delete_first(listHeader *L) {
    if(L->first == nullptr) {
        printf("List is empty.\n");
        return;
    }
    if(L->first == L->last) {
        free(L->first);
        L->first = nullptr;
        L->last = nullptr;
    }
    else {
        Node *temp = L->first;
        L->first = L->first->next;
        L->first->prev = nullptr;
        free(temp);
    }
}

// Function to delete the last node
void deleteLast(listHeader *L) {
    if(L->last == nullptr) {
        printf("List is empty.\n");
        return;
    }
    if(L->first == L->last) {
        free(L->last);
        L->first = nullptr;
        L->last = nullptr;
    }
    else {
        Node *temp = L->last;
        L->last = L->last->prev;
        L->last->next = nullptr;
        free(temp);
    }
}
