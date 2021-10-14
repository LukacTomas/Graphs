#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#define Q_SIZE 860000

queue *createQueue()
{
    queue *q = (queue *)malloc(sizeof(queue *));
    q->size = Q_SIZE;
    q->items = malloc(sizeof(q->items) * q->size);
    q->front = -1;
    q->rear = -1;
    return q;
}
void resize(queue *q)
{
    q->size = q->size * 2;
    q->items = realloc(q->items, sizeof(q->items) * q->size);
    printf("Resizing to size: %i\n", q->size);
}
int dequeue(queue *q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            printf("Resetting queue\n");
            q->front = q->rear = -1;
        }
    }
    return item;
}

int isEmpty(queue *q)
{
    if (q->rear == -1)
        return 1;
    else
        return 0;
}
void checkForResize(queue *q)
{
}
void enqueue(queue *q, int value)
{
    // TODO remake for automatic rezise
    if (q->rear == q->size - 1)
    {
       
        resize(q);
    }

    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}
void display(queue *q) {}
void printQueue(queue *q)
{
    int i = q->front;

    if (isEmpty(q))
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Queue contains ");
        for (i = q->front; i < q->rear + 1; i++)
        {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}