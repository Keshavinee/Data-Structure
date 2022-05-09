#include "queue.h"
#include <stdio.h>

void init(queue *q){
    q->front = -1;
    q->rear = -1;
    //q->size = 0;
}

int isfull(queue *q){
    if (q->rear < max)
    {
        return 0;
    }
    return 1;
}

int isempty(queue *q){
    if (q->rear == -1)
    {
        return 1;
    }
    return 0;
}

void enqueue(queue *q, int data){
    if (q->front == -1)
    {
        q->front = 0;
    }
    
    q->rear++;

    if (! isfull(q))
    {
        q->list[q->rear] = data; 
    }
    else
    {
        printf("Overflow!\n");
    }
}

void dequeue(queue *q){
    q->rear--;

    if (! isempty(q))
    {
        q->list[q->rear] = data; 
    }
    else
    {
        printf("Underflow!\n");
    }
}