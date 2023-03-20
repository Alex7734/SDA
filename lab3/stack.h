#ifndef LAB3_STACK_H
#define LAB3_STACK_H

typedef struct node {
    int data;
    struct node* next;
} Node;

void initStack(Node**);
void printStack(Node*);
void push(Node**, int);
Node* pop(Node**);

#endif //LAB3_STACK_H
