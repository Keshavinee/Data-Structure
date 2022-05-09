#include "etree.h"
#define max 50

struct stack
{
    node * list[max];  // creates an array of node pointers
    int top;
};

typedef struct stack stack;

void init(stack *);
int isFull(stack *);
void push(stack *, node *);
int isEmpty(stack *);
void display(stack *);
node * pop(stack *);
void top(stack );
