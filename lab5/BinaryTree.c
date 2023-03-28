#include "BinaryTree.h"
#include "stdio.h"
#include "stdlib.h"
#define MAX(x, y) ((x) > (y)) ? (x) : (y)
#define MIN(x, y) ((x) > (y)) ? (y) : (x)

Node* insertNode(Node* root, int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    // Adding the root node
    if (root == NULL) {
        return newNode;
    }

    Node* curr = root;
    while (1) {
        if (key < curr->id) {
            if (curr->left == NULL) {
                newNode->parent = curr;
                curr->left = newNode;
                return newNode;
            } else {
                curr = curr->left;
            }
        } else if (curr->right == NULL) {
            newNode->parent = curr;
            curr->right = newNode;
            return newNode;
        } else {
            curr = curr->right;
        }
    }

    return root;
}

Node* findMin(Node* node) {
    if (node == NULL) {
        return NULL;
    }

    while (node->left != NULL) {
        node = node->left;
    }

    return node;
}

Node* findMax(Node* node) {
    if (node == NULL) {
        return NULL;
    }

    while (node->right != NULL){
        node = node->right;
    }

    return node;
}

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

Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->id) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->id) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        } else {
            Node* successor = findMin(root->right);
            root->id = successor->id;
            root->right = deleteNode(root->right, successor->id);
        }
    }

    return root;
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

// Numarul de muchii
int treeDiameter(Node* node){
    if (node == NULL){
        return 0;
    }

    int hLeft = height(node->left);
    int hRight = height(node->right);

    int dLeft = treeDiameter(node->left);
    int dRight = treeDiameter(node->right);

    return MAX(hLeft + hRight +1, MAX(dLeft, dRight));
}

Node* predecessor(Node* node) {
    if (node == NULL) {
        return NULL;
    }

    if (node->left != NULL) {
        return findMax(node->left);

    } else {
        Node* parent = node->parent;
        while (parent != NULL && node == parent->left) {
            node = parent;
            parent = parent->parent;
        }
        return parent;
    }
}

Node* succesor(Node* node) {
    if (node == NULL) {
        return NULL;
    }

    if (node->right != NULL) {
        return findMin(node->right);
    } else {
        Node* parent = node->parent;
        while (parent != NULL && node == parent->right) {
            node = parent;
            parent = parent->parent;
        }
        return parent;
    }
}

Node* searchKey(Node* root, int key) {
    Node* current = root;

    while (current != NULL) {
        if (current->id == key) {
            break;
        } else {
            if (key < current->id) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
    }

    return current;
}