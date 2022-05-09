#define max 200

struct job
{
    int n,time;
};
typedef struct job job;

struct queue
{
    job arr[max];
    int front,rear,size;
};

typedef struct queue queue;

void init(queue *, int);
void enqueue(queue *, job );
int isfull(queue *);
int isempty(queue *);
job dequeue(queue *);
void display(queue );