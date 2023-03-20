#include <cstdlib>
#include <iostream>
#include "stack.h"


// Initializes Stack
void initStack(Node** stack) {
    *stack = nullptr;
}

// Pushes the node on top
void push(Node** stack, int key) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = key;
    newNode->next = *stack;

    *stack = newNode;
}

// Deletes the top node and returns it
Node* pop(Node** stack) {
    if (*stack == nullptr) {
        return nullptr;
    }

    Node* top = *stack;
    *stack = top->next;
    return top;
}

// Prints Stack and new line
void printStack(Node* stack) {
    if (stack == nullptr) {
        printf("Stack is empty\n");
        return;
    }

    Node* current = stack;
    while (current != nullptr) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}