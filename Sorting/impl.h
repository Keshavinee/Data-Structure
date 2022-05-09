#include "sort.h"
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

void display(numberADT *n){
    for (int i = 0; i < n->size; i++)
    {
        printf("%d ",n->arr[i]);
    }
    printf("\n");   
}

void selSort(numberADT *n){
    int pos,min;
    for (int i = 0; i < n->size - 1; i++)
    {
        min = n->arr[i];
        pos = i;
        for (int j = i+1; j < n->size; j++)       {
            if (n->arr[j] < min)
            {
                min = n->arr[j];
                pos = j;
            }   
        }
        n->arr[pos] = n->arr[i];
        n->arr[i] = min;
    }   
}

void shellSort(numberADT *n){
    int temp, j;
    
    for (int gap = n->size/2; gap > 0; gap=gap/2)
    {
        for (int i = gap; i < n->size; i++)
        {
            temp = n->arr[i];
            for (j = i; j >= gap && n->arr[j-gap]>temp; j=j-gap)
            {
                n->arr[j] = n->arr[j-gap];
            }
            n->arr[j] = temp;
        }
        
    }
    
}

