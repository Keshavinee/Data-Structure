#include "impl.h"

int main(){
    queue q;
    job x;
    int size,c;

    printf("Enter size of the queue:");
    scanf("%d", &size);
    init(&q, size);

    printf("Queue Operations:\nMenu\n1.Enqueue\n\
2.Dequeue\n3.Display\n4.Quit\n");

    option :
        printf("Enter any of the options above: ");
        scanf("%d",&c);

    switch (c)
    {
    case 1:
        printf("Job number & CPU burst time:");
        scanf("%d %d", &x.n, &x.time);
        enqueue(&q, x);

        goto option;

    case 2:
        dequeue(&q);
        goto option;

    case 3:
        printf("Elements of queue: \n");
        display(q);
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