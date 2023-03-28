#include <stdio.h>
#include <malloc.h>
#include "BinaryTree.h"

int main() {
    Node* Root = insertNode(NULL, 5);
    insertNode(Root,3);
    insertNode(Root,7);
    insertNode(Root,1);
    Node* node = insertNode(Root,4);
    insertNode(Root,6);
    insertNode(Root,9);
    insertNode(Root,2);
    insertNode(Root,8);
    inorder(Root);
    printf("\nMax:%d Min:%d\n", findMax(Root)->id, findMin(Root)->id);
    printf("Successor is %d\n", succesor(node)->id);
    printf("Predecessor is %d", predecessor(node)->id);
    return 0;
}

