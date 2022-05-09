#include "impl.h"

void app(queue);

int main()
{
    queue q;
    job x;
    int size;
    printf("Enter size of the queue:");
    scanf("%d", &size);
    init(&q, size);

    for (int i = 0; i < q.size; i++)
    {
        printf("Job number & CPU burst time:");
        scanf("%d %d", &x.n, &x.time);
        enqueue(&q, x);
    }

    app(q);

    return 0;
}

void app(queue q)
{
    queue q1, q2;
    int s1 = 0, s2 = 0;
    init(&q1, q.size);
    init(&q2, q.size);

    for (int i = 0; i < q.size; i++)
    {
        if (isempty(&q1) == 1)
        {
            s1 = s1 + q.arr[i].time;
            enqueue(&q1,q.arr[i]);
        }

        else if (isempty(&q2) == 1)
        {
            s2 = s2 + q.arr[i].time;
            enqueue(&q2,q.arr[i]);
        }
        
        else
        {
            if (s1 > s2)
            {
                s2 = s2 + q.arr[i].time;
                enqueue(&q2,q.arr[i]);
            }
            else
            {
                s1 = s1 + q.arr[i].time;
                enqueue(&q1,q.arr[i]);
            }
            
        }
        
    }
    printf("Queue 1:\n");
    display(q1);
    printf("Queue 2:\n");
    display(q2);
}