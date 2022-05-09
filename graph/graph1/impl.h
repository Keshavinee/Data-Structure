#include "cityADT.h"
#include "limpl.h"
#include "qimpl.h"
#include "simpl.h"

void initvar(cityADT *c, int v, int e){
    c->v = v;
    c->e = e;

    c->g = (int **) malloc(v * sizeof(int *));
    for (int i = 0; i < v; i++)
    {
        c->g[i] = (int *)malloc(v * sizeof(int));
    }

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            c->g[i][j] = 0;
        }
        
    }
    
}

void create(cityADT *c){
    char * arr[c->e];
    int m,n;
    for (int i = 0; i < c->e; i++)
    {
        arr[i] = (char *)malloc(2 * sizeof(char));
        scanf("%s",arr[i]);

        m = (int) arr[i][0];
        n = (int) arr[i][1];

        c->g[m%65][n%65]=1;
        //c->g[n%65][m%65]=1;
    }
    
}

void display(cityADT *c){
    for (int i = 0; i < c->v; i++)
    {
        for (int j = 0; j < c->v; j++)
        {
            printf("%d ",c->g[i][j]);
        }
        printf("\n");
    }
    
}

void BFS(cityADT *c){
    queue *q = (queue *) malloc(sizeof(queue));
    init(q,c->v);
    int z;

    node *h = (node *) malloc(sizeof(node));
    h = initialize(h);

    for (int i = 0; i < c->v; i++)
    {
        h = insertEnd(h,i);
    }
    
    printf("BFS :");
    while (h != NULL)
    {
        enqueue(q,h->data);
        h = deleteItem(h,h->data);
        
        while (isempty(q) != 1)
        {
            z = dequeue(q);
            printf("%c ",(char) z+65);

            for (int y = 0; y < c->v; y++)
            {
                if (c->g[z][y] == 1)
                {
                    if (searchItem(h,y)==1)
                    {
                        enqueue(q,y);
                        h = deleteItem(h,y);
                    }
                }    
            }    
        }    
    }
    printf("\n");
}

void DFS(cityADT *c){
    stack *s = (stack *)malloc(sizeof(stack));
    sinit(s);
    int t,f;

    node *h = (node *) malloc(sizeof(node));
    h = initialize(h);

    for (int i = 0; i < c->v; i++)
    {
        h = insertEnd(h,i);
    }
    
    printf("DFS :");
    while (h != NULL)
    {
        push(s,h->data);
        printf("%c ",(char) h->data +65);
        h = deleteItem(h,h->data);

        while (isEmpty(s) != 1)
        {
            t = top(s);

            f=0;
            for (int y = 0; y < c->v; y++)
            {
                if (c->g[t][y] == 1)
                {
                    if (searchItem(h,y)==1)
                    {
                        push(s,y);
                        h = deleteItem(h,y);
                        printf("%c ",(char) y+65);
                        f=1;
                        break;
                    }
                }    
            } 
            if (f==0)
            {
                pop(s);
            }
               
        }    
    }
    printf("\n");

}

void path(cityADT *c, char src, char dtn){
    stack *s = (stack *)malloc(sizeof(stack));
    sinit(s);
    int t,f1,f2,m,n;

    m = (int) src;
    n = (int) dtn;

    node *h = (node *) malloc(sizeof(node));
    h = initialize(h);

    for (int i = 0; i < c->v; i++)
    {
        h = insertEnd(h,i);
    }
    
    push(s,m%65);
    h = deleteItem(h,m%65);
    
    f2=0;
    while (isEmpty(s) != 1)
    {
        t = top(s);

        f1=0;
        for (int y = 0; y < c->v; y++)
        {
            if (c->g[t][y] == 1)
            {
                if (y == (n%65))
                {
                    printf("Path exists\n");
                    f2 = 1;
                    break;
                }
                
                if (searchItem(h,y)==1)
                {
                    push(s,y);
                    h = deleteItem(h,y);
                    f1=1;
                    break;
                }
            }    
        }
        if (f2==1)
        {
            break;
        }
         
        if (f1==0)
        {
            pop(s);
        }           
    }  
    if (f2==0)
    {
        printf("Path not exists\n");
    }
      
}

void connected_graphs(cityADT *c){
    queue *q = (queue *) malloc(sizeof(queue));
    init(q,c->v);
    int z,count = 0;

    node *h = (node *) malloc(sizeof(node));
    h = initialize(h);

    for (int i = 0; i < c->v; i++)
    {
        h = insertEnd(h,i);
    }
    
    while (h != NULL)
    {
        enqueue(q,h->data);
        h = deleteItem(h,h->data);
        
        while (isempty(q) != 1)
        {
            z = dequeue(q);
            printf("%c ",(char) z+65);

            for (int y = 0; y < c->v; y++)
            {
                if (c->g[z][y] == 1)
                {
                    if (searchItem(h,y)==1)
                    {
                        enqueue(q,y);
                        h = deleteItem(h,y);
                    }
                }    
            }    
        }  
        count++;
        printf("\n");
    }
    printf("There are %d connected components in a graph.\n",count);
}