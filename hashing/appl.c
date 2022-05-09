#include "impl.h"
#include <stdlib.h>

int main(){
    hashtableADT *h = (hashtableADT *) malloc(sizeof(hashtableADT));
    
    int n,m,x;
    printf("Enter size of array: ");
    scanf("%d",&n);

    init(h,n);

    printf("Enter no.of elements: ");
    scanf("%d",&m);

    printf("Insert ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&x);
        //insertElement(h,x);
        //quadraticProbing(h,x);
        doubleHashing(h,x);
    }
    
    display(h);

    int start,end;

    printf("Range - start: ");
    scanf("%d",&start);

    printf("Range - end: ");
    scanf("%d",&end);

    for (int i = start; i <= end; i++)
    {
        m = searchElement(h,i);

        if (m == 1)
        {
            printf("%d found\n",i);
        }
        
    }
    
    return 0;
}