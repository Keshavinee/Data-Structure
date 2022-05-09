#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

stk * init(stk *top){
    top = NULL;
    return top;
}

stk * push(stk *top, int data){
    stk *newNode = (stack *) malloc(sizeof(stack));
    newNode->data = data;
    newNode->next = top;

    top = newNode;
    return top;
}

int isEmpty(stk *top){
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

stk * pop(stk *top){
    stk *temp;;
    if (isEmpty(top))
    {
        printf("Stack is empty! Nothing there to pop from the stack!\n");
    }
    else
    {
        temp = top;
        printf("%d is popped from the stack!\n",temp->data);
        top = temp->next;
    }
    return top;
}

void display(stk *top){
    stk *temp;

    if (isEmpty(top))
    {
        printf("Stack is empty!\n");
    }
    else
    {
        temp = top;
        
        while (temp->next != NULL)
        {
            printf("%d\n",temp->data);
            temp = temp->next;
        }
        printf("%d\n",temp->data);
    }    
}