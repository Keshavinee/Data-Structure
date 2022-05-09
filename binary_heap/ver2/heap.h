#define max 100

struct emp
{
    char id;
    int sal;
};

typedef struct emp emp;

struct priorityQueueADT
{
    emp arr[max];
    int size;
    int rear;
};

typedef struct priorityQueueADT priorityQueueADT;

void init(priorityQueueADT *,int);
void insert(priorityQueueADT *, char, int );
void display(priorityQueueADT *);
emp del(priorityQueueADT *);