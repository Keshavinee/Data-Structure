#include "cityADT.h"
#include <stdlib.h>
#include <stdio.h>

void initvar(cityADT *c, int v, int e){
    c->v = v;
    c->e = e;

    c->g = (int **) malloc(v * sizeof(int *));
    c->dist = (int **) malloc(v * sizeof(int *));
    c->pred = (int **) malloc(v * sizeof(int *));
    for (int i = 0; i < v; i++)
    {
        c->g[i] = (int *)malloc(v * sizeof(int));
        c->dist[i] = (int *)malloc(v * sizeof(int));
        c->pred[i] = (int *)malloc(v * sizeof(int));
    }

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            c->g[i][j] = 0;
            c->dist[i][j] = 0;
            c->pred[i][j] = 0;
        }    
    }   
}

void display(cityADT *c){
    for (int i = 0; i < c->v; i++)
    {
        for (int j = 0; j < c->v; j++)
        {
            printf("%d\t",c->g[i][j]);
        }
        printf("\t");
        for (int j = 0; j < c->v; j++)
        {
            printf("%d\t",c->dist[i][j]);
        }
        printf("\t");
        for (int j = 0; j < c->v; j++)
        {
            printf("%d\t",c->pred[i][j]);
        }
        printf("\n");
    }
    
}

void create(cityADT *c){
    int * a[c->e];
    int m,n;
    for (int i = 0; i < c->e; i++)
    {
        a[i] = (int *)malloc(3 * sizeof(int));
        scanf("%d",&a[i][0]);
        scanf("%d",&a[i][1]);
        scanf("%d",&a[i][2]);

        c->g[a[i][0]-1][a[i][1]-1]=1;
        c->dist[a[i][0]-1][a[i][1]-1]=a[i][2];
    } 

    for (int i = 0; i < c->v; i++)
    {
        for (int j = 0; j < c->v; j++)
        {
            if (i!=j && c->g[i][j]==0)
            {
                c->g[i][j] = 999;
            }
            
        }
        
    }
}

void floydWarshall(cityADT *c){
    for (int k = 0; k < c->v; k++)
    {
        for (int i = 0; i < c->v; i++)
        {
            for (int j = 0; j < c->v; j++)
            {
                if (c->dist[i][j] > (c->dist[i][k] + c->dist[k][j]))
                {
                    c->dist[i][j] = c->dist[i][k] + c->dist[k][j];
                    c->pred[i][j] = k;
                }  
            }    
        }    
    }    
}


void path(cityADT *c, int i, int j){
    if (c->pred[i][j] == 0)
    {
        printf("%d ",j);
    }
    
    else
    {
        path(c,i,c->pred[i][j]);
        path(c,c->pred[i][j],j);
    }
    
}