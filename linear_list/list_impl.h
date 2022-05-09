#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

//typedef struct node node;

void insert(struct node *head, int value){
    struct node *newNode, *temp;

    //printf("Enter data for new node: ");
    //scanf("%d",&(new->data));

    newNode->data = 10;
    printf("%p",temp);
    //temp = head->next;
    printf("%p",temp);
    while (temp != NULL)
    {
        //printf("%p",temp);
        if (temp->data != value)
        {
            temp = temp->next;
            //printf("%p",temp);
        }
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void display(struct node *head)
{
    struct node *temp;
    temp = head->next;

    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
}
int main()
{
    struct node head,t;

    /*t.data = 5;
    t.next = NULL;*/
    head.next = NULL;
    
    insert(&head,5);
    //display(&head);

    return 0;
}