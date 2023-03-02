#include "reverse.h"
#include "node.h"

Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next;

    while (current != nullptr) {
        next = current->next;    // save the next node
        current->next = prev;   // reverse the link
        prev = current;         // move to the next pair
        current = next;
    }

    return prev;                // return the new head
}

