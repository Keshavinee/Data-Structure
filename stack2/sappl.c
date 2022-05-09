#include "implementation.h"
#include <stdlib.h>

int twoStacks(int, stack, stack);

int main(){
    stack s,s1,s2;
    int c, data, maxsum;

    init(&s); init(&s1); init(&s2);

    printf("Stack Operations:\nMenu\n1.Push\n2.Pop\n3.Display\n\
4.Top element\n5.Is Full?\n6.Is Empty?\n7.Play a Game?\n8.Quit\n");

    option :
        printf("Enter any of the options above: ");
        scanf("%d",&c);

    switch (c)
    {
    case 1:
        printf("Enter data to be pushed onto stack: ");
        scanf("%d",&data);

        push(&s, data);
        printf("%d is pushed onto stack!\n",data);
        goto option;

    case 2:
        pop(&s);
        goto option;

    case 3:
        printf("Elements of stack: \n");

        display(&s);
        goto option;

    case 4:
        top(s);
        goto option;
    
    case 5:
        if (isFull(&s))
        {
            printf("Stack is full!\n");
        }
        else
        {
            printf("Stack is not full!\n");   
        }
        goto option;

    case 6:
        if (isEmpty(&s))
        {
            printf("Stack is empty!\n");
        }
        else
        {
            printf("Stack is not empty!\n");   
        }
        goto option;

    case 7:
        printf("Create first stack:\n No.of elements: ");
        scanf("%d",&c);

        for (int i = 0; i < c; i++)
        {
            printf("Enter data %d: ",i+1);
            scanf("%d",&data);
            push(&s1,data);
        }

        printf("Create second stack:\n No.of elements: ");
        scanf("%d",&c);

        for (int i = 0; i < c; i++)
        {
            printf("Enter data %d: ",i+1);
            scanf("%d",&data);
            push(&s2,data);
        }
        
        printf("Maximum number:");
        scanf("%d",&maxsum);

        printf("No. of moves: %d\n",twoStacks(maxsum,s1,s2));
        goto option;
    case 8:
        printf("Program ended!\n");
        break;

    default:
        printf("Invalid option!\n");
        goto option;
    }
    return 0;
}

int twoStacks(int maxSum, stack s1, stack s2){
    int n=0, m=0;

    while (!(isEmpty(&s1) && isEmpty(&s2)))
    {
        if (m > maxSum)
        {
            return n;
        }
        
        if (isEmpty(&s1))
        {
            m = m + s2.list[s2.top];
            pop(&s2);
        }

        else if (isEmpty(&s2))
        {
            m = m + s1.list[s1.top];
            pop(&s1);
        }

        else
        {
            if (rand()%2==0)
            {
                m = m + s2.list[s2.top];
                pop(&s2);
            }
            else
            {
                m = m + s1.list[s1.top];
                pop(&s1);
            }
            
        }
        n++;
    }
    return n;
}