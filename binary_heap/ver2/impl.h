#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

void init(priorityQueueADT *p, int size){
    emp e;
    e.id = '-';
    e.sal = 0;

    p->size = size;
    p->rear = 0;
    p->arr[p->rear] = e;
}

void insert(priorityQueueADT *p, char x1, int x2){
    emp e;
    p->rear++;
    p->arr[p->rear].id = x1;
    p->arr[p->rear].sal = x2;

    for (int i = p->rear; i > 0; i=i/2)
    {
        if (p->arr[i].sal < p->arr[i/2].sal )
        {
            e = p->arr[i];
            p->arr[i] = p->arr[i/2];
            p->arr[i/2] = e;
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
        printf("%c %d\n",p->arr[i].id,p->arr[i].sal);
    }
    
}

emp del(priorityQueueADT *p){
    emp e = p->arr[p->rear];
    if (p->rear != 0)
    {
        e = p->arr[1];
        if (p->rear != 1)
        {
            p->arr[1] = p->arr[p->rear];
            
        }
        p->rear--;
    }
    return e;
}