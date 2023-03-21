#ifndef LAB4_BINARYTREE_H
#define LAB4_BINARYTREE_H
#include "stdio.h"

typedef struct node_type {
    int id;
    struct node_type *left, *right;
} Node;

Node *createBinTreeFromFile(FILE *);
void preorder(Node *node);
void inorder(Node *node);
void postorder(Node *node);
int leafNode(Node *node);
void displayLeafNodes(Node *node);
int internalNodes(Node *node);
int height(Node* node);
Node* search(Node *root, int key);

#endif //LAB4_BINARYTREE_H
