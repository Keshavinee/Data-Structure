#include "hashtable.h"
#include <stdio.h>

void init(hashtableADT *h,int size){
    h->size = size;
    for (int i = 0; i < size; i++)
    {
        h->arr[i] = 0;
    }   
}

void insertElement(hashtableADT *h, int x){
    int pos = x % h->size;
    int i = 0;

    while (i<h->size)
    {
        if (h->arr[pos] != 0)
        {
            pos = (pos + 1) % h->size;
            i++;
        }
        else
        {
            h->arr[pos] = x;
            break;
        }
        
    }
}

int searchElement(hashtableADT *h, int key){
    int pos = key % h->size;
    int i = 0;

    while (i<h->size)
    {
        if (h->arr[pos] != key)
        {
            pos = (pos + 1) % h->size;
            i++;
        }
        else
        {
            return 1;
        }
        
    }
    return -1;
}

void display(hashtableADT *h){
    for (int i = 0; i < h->size; i++)
    {
        printf("%d ",h->arr[i]);
    }
    printf("\n");
}

void quadraticProbing(hashtableADT *h, int x){
    int pos = x % h->size;
    int i = 1,j = pos;

    while (i<=h->size)
    {
        if (h->arr[j] != 0)
        {
            j = (pos + i*i) % h->size;
            i++;
        }
        else
        {
            h->arr[j] = x;
            break;
        }
        
    }
}

void doubleHashing(hashtableADT *h, int x){
    int pos1 = x % h->size;
    int pos2 = 7 - (x % 7);
    int i = 1,j = pos1;

    while (i<=h->size)
    {
        if (h->arr[j] != 0)
        {
            j = (pos1 + i*pos2) % h->size;
            i++;
        }
        else
        {
            h->arr[j] = x;
            break;
        }
        
    }
}