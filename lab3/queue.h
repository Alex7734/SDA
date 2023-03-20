#ifndef LAB3_QUEUE_H
#define LAB3_QUEUE_H
#define CAPACITY 10

typedef struct queue
{
    int vec[CAPACITY]; // the queue itself
    int size; // the current size
    int head, tail; // these will be the indices of the head and tail
} queue;

void initQueue(queue*);
void enqueue(queue* , int); // adds element in queue
int dequeue(queue*); // returns the dequeued element and removes it from the queue
void printQueue(queue*);

#endif //LAB3_QUEUE_H
