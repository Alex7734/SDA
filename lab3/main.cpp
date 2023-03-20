#include <iostream>
#include <cstdlib>
#include "stack.h"
#include "queue.h"

int main() {
//    Node* stack;
//    initStack(&stack);
//
//    push(&stack, 1);
//    push(&stack, 2);
//    push(&stack, 3);
//
//    printStack(stack);
//
//    Node* top = pop(&stack);
//    printf("Popped element: %d\n", top->data);
//
//    printStack(stack);

    queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    enqueue(&q, 70);
    enqueue(&q, 80);
    enqueue(&q, 90);

    printQueue(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    enqueue(&q, 110);
    enqueue(&q, 120);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q, 130);
    enqueue(&q, 140);
    enqueue(&q, 150);
    enqueue(&q, 150);
    enqueue(&q, 150);
    enqueue(&q, 150);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    dequeue(&q);

    printQueue(&q);

    return 0;
}

