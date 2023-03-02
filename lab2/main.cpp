#include <iostream>
#include <cstdint>
#include "node.h"
#include "reverse.h"

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
    Node* current = head;
    printf("Linked List: ");
    while (current != nullptr) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node *first, *last;
    first = nullptr;
    last = nullptr;

    createLinkedList(&first, &last);
    printLinkedList(first);

    printf("\n");

    Node* reversed = reverseLinkedList(first);
    printLinkedList(reversed);

    return 0;
}
