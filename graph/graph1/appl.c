#include "impl.h"

int main(){
    int v,e;
    char src,dtn;
    cityADT *c = (cityADT *) malloc(sizeof(cityADT));
    printf("Enter no.of vertices:");
    scanf("%d",&v);
    printf("Enter no.of edges:");
    scanf("%d",&e);
    initvar(c,v,e);
    create(c);
    display(c);

    BFS(c);
    DFS(c);

    printf("Application 1:\n");
    printf("Source:");
    scanf(" %c",&src);
    printf("Destination:");
    scanf(" %c",&dtn);

    path(c,src,dtn);

    printf("Application 2:\n");
    cityADT *d = (cityADT *) malloc(sizeof(cityADT));
    printf("Enter no.of vertices:");
    scanf("%d",&v);
    printf("Enter no.of edges:");
    scanf("%d",&e);
    initvar(d,v,e);
    create(d);
    display(d);

    connected_graphs(d);

}