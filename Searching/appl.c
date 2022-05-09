#include "impl.h"

int main(){
    int size;
    printf("Enter no.of elements: ");
    scanf("%d",&size);
    
    int arr[size];
    numberADT *n = (numberADT *) malloc(sizeof(numberADT));
    numberADT *m = (numberADT *) malloc(sizeof(numberADT));

    printf("Enter elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    /*int size2;
    printf("Enter no.of elements for second array: ");
    scanf("%d",&size2);
    
    int arr2[size2];
    printf("Enter elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr2[i]);
    }*/

    init(n, size);
    insertElements(n, arr);
    
    /*init(m, size2);
    insertElements(m, arr2);

    printf("Second occurrence of element 7:");
    printf("%d\n",secondocc(n,7));

    printf("Frequency of element 7:");
    printf("%d\n",freq(n,7));

    printf("Find whether the two list of distinct elements are same\n");
    display(m);
    display(n);
    identical(m,n);*/

    printf("Retrieve the pair of elements from the list whose difference is some 18\n");
    pair(n,18);
    return 0;
}