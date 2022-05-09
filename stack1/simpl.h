#include <stdio.h>
#include "stack.h"

void init(stack *stk){
    stk->top = -1;
}

int isFull(stack *stk){
    if (stk->top == max)
    {
        return 1;
    }
    return 0;
}

void push(stack *stk, node *data){
    stk->top ++;

    if (isFull(stk))
    {
        printf("Stack is full!\n");
    }

    else
    {
        stk->list[stk->top] = data;
    }
}

void top(stack stk){
    if (stk.top == -1)
    {
        printf("Stack is empty!");
    }
    else
    {
        printf("Top of the element: %p\n",stk.list[stk.top]);
    }
}

int isEmpty(stack *stk){
    if (stk->top == -1)
    {
        return 1;
    }
    return 0;
}

void display(stack *stk){
    if (isEmpty(stk))
    {
        printf("Stack is empty!\n");
    }
    else
    {
        for (int i = stk->top; i != -1; i--)
        {
            printf("%p\n",stk->list[i]);
        }
    }    
}

node * pop(stack *stk){
    node *d;
    if (isEmpty(stk))
    {
        printf("Stack is empty! Nothing there to pop from the stack!\n");
    }
    else
    {
        d = stk->list[stk->top];
        //printf("%p is popped from the stack!\n",stk->list[stk->top]);
        stk->top--;
        return d;
    }
    
}

