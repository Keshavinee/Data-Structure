#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

void init(priorityQueueADT *p, int size){
    p->size = size;
    p->rear = 0;
    p->arr[p->rear] = -1;
}

void insert(priorityQueueADT *p, int x){
    int m;
    p->rear++;
    p->arr[p->rear] = x;

    for (int i = p->rear; i > 0; i=i/2)
    {
        if (p->arr[i] < p->arr[i/2] )
        {
            m = p->arr[i];
            p->arr[i] = p->arr[i/2];
            p->arr[i/2] = m;
        }
        
        else
        {
            break;
        }
        
    }   
}

void display(priorityQueueADT *p){
    for (int i = 1; i <= p->rear; i++)
    {
        printf("%d ",p->arr[i]);
    }
    
}

int del(priorityQueueADT *p){
    int d = -1;
    if (p->rear != 0)
    {
        d = p->arr[1];
        if (p->rear != 1)
        {
            p->arr[1] = p->arr[p->rear];
            
        }
        p->rear--;
    }
    return d;
}