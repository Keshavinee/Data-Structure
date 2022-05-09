#include "implementation.h"

int main(){
    stk *top;
    int c, data;
    top = init(top);

    printf("Stack Operations:\nMenu\n1.Push\n2.Pop\n3.Display\n4.Quit\n");

    option :
        printf("Enter any of the options above: ");
        scanf("%d",&c);

    switch (c)
    {
    case 1:
        printf("Enter data to be pushed onto stack: ");
        scanf("%d",&data);

        top = push(top, data);
        printf("%d is pushed onto stack!\n",data);
        goto option;

    case 2:
        top = pop(top);
        goto option;

    case 3:
        printf("Elements of stack: \n");
        display(top);
        goto option;

    case 4:
        printf("Program ended!\n");
        break;

    default:
        printf("Invalid option!\n");
        goto option;
    }
    return 0;
}
