#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

int main() {
    FILE *f = fopen("ArboreBinar.txt", "r");
    Node *root = createBinTreeFromFile(f);
    fclose(f);
    preorder(root);
    printf("\n");
    printf("%d", height(root));
    return 0;
}