#include "impl.h"

int main(){
    int size;
    printf("Enter no.of elements: ");
    scanf("%d",&size);

    int arr[size];
    numberADT *n = (numberADT *) malloc(sizeof(numberADT));

    printf("Enter elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    init(n, size);
    insertElements(n, arr);

    shellSort(n);
    display(n);
    return 0;
}