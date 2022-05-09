#include "impl.h"

int main(){
    int v,e;
    int src,dtn;

    cityADT *c = (cityADT *) malloc(sizeof(cityADT));
    printf("Enter no.of vertices:");
    scanf("%d",&v);
    printf("Enter no.of edges:");
    scanf("%d",&e);

    initvar(c,v,e);
    create(c);
    floydWarshall(c);

    display(c);

    printf("Shortest path between two vertices:\n");
    printf("Source:");
    scanf(" %d",&src);
    printf("Destination:");
    scanf(" %d",&dtn);

    path(c,src,dtn);

}