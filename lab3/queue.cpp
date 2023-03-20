#include <iostream>
#include <cstdlib>
#include "queue.h"

void initQueue(queue *q) {
    q->size = 0;
    q->head = 0;
    q->tail = 0;
}

void enqueue(queue *q, int key) {
    if (q->size >= CAPACITY){
        printf("Queue is full!\n");
        return;
    }

    q->vec[q->tail] = key;
    q->tail = (q->tail + 1) % CAPACITY;
    q->size++;
}

int dequeue(queue *q){
    if (q->size == 0){
        printf("Queue is empty!\n");
        return -1;
    }

    int element = q->vec[q->head];
    q->head = (q->head + 1) % CAPACITY;
    (q->size)--;
    return element;
}

void printQueue(queue *q) {
    printf("Queue: ");
    for (int i = q->head; i != q->tail; i = (i + 1) % CAPACITY) {
        printf("%d ", q->vec[i]);
    }
    printf("\n");
}
