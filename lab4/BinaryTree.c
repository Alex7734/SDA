#include "BinaryTree.h"
#include "stdio.h"
#include "stdlib.h"

Node *createBinTreeFromFile(FILE *f) {
    int id;
    fscanf(f, "%d", &id);
    if (id == 0) {
        return NULL;
    }
    Node *node = (Node *)malloc(sizeof(Node));
    node->id = id;
    node->left = createBinTreeFromFile(f);
    node->right = createBinTreeFromFile(f);
    return node;
}

void preorder(Node *node) {
    if (node == NULL) {
        printf("0 ");
        return;
    }
    printf("%d ", node->id);
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node *node) {
    if (node == NULL) {
        printf("0 ");
        return;
    }
    inorder(node->left);
    printf("%d ", node->id);
    inorder(node->right);
}

void postorder(Node *node) {
    if (node == NULL) {
        printf("0 ");
        return;
    }
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->id);
}

int leafNode(Node *node) {
    if (node == NULL) {
        return 0;
    }
    if (node->left == NULL && node->right == NULL) {
        return 1;
    } else {
        return leafNode(node->left) + leafNode(node->right);
    }
}

void displayLeafNodes(Node *node) {
    if (node != NULL) {
        if (node->left == NULL && node->right == NULL) {
            printf("%d ", node->id);
        } else {
            displayLeafNodes(node->left);
            displayLeafNodes(node->right);
        }
    }
}

int countNodes(Node *root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int internalNodes(Node *node){
    return countNodes(node) - leafNode(node);
}

int height(Node *root) {
    if (root == NULL)
        return -1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

Node* search(Node *root, int key) {
    if (root == NULL || root->id == key) {
        return root;
    }
    Node *leftResult = search(root->left, key);
    if (leftResult != NULL) {
        return leftResult;
    }
    return search(root->right, key);
}