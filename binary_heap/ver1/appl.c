#include "impl.h"

int main()
{
    priorityQueueADT *p = (priorityQueueADT *)malloc(sizeof(priorityQueueADT));

    insert(p, 14);
    insert(p, 16);
    insert(p, 22);
    insert(p, 11);
    insert(p, 9);
    insert(p, 18);
    insert(p, 10);
    insert(p, 7);
    insert(p, 4);
    insert(p, 1);
    
    display(p);
    return 0;
}