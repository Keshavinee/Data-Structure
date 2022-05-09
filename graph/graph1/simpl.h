#include <stdio.h>
#include "stack.h"

void sinit(stack *stk){
    stk->top = -1;
}

int isFull(stack *stk){
    if (stk->top == max)
    {
        return 1;
    }
    return 0;
}

void push(stack *stk, int data){
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

int top(stack *stk){
    if (stk->top == -1)
    {
        return -1;
    }
    else
    {
        return stk->list[stk->top];
    }
}

int isEmpty(stack *stk){
    if (stk->top == -1)
    {
        return 1;
    }
    return 0;
}

void sdisplay(stack *stk){
    if (isEmpty(stk))
    {
        printf("Stack is empty!\n");
    }
    else
    {
        for (int i = stk->top; i != -1; i--)
        {
            printf("%d\n",stk->list[i]);
        }
    }    
}

int pop(stack *stk){
    int d;
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

