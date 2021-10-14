#ifndef QUEUE_H_
#define QUEUE_H_
typedef struct Queue {
    int *items;
    int size;
    int front;
    int rear;
} queue;
queue *createQueue();
void resize(queue *q);
int dequeue(queue *q);
int isEmpty(queue *q);
void checkForResize(queue *q);
void enqueue(queue *q, int value);
void display(queue *q);
void printQueue(queue *q);
#endif