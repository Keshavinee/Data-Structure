#define max 100

struct priorityQueueADT
{
    int arr[max];
    int size;
    int rear;
};

typedef struct priorityQueueADT priorityQueueADT;

void init(priorityQueueADT *,int);
void insert(priorityQueueADT *, int );
void display(priorityQueueADT *);
int del(priorityQueueADT *);
