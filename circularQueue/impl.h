#include "queue.h"
#include <stdio.h>

void init(queue *q, int size){
    q->front = -1;
    q->rear = -1;
    q->size = size;
}

int isfull(queue *q){
    if (q->rear - q->front == (q->size)-1)
    {
        return 1;
    }
    return 0;
}

void enqueue(queue *q, job x){
    if (q->front==-1 && q->rear==-1)
    {
        q->front = 0;
        q->rear = 0;
        q->arr[q->rear] = x;
    }

    else if (isfull(q)==1)
    {
        printf("Queue is full!\n");
    }
    
    else
    {
        q->rear ++;
        q->arr[q->rear%q->size] = x;
    }
}

int isempty(queue *q){
    if (q->front==-1 && q->rear==-1)
    {
        return 1;
    }
    
    else if (q->front-q->rear==1)
    {
        return 1;
    }
    return 0;   
}

job dequeue(queue *q){
    job x; 
    x.n = -1; x.time = -1;

    if (isempty(q)==1)
    {
        printf("Queue is empty!\n");
        return x;
    }
    x = q->arr[q->front % q->size];
    printf("(%d,%d) is dequeued!\n",x.n,x.time);
    q->front++;
    return x;
}

void display(queue q){
    int iter;

    if (isempty(&q)==1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        iter = q.front;
        while (iter <= q.rear)
        {
            printf("(%d,%d)\n",q.arr[iter % q.size].n,q.arr[iter % q.size].time);
            iter++;
        }
    }    
}

//AB BC BD CA CF DE EF
