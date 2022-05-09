#include "queue.h"
#include <stdio.h>


void init(queue *q, int size){
    q->front = -1;
    q->rear = -1;
    q->size = size;
}

int isfull(queue *q){
    if (q->rear == (q->size)-1)
    {
        return 1;
    }
    return 0;
}

void enqueue(queue *q, int x){
    if (q->rear == (q->size)-1)
    {
        printf("Overflow!");
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->list[q->rear] = x;
    }
    
}

int isempty(queue *q){
    if (q->front==-1 || q->front > q->rear)
    {
        return 1;
    }
    return 0;   
}

int dequeue(queue *q){
    int x; 

    if (q->front==-1 || q->front > q->rear)
    {
        return x;
    }
    x = q->list[q->front];
    q->front++;
    return x;
}

void qdisplay(queue *q){
    if (q->front==-1 || q->front > q->rear)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        for (int i = q->front; i < q->rear; i++)
        {
            printf("%d ",q->list[i]);
        }
        printf("\n");
    }    
}