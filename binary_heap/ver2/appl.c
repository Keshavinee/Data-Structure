#include "impl.h"

int main()
{
    priorityQueueADT *p = (priorityQueueADT *)malloc(sizeof(priorityQueueADT));

    insert(p, 'A', 15000);
    insert(p, 'K', 12000);
    insert(p, 'R', 4000);
    insert(p, 'T', 3500);
    insert(p, 'L', 4600);
    insert(p, 'P', 6000);
    insert(p, 'Y', 8600);

    display(p);
    return 0;
}