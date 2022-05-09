#include "search.h"
#include <stdlib.h>
#include <stdio.h>

void init(numberADT *n, int size){
    n->size = size;
}

void insertElements(numberADT *n, int x[]){
    for (int i = 0; i < n->size; i++)
    {
        n->arr[i] = x[i];
    }   
}

int lsearchElement(numberADT *n, int key){
    for (int i = 0; i < n->size; i++)
    {
        if (n->arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int bsearchElement(numberADT *n, int key){
    int mid;
    int low = 0;
    int high = n->size - 1;

    while (low <= high)
    {
        mid = (low + high)/2;

        if (n->arr[mid]==key)
        {
            return mid;
        }
        else if (n->arr[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }    
    }
    return -1;
}

void display(numberADT *n){
    for (int i = 0; i < n->size; i++)
    {
        printf("%d ",n->arr[i]);
    }
    printf("\n");   
}

int secondocc(numberADT *n,int key){
    int j = 0;
    for (int i = 0; i < n->size; i++)
    {
        if (n->arr[i] == key)
        {
            if (j > 0)
            {
                return i+1;
            }
            j++;
        }
    }
    return -1;
}

int freq(numberADT *n,int key){
    int c = 0;
    for (int i = 0; i < n->size; i++)
    {
        if (n->arr[i] == key)
        {
            c++;
        }
    }
    return c;
}

void identical(numberADT *a, numberADT *b){
    int f=1;
    if (a->size == b->size)
    {
        for (int i = 0; i < a->size; i++)
        {
            if (lsearchElement(a,b->arr[i])==-1)
            {
                printf("Different\n");
                f=0;
                break;
            }   
        }  
        if (f==1)
        {
            printf("Same\n");
        }
          
    }
    else
    {
        printf("Different\n");
    }
    
}

void pair(numberADT *n, int d){
    for (int i = 0; i < n->size; i++)
    {
        for (int j = i; j < n->size; j++)
        {
            if (n->arr[i]-n->arr[j] == d | n->arr[i]-n->arr[j] == -d)
            {
                printf("%d %d\n",n->arr[i],n->arr[j]);
            }   
        }  
    }   
}